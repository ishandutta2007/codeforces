#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=998244353;
int n,i,x,y;
long long f[MX][4],dp[MX][4];
vector<int> g[MX],e[MX];
void dfs(int i, int p, int pe) {
  int prev=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j],ed=e[i][j];
    if (k==p) continue;
    dfs(k,i,ed);
    long long cur1=f[k][1]+f[k][2];
    long long cur2=f[k][0]+f[k][1]+f[k][3];
    dp[k][0]=(dp[prev][0]*cur1)%md;
    if (ed<pe) {
      dp[k][1]=(dp[prev][1]*cur2+dp[prev][0]*(f[k][0]+f[k][3]))%md;
      dp[k][2]=(dp[prev][2]*cur1)%md;
    } else {
      dp[k][1]=(dp[prev][1]*cur2)%md;
      dp[k][2]=(dp[prev][2]*cur2)%md;
      dp[k][3]=(dp[prev][3]*cur2+dp[prev][0]*(f[k][0]+f[k][3]))%md;
    }
    prev=k;
  }
  for (int j=0; j<4; j++) f[i][j]=dp[prev][j];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y); e[x].push_back(i);
    g[y].push_back(x); e[y].push_back(i);
  }
  dp[0][0]=dp[0][2]=1;
  dfs(1,0,0);
  printf("%d\n",int((f[1][0]+f[1][1]+f[1][3])%md));
  return 0;
}