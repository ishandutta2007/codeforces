#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int i,j,k,n,t[2010],c[2010];
long long r,f[2010][5001];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&t[i],&c[i]);
  memset(f,120,sizeof(f)); f[0][2500]=0;
  for (i=0; i<n; i++) for (j=0; j<=5000; j++) if (f[i][j]<f[0][5000]) {
    k=min(5000,j+t[i]);
    f[i+1][k]=min(f[i+1][k],f[i][j]+c[i]);
    f[i+1][j-1]=min(f[i+1][j-1],f[i][j]);
  }
  r=f[n][2500];
  for (i=2501; i<=5000; i++) r=min(r,f[n][i]);
  printf("%I64d\n",r);
  return 0;
}