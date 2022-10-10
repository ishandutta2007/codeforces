#include <cstdio>
#include <algorithm>
using namespace std;
int hx,ax,dx,hy,ay,dy,hz,az,dz,sx,sy,i,j,b,c,r=2000000000;
int main() {
  scanf("%d%d%d",&hx,&ax,&dx);
  scanf("%d%d%d",&hy,&ay,&dy);
  scanf("%d%d%d",&hz,&az,&dz);
  for (i=0; i<=max(0,hy+dy-ax); i++) for (j=0; j<=max(0,ay-dx); j++) {
    sx=ax+i-dy;
    if (sx<=0) continue;
    sy=max(0,ay-(dx+j));
    c=(hy+sx-1)/sx;
    b=hx-c*sy;
    if (b<=0) b=1-b; else b=0;
    r=min(r,i*az+j*dz+b*hz);
  }
  printf("%d\n",r);
  return 0;
}