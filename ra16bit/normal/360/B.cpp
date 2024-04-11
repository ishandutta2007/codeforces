#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,l,r,h,a[2020],f[2020];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  if (m>=n-1) { puts("0"); return 0; }
  l=0; r=2000000000;
  while (l<r) {
    h=((long long)l+r)/2;
    for (i=1; i<=n; i++) f[i]=i-1;
    for (i=1; i<=n; i++) {
      for (j=i; j<n; j++) if ((j-i+1LL)*h>=abs(a[i-1]-a[j])) f[j+1]=min(f[i]+j-i,f[j+1]);
      f[n]=min(f[n],f[i]+n-i);
    }
    if (f[n]<=m) r=h; else l=h+1;
  }
  printf("%d\n",r);
  return 0;
}