#include <stdio.h>
#include <math.h>
int n,m,ax,ay,bx1,by1,bx,by,cx,cy,dx1,dy1,dx,dy,rax,ray,rbx,rby,rcx,rcy,rdx,rdy;
double d,r;
double sqr(double x) { return x*x; }
void upd() {
  d=sqrt(sqr(ax-bx)+sqr(ay-by));
  d+=sqrt(sqr(cx-bx)+sqr(cy-by));
  d+=sqrt(sqr(cx-dx)+sqr(cy-dy));
  if (d>r) {
    r=d;
    rax=ax; ray=ay;
    rbx=bx; rby=by;
    rcx=cx; rcy=cy;
    rdx=dx; rdy=dy;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  if (n>0 && m>0) {
    bx=n; by=m;
    cx=n; cy=0;
    dx=0; dy=m;
    upd();
    dx=n; dy=0;
    cx=0; cy=m;
    upd();
  }
  for (ax=0; ax<2 && ax<=n; ax++) for (ay=0; ay<2 && ay<=m; ay++)
    for (bx1=0; bx1<2 && bx1<=n; bx1++) for (by1=0; by1<2 && by1<=m; by1++) {
      bx=n-bx1,by=m-by1;
      if (ax!=bx || ay!=by)
      for (cx=0; cx<2 && cx<=n; cx++) for (cy=0; cy<2 && cy<=m; cy++) if ((ax!=cx || ay!=cy) && (cx!=bx || cy!=by))
        for (dx1=0; dx1<2 && dx1<=n; dx1++) for (dy1=0; dy1<2 && dy1<=m; dy1++) {
          dx=n-dx1,dy=m-dy1;
          if ((ax!=dx || ay!=dy) && (dx!=bx || dy!=by) && (cx!=dx || cy!=dy)) upd();
        }
    }
  printf("%d %d\n",rax,ray);
  printf("%d %d\n",rbx,rby);
  printf("%d %d\n",rcx,rcy);
  printf("%d %d\n",rdx,rdy);
  return 0;
}