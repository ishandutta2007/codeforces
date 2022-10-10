
#include <stdio.h>
int n,i,x,y;
long long kx,ky,sx,sy,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    kx+=x*x; ky+=y*y;
    sx+=x;   sy+=y;
  }
  printf("%I64d\n",n*kx+n*ky-sx*sx-sy*sy);
  return 0;
}