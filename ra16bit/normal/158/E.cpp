#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,n,m,r,z,t[4040],d[4040],f[4040][4040];
int main() {
  scanf("%d%d",&n,&m);
  for (j=0; j<=m; j++) f[0][j]=1;
  for (i=1; i<=n; i++) {
    scanf("%d%d",&t[i],&d[i]);
    r=max(r,t[i]-f[i-1][m]);
    for (j=0; j<=m; j++) {
      f[i][j]=max(t[i],f[i-1][j])+d[i];
      if (j>0) {
        f[i][j]=min(f[i][j],f[i][j-1]);
        f[i][j]=min(f[i][j],f[i-1][j-1]);
      }
    }
  }
  printf("%d\n",max(r,86401-f[n][m]));
  return 0;
}