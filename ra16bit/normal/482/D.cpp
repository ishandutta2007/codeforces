#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int md=1000000007;
int n,i,x,f[100100][2],dp[100100][2][3][4];
vector<int> g[100100];
void dfs(int i) {
  int prev=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
    for (int bef=0; bef<2; bef++) for (int last=0; last<3; last++) for (int mask=1; mask<4; mask++) if (dp[prev][bef][last][mask]) {
      long long cur=dp[prev][bef][last][mask];
      dp[k][bef][last][mask]=(dp[k][bef][last][mask]+cur)%md;
      for (int ins=0; ins<2; ins++) if (f[k][ins]) for (int w=0; w<2; w++) {
        int nmask=mask;
        if ((nmask&1) && w!=bef) nmask^=1;
        if ((nmask&2) && last!=2 && last!=(w^ins)) nmask^=2;
        dp[k][bef^ins][w][nmask]=(dp[k][bef^ins][w][nmask]+cur*f[k][ins])%md;
      }
    }
    prev=k;
  }
  for (int bef=0; bef<2; bef++) for (int last=0; last<3; last++) for (int mask=1; mask<4; mask++)
    if (dp[prev][bef][last][mask] && ((mask&1) || last==1)) f[i][bef]=(f[i][bef]+dp[prev][bef][last][mask])%md;
}
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) {
    scanf("%d",&x);
    g[x].push_back(i);
  }
  for (i=1; i<=n; i++) sort(g[i].begin(),g[i].end());
  dp[0][1][2][3]=1;
  dfs(1);
  printf("%d\n",(f[1][0]+f[1][1])%md);
  return 0;
}