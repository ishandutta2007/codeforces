#include <cstdio>
#include <cmath>
using namespace std;
int ir,n,x,y,i,a[110];
long long rr,cc,xx,yy;
double r,c,eps=1e-8;
int main() {
  scanf("%d%d%d",&n,&x,&y);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%I64d%I64d",&xx,&yy);
  ir=1; rr=(xx-a[1])*(xx-a[1])+yy*yy;
  r=double(a[1])/x+sqrt(double(rr))/y;
  for (i=2; i<n; i++) {
    cc=(xx-a[i])*(xx-a[i])+yy*yy;
    c=double(a[i])/x+sqrt(double(cc))/y;
    if (c<r-eps || (fabs(r-c)<eps && cc<rr)) { ir=i; rr=cc; r=c; }
  }
  printf("%d\n",ir+1);
  return 0;
}