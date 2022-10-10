#include <stdio.h>
int xa,ya,xb,yb,xv,yv,xw,yw,vm,t;
double l,r,h,x,y,vm2;
int main() {
  scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
  scanf("%d%d%d%d%d%d",&vm,&t,&xv,&yv,&xw,&yw);
  vm2=1.*vm*vm;
  xb-=xa; yb-=ya;
  l=0; r=1e9;
  while (l+1e-11<r) {
    h=(l+r)*0.5;
    if (h>t) {
      x=xb-(h-t)*xw-1.*t*xv;
      y=yb-(h-t)*yw-1.*t*yv;
    } else {
      x=xb-h*xv;
      y=yb-h*yv;
    }
    if (x*x+y*y>h*h*vm2) l=h; else r=h;
  }
  printf("%.15lf\n",(l+r)*0.5);
  return 0;
}