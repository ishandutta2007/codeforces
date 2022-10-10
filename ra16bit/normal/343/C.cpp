#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,n,m;
long long l,r,h,z,cur,a[100100],b[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%I64d",&a[i]);
  for (i=0; i<m; i++) scanf("%I64d",&b[i]);
  l=0; r=20000000000LL;
  while (l<r) {
    h=(l+r)/2;
    for (i=j=0; i<n && j<m; i++) {
      if (b[j]<a[i]) {
        z=h-(a[i]-b[j]);
        if (z<0) break;
        cur=max(b[j]+z,a[i]+z/2);
      } else cur=a[i]+h;
      while (j<m && b[j]<=cur) j++;
    }
    if (j>=m) r=h; else l=h+1;
  }
  printf("%I64d\n",r);
  return 0;
}