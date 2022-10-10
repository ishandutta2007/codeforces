#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,i,j,k,r,a[102],f[102][302][302],g[302][302],e[302][302];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) for (j=1; j<=300; j++) for (k=j; k<=300; k++) {
    f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]);
    f[i][j][k+1]=max(f[i][j][k+1],f[i][j][k]);
    if (a[i]>=k) f[i+1][j][a[i]]=max(f[i+1][j][a[i]],f[i][j][k]+1);
  }
  for (i=0; i<m && i<=300; i++) for (j=1; j<=300; j++) {
    for (k=j; k<=300; k++) g[i+1][k]=max(g[i+1][k],g[i][j]+f[n][j][k]);
    for (k=j; k>0; k--) e[i+1][k]=max(e[i+1][k],e[i][j]+f[n][k][j]);
  }
  for (i=0; i<=m && i<=300; i++) for (j=0; i+j<=m && j<=300; j++) for (k=1; k<=300; k++)
    r=max(r,g[i][k]+f[n][k][k]*(m-i-j)+e[j][k]);
  printf("%d\n",r);
  return 0;
}