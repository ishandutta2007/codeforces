#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,x,y,z,i,j,k,a[302010];
long long f[5005][5005];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  x=n%m; y=m-x; z=n/m;
  memset(f,120,sizeof(f));
  f[0][0]=0;
  for (i=0; i<=x; i++) for (j=0; j<=y; j++) {
    k=z*(i+j)+i;
    if (i<x) f[i+1][j]=min(f[i+1][j],f[i][j]+a[k+z]-a[k]);
    if (j<y) f[i][j+1]=min(f[i][j+1],f[i][j]+a[k+z-1]-a[k]);
  }
  printf("%I64d\n",f[x][y]);
  return 0;
}