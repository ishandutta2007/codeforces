#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,x[222222];
double l,r,h,y,eps=1e-8;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&x[i]);
  sort(x,x+n);
  l=0; r=1e10;
  while (l<r-eps) {
    h=(l+r)*0.5;
    for (i=0; i<n; i++) if (x[i]-x[0]>2*h) break;
    if (i<n) {
      for (j=i; i<n; i++) if (x[i]-x[j]>2*h) break;
      if (i<n) for (j=i; i<n; i++) if (x[i]-x[j]>2*h) break;
    }
    if (i<n) l=h; else r=h;
  }
  for (i=0; i<n; i++) if (x[i]-x[0]>2*r) break;
  if (i==n) i--;
  y=x[i]+r;
  if (y>x[n-1]-r) y=x[n-1]-r;
  printf("%.6lf\n%.6lf %.6lf %.6lf\n",r,x[0]+r,y,x[n-1]-r);
  return 0;
}