#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "snarf.h"

int opterr;
int optopt;
int optind;
char *optarg;
FILE *ofp;
char *url_to_snarf;
char *output_file = NULL;
int q_flag = 0;
int out_put_flag = 0;





void
parse_args(int argc, char *argv[],char*keyword[])
{


  int i;
  char option;

  for (i = 0; optind < argc; i++) {
    debug("%d opterr: %d", i, opterr);
    debug("%d optind: %d", i, optind);
    debug("%d optopt: %d", i, optopt);
    debug("%d argv[optind]: %s", i, argv[optind]);
    if ((option = getopt(argc, argv, "+q:o:")) != -1) {
      switch (option) {
        case 'q': {

          keyword[q_flag] = optarg;
          q_flag++;







          break;
        }
        case 'o': {
            out_put_flag =1;
	  output_file = optarg;
    ofp =  fopen(output_file,"w");
          break;
        }
        case '?': {
          if (optopt != 'h')
            fprintf(stderr, KRED "-%c is not a supported argument\n" KNRM,
                    optopt);
          USAGE(argv[0]);
          exit(0);
          break;
        }
        default: {
          break;
        }
      }
    } else if(argv[optind] != NULL) {
	info("URL to snarf: %s", argv[optind]);
	url_to_snarf = argv[optind];
	optind++;
    }
  }
}
