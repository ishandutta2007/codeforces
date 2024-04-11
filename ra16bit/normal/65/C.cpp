#include <stdio.h>
#include <math.h>
int i,n,v,w,it,x[10100],y[10100],z[10100],px,py,pz;
long double lx,ly,lz,hx,hy,hz,rx,ry,rz,d,d1,d2,e,vw;
long double sqr(long double x) { return x*x; }
bool ok(long double hx, long double hy, long double hz) {
  long double t1=sqrt(sqr(hx-px)+sqr(hy-py)+sqr(hz-pz))/v;
  long double t2=(d+sqrt(sqr(hx-x[i-1])+sqr(hy-y[i-1])+sqr(hz-z[i-1])))/w;
  if (t1>t2+1e-8) return false;
  puts("YES");
  printf("%.10lf\n",double(t1));
  printf("%.10lf %.10lf %.10lf\n",double(hx),double(hy),double(hz));
  return true;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<=n; i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
  scanf("%d%d",&v,&w);
  vw=v; vw*=v; vw/=w; vw/=w;
  scanf("%d%d%d",&px,&py,&pz);
  for (i=1; i<=n; i++) {
    lx=x[i-1]; ly=y[i-1]; lz=z[i-1];
    rx=x[i];   ry=y[i];   rz=z[i];
    e=sqrt(sqr(rx-lx)+sqr(ry-ly)+sqr(rz-lz));
    for (it=0; it<500; it++) {
      hx=(lx+rx)*0.5;
      hy=(ly+ry)*0.5;
      hz=(lz+rz)*0.5;
      d1=sqrt(sqr(hx-px)+sqr(hy-py)+sqr(hz-pz));
      d2=sqrt(sqr(hx-x[i-1])+sqr(hy-y[i-1])+sqr(hz-z[i-1]));
      if (d1/v<(d+d2)/w) { rx=hx; ry=hy; rz=hz; } else { lx=hx; ly=hy; lz=hz; }
    }
    if (ok(rx,ry,rz)) return 0;
    d+=e;
  }
  puts("NO");
  return 0;
}