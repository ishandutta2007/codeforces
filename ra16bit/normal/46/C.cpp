#include <stdio.h>
int n,i,j,p,e,r;
char s[1111];
int main() {
  scanf("%d",&n); scanf("%s",s); r=n;
  for (i=0; i<n; i++) if (s[i]=='T') p++;
  for (i=0; i<n; i++) {
    for (e=j=0; j<p; j++) if (s[(i+j)%n]=='H') e++;
    if (e<r) r=e;
  }
  printf("%d\n",r);
  return 0;
}