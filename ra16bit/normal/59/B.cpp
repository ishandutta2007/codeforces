#include <stdio.h>
int n,i,a,s,x=1000000000;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    s+=a;
    if ((a&1) && a<x) x=a;
  }
  if ((s&1)==0) {
    if (x!=1000000000) printf("%d\n",s-x); else printf("0\n");
  } else printf("%d\n",s);
  return 0;
}