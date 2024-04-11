#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const long double pi=acos(-1.0),eps=1e-8;
int xp,yp,vp,x,y,v,r,it;
long double s,h,le,ri,L,R,D,xc,yc,st,angp,angl,dstp,dstl,tm;
long double sqr(long double x) { return x*x; }
long double solve(long double a1, long double a2) {
  long double x=a2-a1;
  while (x<0) x+=2*pi;
  while (x>=2*pi) x-=2*pi;
  if (x>pi) x=2*pi-x;
  return x*r;
}
bool inside() {
  long double a,b,c,d,t,xx,yy,mx,my,nx,ny;
  a=y-yc;
  b=xc-x;
  c=-a*x-b*y;
  d=a*a+b*b;
  if (d<0) d=0;
  if (d==0) return false;
  d=sqrt(d);
  t=fabs(c)/d;
  if (t>=r) return false;
  xx=a*t/d;
  yy=b*t/d;
  mx=max((long double)x,xc); my=max((long double)y,yc);
  nx=min((long double)x,xc); ny=min((long double)y,yc);
  if (fabs(a*xx+b*yy+c)<eps) return xx>=nx-eps && xx<=mx+eps && yy>=ny-eps && yy<=my+eps;
  return -xx>=nx-eps && -xx<=mx+eps && -yy>=ny-eps && -yy<=my+eps;
}
int main() {
  scanf("%d%d%d",&xp,&yp,&vp);
  R=sqrt(sqr(xp)+sqr(yp));
  scanf("%d%d%d%d",&x,&y,&v,&r);
  D=sqrt(sqr(x)+sqr(y));
  st=atan2(y,x);
  le=atan2(yp,xp); L=le;
  ri=(D/R)*2e4;
  angp=fabs(acos(r/R)); dstp=sqrt(R*R-r*r);
  angl=fabs(acos(r/D)); dstl=sqrt(D*D-r*r);
  for (it=1; it<=400; it++) {
    h=(le+ri)*0.5;
    tm=((h-L)*R)/vp;
    xc=R*cos(h);
    yc=R*sin(h);
    if (inside()) {
      s=min(solve(h+angp,st+angl),solve(h+angp,st-angl));
      s=min(s,solve(h-angp,st+angl));
      s=min(s,solve(h-angp,st-angl));
      s+=dstp+dstl;
    } else s=sqrt(sqr(x-xc)+sqr(y-yc));
    if (s/v>tm) le=h; else ri=h;
  }
  printf("%.15lf\n",double(tm));
  return 0;
}