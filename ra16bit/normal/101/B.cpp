#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int n,m,e,l,r,h,i,b[100100],c[100100],f[100100],s[100100],md=1000000007;
pair <int, int> a[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d",&a[i].second,&a[i].first);
  sort(a,a+m); b[1]=a[0].first; c[0]=e=1;
  for (i=1; i<m; i++) {
    if (a[i].first!=a[i-1].first) b[++e]=a[i].first;
    c[i]=e;
  }
  if (b[e]!=n) { puts("0"); return 0; }
  f[0]=s[0]=1;
  for (i=0; i<m; i++) {
    l=0; r=c[i];
    while (l<r) {
      h=(l+r)/2;
      if (b[h]<a[i].second) l=h+1; else r=h;
    }
    if (r<c[i]) {
      f[c[i]]+=(s[c[i]-1]-((r>0)?s[r-1]:0)+md)%md;
      if (f[c[i]]>=md) f[c[i]]-=md;
    }
    if (c[i]!=c[i+1]) {
      s[c[i]]=s[c[i]-1]+f[c[i]];
      if (s[c[i]]>=md) s[c[i]]-=md;
    }
  }
  printf("%d\n",f[e]);
  return 0;
}