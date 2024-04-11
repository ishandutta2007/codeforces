#include <cstdio>
#include <algorithm>
using namespace std;
const double eps=0.5e-7;
int n,i,a[200200];
double l,r,h1,h2,ans1,ans2;
double aa(double x) { return (x<0)?-x:x; }
double solve(double x) {
  double mn=0,mx=0,s=0,r=0;
  for (i=0; i<n; i++) {
    s+=a[i]-x;
    r=max(r,aa(s-mn));
    r=max(r,aa(s-mx));
    mn=min(s,mn);
    mx=max(s,mx);
  }
  return r;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  l=-10000; r=10000;
  for (int it=0; it<100; it++) {
    h1=(l+l+r)/3.;
    h2=(l+r+r)/3.;
    if (solve(h1)<solve(h2)) r=h2; else l=h1;
  }
  printf("%.8lf\n",solve(0.5*(l+r)));
  return 0;
}