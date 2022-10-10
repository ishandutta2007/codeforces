#include <bits/stdc++.h>
using namespace std;
const int MX=300300,md=998244353;
int n,x,y,i,r;
long long cnt[MX],dp[MX][3],f[MX][3];
vector<int> g[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void dfs(int i, int p) {
  //cnt[i]=1;
  int prv=0;
  for (int j: g[i]) if (j!=p) {
    dfs(j,i);
    //cnt[i]=(cnt[i]*2LL*cnt[j])%md;
    dp[j][0]=(dp[prv][0]*f[j][0])%md;
    dp[j][1]=((dp[prv][0]+dp[prv][1])*f[j][1]+dp[prv][1]*f[j][0])%md;
    dp[j][2]=((dp[prv][0]+dp[prv][1]+dp[prv][2])%md*f[j][2]+dp[prv][2]*(f[j][0]+f[j][1]))%md;
    prv=j;
  }
  f[i][0]=(dp[prv][0]+dp[prv][1]*2+dp[prv][2])%md;
  f[i][1]=(dp[prv][0]+dp[prv][1]+dp[prv][2])%md;
  f[i][2]=(dp[prv][0]+dp[prv][1])%md;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dp[0][0]=1;
  dfs(1,0);
  printf("%d\n",int((f[1][0]+md-1)%md));
  return 0;
}