#include <stdio.h>
int n,a,i,j,r,b[1111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    b[a]++;
  }
  for (i=j=1; i<=1000; i++) {
    if (b[i]!=0) r++;
    if (b[i]>b[j]) j=i;
  }
  printf("%d %d\n",b[j],r);
  return 0;
}