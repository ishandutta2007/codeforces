#include <stdio.h>
int n,a,i,b=101,c;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    if (a<b) { c=b; b=a;}
     else if (a>b && a<c) c=a;
  }
  if (c==101) puts("NO"); else printf("%d\n",c);
  return 0;
}