#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,a[5005],f[5005][5005];
double x[5005];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d%lf",&a[i],&x[i]);
  for (i=0; i<=n; i++) for (j=1; j<=m; j++) {
    if (j<m) f[i][j+1]=max(f[i][j],f[i][j+1]);
	if (i<n) f[i+1][j]=max(f[i+1][j],f[i][j]+int(a[i]==j));
  }
  printf("%d\n",n-f[n][m]);
  return 0;
}