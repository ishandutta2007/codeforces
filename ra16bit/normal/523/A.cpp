#include <stdio.h>
int n,m,i,j;
char s[111][111];
int main() {
  scanf("%d%d",&m,&n);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<2*m; i++, puts("")) for (j=0; j<2*n; j++) putchar(s[j/2][i/2]);
  return 0;
}