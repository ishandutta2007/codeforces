#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k;
double a[111];
long double x,y,best,r;
bool u[111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%lf",&a[i]);
  r=0.0;
  while (true) {
    best=r;
    for (i=0; i<n; i++) {
      u[i]=!u[i];
      x=1.; y=0.;
      for (j=0; j<n; j++) if (u[j]) {
        y=a[j]*x+(1.-a[j])*y;
        x*=1.-a[j];
      }
      u[i]=!u[i];
      if (y>best) { best=y; k=i; }
    }
    if (best<r+1e-13) break;
    r=best;
    u[k]=!u[k];
  }
  printf("%.12lf\n",double(r));
  return 0;
}