#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,m,i,j,r,a[222],f[222][222];
int main() {
  scanf("%d",&n); m=n; n=2*n-1;
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  memset(f,140,sizeof(f));
  f[0][0]=0; r=f[0][1];
  for (i=0; i<n; i++) for (j=0; j<=i; j++) {
    f[i+1][j]=max(f[i+1][j],f[i][j]+a[i]);
	f[i+1][j+1]=max(f[i+1][j+1],f[i][j]-a[i]);
  }
  for (j=0; j<=n; j++) if (f[n][j]>r && (j%2==0 || m%2==1)) r=f[n][j];
  printf("%d\n",r);
  return 0;
}