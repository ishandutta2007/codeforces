#include <cstdio>
#include <algorithm>
using namespace std;
int it,n,i,c,q,x0[555555],v[555555],lr[555555],k[555555];
double l=0.0,r,h,xx,vv,x[555555];
inline bool cmp(int i, int j) { return (x[i]<x[j]); }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x0[i],&v[i]);
    k[i]=i;
    if (v[i]>0) {
      if (q==0) { q=1; xx=x0[i]; vv=v[i]; }
      c++;
    }
    if (v[i]<0) {
      if (q==1) q=2;
      if (q==2) r=(x0[i]-xx)/(vv-v[i]);
      lr[i]=c;
    }
  }
  for (c=0, i=n-1; i>=0; i--) if (v[i]<0) c++; else lr[i]=c;
  if (q!=2) { puts("-1"); return 0; }
  while (l<r-1e-10) {
    h=(l+r)*0.5; q=0;
    for (i=0; i<n; i++) x[i]=h*v[i]+x0[i];
    sort(k,k+n,cmp);
    for (c=i=0; i<n; i++) if (v[k[i]]>0) c++; else if (lr[k[i]]!=c) {
      q=1; break;
    }
    if (q==0) for (c=0, i=n-1; i>=0; i--) if (v[k[i]]<0) c++; else if (lr[k[i]]!=c) {
      q=1; break;
    }
    if (q) r=h; else l=h;
  }
  printf("%.15lf\n",(l+r)*0.5);
  return 0;
}