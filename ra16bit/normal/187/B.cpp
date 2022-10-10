#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=63;
int n,m,q,c,i,j,k,p,x,y,z,a[MX][MX],d[MX][MX],f[MX][MX][MX];
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (c=1; c<=m; c++) {
    for (i=1; i<=n; i++) for (j=1; j<=n; j++) scanf("%d",&a[i][j]);
    for (k=1; k<=n; k++) for (i=1; i<=n; i++) for (j=1; j<=n; j++) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for (i=1; i<=n; i++) for (j=1; j<=n; j++) if (c==1 || a[i][j]<d[i][j]) d[i][j]=a[i][j];
  }
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) for (p=0; p<=n; p++) f[i][p][j]=d[i][j];
    for (p=0; p<n; p++) for (j=1; j<=n; j++) for (k=1; k<=n; k++) f[i][p+1][k]=min(f[i][p+1][k],f[i][p][j]+d[j][k]);
  }
  while (q--) {
    scanf("%d%d%d",&x,&y,&z);
    printf("%d\n",f[x][min(z,n)][y]);
  }
  return 0;
}