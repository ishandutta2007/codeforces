#include <cstdio>
#include <vector>
using namespace std;
int n,i,x,a[200200];
vector<int> g[200200];
long long f[200200][2],dp[200200][2];
void dfs(int i) {
  int prev=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
    for (int p=0; p<2; p++) if (dp[prev][p]>=0)
      for (int e=0; e<2; e++) if (f[k][e]>=0)
        dp[k][p^e]=max(dp[k][p^e],dp[prev][p]+f[k][e]);
    prev=k;
  }
  f[i][0]=max(f[i][0],dp[prev][0]);
  f[i][1]=max(f[i][1],dp[prev][0]+a[i]);
  f[i][1]=max(f[i][1],dp[prev][1]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x,&a[i]);
    if (x>0) g[x].push_back(i);
  }
  for (i=0; i<=n; i++) f[i][1]=dp[i][1]=-1;
  dfs(1);
  printf("%I64d\n",max(f[1][0],f[1][1]));
  return 0;
}