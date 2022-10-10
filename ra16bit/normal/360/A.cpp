#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,z,a[5050],l[5050],r[5050],d[5050],t[5050],b[5050];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d%d%d",&t[i],&l[i],&r[i],&d[i]);
  for (i=1; i<=n; i++) a[i]=100000000;
  for (i=m-1; i>=0; i--) for (j=l[i]; j<=r[i]; j++) if (t[i]==1) a[j]-=d[i]; else a[j]=min(a[j],d[i]);
  for (j=1; j<=n; j++) b[j]=a[j];
  for (i=0; i<m; i++) if (t[i]==2) {
    z=a[l[i]];
    for (j=l[i]+1; j<=r[i]; j++) z=max(z,a[j]);
    if (z!=d[i]) { puts("NO"); return 0; }
  } else for (j=l[i]; j<=r[i]; j++) a[j]+=d[i];
  puts("YES");
  for (j=1; j<=n; j++) printf("%d%c",b[j],j==n?'\n':' ');
  return 0;
}