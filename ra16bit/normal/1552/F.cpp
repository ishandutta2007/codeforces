#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=998244353;
int t,n,i,prv,z,r,x[MX],y[MX],f[MX],s[MX];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d%d",&x[i],&y[i],&z);
    prv=upper_bound(x+1,x+i+1,y[i])-x;
    f[i]=(x[i]-y[i]+s[i-1])%md;
    f[i]=(f[i]+md-s[prv-1])%md;
    s[i]=(s[i-1]+f[i])%md;
    if (z) r=(r+f[i])%md;
  }
  r=(r+x[n]+1)%md;
  printf("%d\n",r);
  return 0;
}