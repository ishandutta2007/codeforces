#include <cstdio>
#include <algorithm>
using namespace std;
int r,n,i,j,a[111111],f[111111][3];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) for (j=0; j<3; j++) f[i][0]=-2000000000;
  for (i=0; i<n; i++) {
    if (f[i][0]>-2000000000) {
      f[i+1][0]=max(f[i+1][0],f[i][0]-a[i]);
      f[i+1][1]=max(f[i+1][1],f[i][0]+a[i]);
    }
    if (f[i][1]>-2000000000) {
      f[i+1][1]=max(f[i+1][1],f[i][1]+a[i]);
      f[i+1][2]=max(f[i+1][2],f[i][1]-a[i]);
    }
    if (f[i][2]>-2000000000) f[i+1][2]=max(f[i+1][2],f[i][2]-a[i]);
  }
  if (f[n][1]>f[n][0]) r=f[n][1]; else r=f[n][0];
  if (f[n][2]>r) r=f[n][2];
  printf("%d\n",r);
  return 0;
}