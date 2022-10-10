#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,a[1515][1515];
long long s,r=0,f[1515][1515],g[1515][1515],inf=1000000000;
int main() {
  scanf("%d%d",&n,&m);
  inf*=1000000;
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) scanf("%d",&a[i][j]);
    for (j=0; j<=m; j++) f[i][j]=g[i][j]=-inf;
  }
  for (f[0][0]=j=0; j<m; j++) f[0][j+1]=f[0][j]+a[0][j];
  g[0][m]=f[0][m];
  for (j=m-1; j>0; j--) g[0][j]=max(g[0][j+1],f[0][j]);
  for (i=1; i<n; i++) if (i&1) for (s=j=0; j<m-1; j++) {
    s+=a[i][j];
    f[i][j+1]=s+g[i-1][j+2];
    g[i][j+1]=f[i][j+1];
    if (j) g[i][j+1]=max(g[i][j+1],g[i][j]);
  } else {
    for (s=a[i][0],j=1; j<m; j++) {
      s+=a[i][j];
      f[i][j+1]=s+g[i-1][j];
    }
    g[i][m]=f[i][m];
    for (j=m-1; j>0; j--) g[i][j]=max(g[i][j+1],f[i][j]);
  }
//  for (i=0; i<n; i++,puts("")) for (j=0; j<=m; j++) printf("%I64d ",f[i][j]); puts("");
//  for (i=0; i<n; i++,puts("")) for (j=0; j<=m; j++) printf("%I64d ",g[i][j]); puts("");
  r=f[n-1][1];
  for (i=2; i<=m; i++) r=max(r,f[n-1][i]);
  printf("%I64d\n",r);
  return 0;
}