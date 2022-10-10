#include <bits/stdc++.h>
using namespace std;
const int MX=3636,md=998244353;
int n,m,cntn,cntm,k,i,j,r,xa,ya,xb,yb,fa[MX][MX],fb[MX][MX],a[MX],b[MX];
long long cur,f[MX],o[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  for (f[0]=o[0]=i=1; i<MX; i++) {
    f[i]=(f[i-1]*i)%md;
    o[i]=pw(f[i],md-2);
  }
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<k; i++) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    --xa; --ya;
    --xb; --yb;
    if (xa==xb) {
      a[ya]=2;
      b[xa]=1;
      ++cntn;
    } else {
      a[ya]=1;
      b[xa]=2;
      ++cntm;
    }
  }
  fa[0][0]=1;
  for (i=0; i<m; i++) for (j=0; j*2<=i; j++) if (fa[i][j]) {
    if (a[i]!=2) fa[i+1][j]=(fa[i+1][j]+fa[i][j])%md;
    if (i+1<m && a[i]!=1 && a[i+1]==0) fa[i+2][j+1]=(fa[i+2][j+1]+fa[i][j])%md;
  }
  fb[0][0]=1;
  for (i=0; i<n; i++) for (j=0; j*2<=i; j++) if (fb[i][j]) {
    if (b[i]!=2) fb[i+1][j]=(fb[i+1][j]+fb[i][j])%md;
    if (i+1<n && b[i]!=1 && b[i+1]==0) fb[i+2][j+1]=(fb[i+2][j+1]+fb[i][j])%md;
  }
  for (i=cntn; i<=m/2; i++) if (fa[m][i]) {
    cur=(fa[m][i]*f[m-i*2-cntm])%md;
    for (j=cntm; i<=n-j*2 && j<=m-i*2; j++) if (fb[n][j])
      r=(r+cur*fb[n][j]%md*f[n-j*2-cntn]%md*o[n-j*2-i]%md*o[m-i*2-j])%md;
  }
  printf("%d\n",r);
  return 0;
}