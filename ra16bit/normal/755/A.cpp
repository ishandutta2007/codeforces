#include <stdio.h>
int n,i,j,x;
int main() {
  scanf("%d",&n);
  for (i=1; i<=1000; i++) {
    x=n*i+1;
    for (j=2; j<x; j++) if (x%j==0) break;
    if (j<x) { printf("%d\n",i); break; }
  }
  return 0;
}