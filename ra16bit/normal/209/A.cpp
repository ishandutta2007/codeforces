#include <stdio.h>
int n,i,c,r,a[2],md=1000000007;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    c=(a[1-(i&1)]+1)%md;
    r=(r+c)%md;
    a[i&1]=(a[i&1]+c)%md;
  }
  printf("%d\n",r);
  return 0;
}