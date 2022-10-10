#include <bits/stdc++.h>
using namespace std;
const int MX=105;
int t,n,mn,inf,i,j,s,a[MX],b[MX],f[MX][MX*MX*2];
long long tot;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=0; i<n; i++) scanf("%d",&b[i]);
    for (i=0; i<=n; i++) memset(f,120,sizeof(f));
    inf=f[0][0];
    f[0][0]=s=0;
    for (tot=i=0; i<n; i++) {
      for (j=0; j<=s; j++) if (f[i][j]<inf) {
        f[i+1][j+a[i]]=min(f[i+1][j+a[i]],f[i][j]+j*a[i]+(s-j)*b[i]);
        f[i+1][j+b[i]]=min(f[i+1][j+b[i]],f[i][j]+j*b[i]+(s-j)*a[i]);
      }
      s+=a[i]+b[i];
      tot+=a[i]*a[i]+b[i]*b[i];
    }
    mn=inf;
    for (i=0; i<=s; i++) mn=min(mn,f[n][i]);
    printf("%lld\n",tot*(n-1LL)+mn*2LL);
  }
  return 0;
}