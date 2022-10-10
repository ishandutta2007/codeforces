#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int tt,n,m,i,lx,rx,a[100100];
double t,lt,rt,vl,vr,le,ri;
int main() {
  scanf("%d",&tt);
  while (tt--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    a[0]=0; a[n+1]=m;
    vl=vr=1;
    for (t=le=0, ri=m, lx=1, rx=n; lx<=rx; ) {
      lt=(a[lx]-le)/vl;
      rt=(ri-a[rx])/vr;
      if (fabs(lt-rt)<eps) {
        le+=lt*vl;
        ri-=lt*vr;
        lx++; vl++;
        rx--; vr++;
        t+=lt;
      } else if (lt<rt) {
        le+=lt*vl;
        ri-=lt*vr;
        t+=lt; lx++; vl++;
      } else {
        le+=rt*vl;
        ri-=rt*vr;
        t+=rt; rx--; vr++;
      }
      //printf("t=%.5lf le=%.5lf(%.5lf) ri=%.5lf(%.5lf) | %d %d\n",t,le,vl,ri,vr,lx,rx);
    }
    printf("%.10lf\n",t+max(0.,(ri-le)/(vl+vr)));
  }
  return 0;
}