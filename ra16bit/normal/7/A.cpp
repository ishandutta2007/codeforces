#include <stdio.h>
int i,j,a,b,r;
char s[9][9];
int main() {
  for (i=0; i<8; i++) gets(s[i]);
  for (i=0; i<8; i++) {
    a=1; b=1;
    for (j=0; j<8; j++) {
      if (s[i][j]=='W') a=0;
      if (s[j][i]=='W') b=0;
    }
    r+=a+b;
  }
  if (r==16) r=8;
  printf("%d\n",r);
  return 0;
}