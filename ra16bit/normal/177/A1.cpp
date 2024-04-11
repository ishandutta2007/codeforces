#include <stdio.h>
int n,i,j,m,a,r;
int main() {
  scanf("%d",&n); m=n/2;
  for (i=0; i<n; i++) for (j=0; j<n; j++) {
    scanf("%d",&a);
    if (i==j || i==n-j-1 || i==m || j==m) r+=a;
  }
  printf("%d\n",r);
  return 0;
}