#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,d,az,bz,cz,dz;
double l,r,h,A,B,mA,mB,nA,nB,eps=1e-11;
int main() {
  scanf("%d%d%d%d",&a,&b,&c,&d);
  A=a; A*=d;
  B=b; B*=c;
  if (fabs(A-B)<eps) { puts("0"); return 0; }
  l=0; r=2e10;
  for (int it=0; it<100000; it++) {
    h=(l+r)*0.5;
    for (az=0; az<2; az++)  for (dz=0; dz<2; dz++) {
      if (az) A=a-h; else A=a+h;
      if (dz) A*=d-h; else A*=d+h;
      if (az>0 || dz>0) {
        mA=max(mA,A);
        nA=min(nA,A);
      } else mA=nA=A;
    }
    for (bz=0; bz<2; bz++) for (cz=0; cz<2; cz++) {
      if (bz) B=b-h; else B=b+h;
      if (cz) B*=c-h; else B*=c+h;
      if (bz>0 || cz>0) {
        mB=max(mB,B);
        nB=min(nB,B);
      } else mB=nB=B;
    }
    if (max(nA,nB)<min(mA,mB)-eps) r=h; else l=h;
  }
  printf("%.15lf\n",(l+r)*0.5);
  return 0;
}