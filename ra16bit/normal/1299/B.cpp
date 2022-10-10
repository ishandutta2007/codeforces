#include <bits/stdc++.h>
using namespace std;
int n,i,x[100100],y[100100];
long long dx,dy,ex,ey;
long long sqr(long long x) { return x*x; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
  if (n&1) { puts("NO"); return 0; }
  x[n]=x[0];
  y[n]=y[0];
  n/=2;
  for (i=1; i<=n; i++) {
    dx=x[i]-x[i-1];
    dy=y[i]-y[i-1];
    ex=x[i+n]-x[i+n-1];
    ey=y[i+n]-y[i+n-1];
    if (sqr(dx)+sqr(dy)!=sqr(ex)+sqr(ey)) {
      puts("NO"); return 0;
    }
    if (dx*ey!=dy*ex) {
      puts("NO"); return 0;
    }
  }
  puts("YES");
  return 0;
}