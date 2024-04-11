#include <bits/stdc++.h>
using namespace std;
const int MX=50500;
int t,n,m,i,j,a[MX],f[MX][3];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for (i=0; i<n; i++) a[i]-=m;
    for (i=0; i<=n; i++) for (j=0; j<3; j++) f[i][j]=-1;
    f[0][0]=0;
    for (i=0; i<n; i++) {
      if (f[i][0]>=0) {
        f[i+1][0]=max(f[i+1][0],f[i][0]);
        f[i+1][1]=max(f[i+1][1],f[i][0]+1);
      }
      if (f[i][1]>=0) {
        f[i+1][0]=max(f[i+1][0],f[i][1]);
        if (a[i-1]+a[i]>=0) f[i+1][2]=max(f[i+1][2],f[i][1]+1);
      }
      if (f[i][2]>=0) {
        f[i+1][0]=max(f[i+1][0],f[i][2]);
        if (a[i-1]+a[i]>=0 && a[i-2]+a[i-1]+a[i]>=0) f[i+1][2]=max(f[i+1][2],f[i][2]+1);
      }
    }
    printf("%d\n",max(f[n][0],max(f[n][1],f[n][2])));
  }
  return 0;
}