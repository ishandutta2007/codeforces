#include <cstdio>
#include <vector>
using namespace std;
const int md=1000000007;
int n,i,x,a[100100],f[100100][2];
long long dp[100100][2];
vector<int> g[100100];
void dfs(int i) {
  int prev=n;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
    long long tot=f[k][0]+f[k][1];
    dp[k][0]=(dp[prev][0]*tot)%md;
    dp[k][1]=(dp[prev][1]*tot)%md;
    dp[k][1]=(dp[k][1]+dp[prev][0]*f[k][1])%md;
    prev=k;
  }
  if (a[i]==0) {
    f[i][0]=dp[prev][0];
    f[i][1]=dp[prev][1];
  } else f[i][1]=dp[prev][0];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d",&x);
    g[x].push_back(i);
  }
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  dp[n][0]=1;
  dfs(0);
  printf("%d\n",f[0][1]);
  return 0;
}