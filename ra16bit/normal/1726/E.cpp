#include <bits/stdc++.h>
using namespace std;
const int MX=300100,md=998244353;
int t,i,n,cnt,res;
long long F[MX],O[MX],f[MX],dp[MX],pw2[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
long long C(int n, int m) {
  return (((F[n]*O[m])%md)*O[n-m])%md;
}
long long solve(int n, int m) {
  long long cur=(C(n-m*2,m*2)*pw2[m])%md;
  return (cur*dp[m*2-1])%md;
}
int main() {
  for (F[0]=O[0]=pw2[0]=i=1; i<MX; i++) {
    F[i]=(F[i-1]*i)%md;
    O[i]=pw(F[i],md-2);
    pw2[i]=(pw2[i-1]*2)%md;
  }
  f[0]=f[1]=dp[0]=dp[1]=1;
  for (i=2; i<MX; i++) {
    f[i]=(f[i-1]+f[i-2]*(i-1LL))%md;
    dp[i]=(dp[i-2]*i)%md;
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    cnt=n/4;
    res=f[n];
    for (i=1; i<=cnt; i++) res=(res+solve(n,i)*f[n-i*4])%md;
    printf("%d\n",res);
  }
  return 0;
}