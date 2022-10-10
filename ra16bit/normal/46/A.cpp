#include <stdio.h>
int n,i,j;
int main() {
  scanf("%d",&n);
  for (i=j=1; i<n; i++) {
    j=(j-1+i)%n+1;
    if (i!=1) putchar(' ');
    printf("%d",j);
  }
  return 0;
}