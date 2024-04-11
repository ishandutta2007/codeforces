#include <stdio.h>
int px[2],py[2],n[2],x[2][1010],y[2][1010];
long long sqr(long long x) { return x*x; }
bool solve(int a, int b) {
  long long r=sqr(px[a]-px[b])+sqr(py[a]-py[b]);
  for (int j=0; j<n[b]; j++) {
    int cx=px[a]+x[b][j]-px[b];
    int cy=py[a]+y[b][j]-py[b];
    for (int i=0; i<n[a]; i++) {
      int ax=x[a][i],bx=x[a][i+1];
      int ay=y[a][i],by=y[a][i+1];
      long long d1=sqr(ax-cx)+sqr(ay-cy);
      long long d2=sqr(bx-cx)+sqr(by-cy);
      if ((d1<=r && d2>=r) || (d2<=r && d1>=r)) return true;
      if (d1<r && d2<r) continue;
      long long A=by-ay,B=ax-bx,C=-A*ax-B*ay,t=A*A+B*B;
      long long d=sqr(A*cx+B*cy+C);
      if (d<=r*t) {
        long long nx=cx+A,ny=cy+B;
        A=ny-cy; B=cx-nx; C=-A*cx-B*cy;
        long long z1=A*ax+B*ay+C;
        long long z2=A*bx+B*by+C;
        if ((z1<0 && z2>0) || (z2<0 && z1>0)) return true;
      }
    }
  }
  return false;
}
int main() {
  for (int j=0; j<2; j++) {
    scanf("%d%d%d",&px[j],&py[j],&n[j]);
    for (int i=0; i<n[j]; i++) scanf("%d%d",&x[j][i],&y[j][i]);
    x[j][n[j]]=x[j][0];
    y[j][n[j]]=y[j][0];
  }
  puts((solve(0,1) || solve(1,0))?"YES":"NO");
  return 0;
}