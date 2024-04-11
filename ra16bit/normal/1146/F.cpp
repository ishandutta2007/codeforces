#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,i,x,dp[200200][3];
long long f[200200][3];
vector<int> g[200200];
void dfs(int i) {
  if (g[i].empty()) {
    f[i][0]=0;
	f[i][1]=0;
	f[i][2]=1;
	return;
  }
  int p=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
	for (int e=0; e<3; e++) dp[k][e]=(dp[p][e]*(f[k][0]+f[k][2]))%md;
	for (int e=0; e<2; e++) dp[k][e+1]=(dp[k][e+1]+dp[p][e]*(f[k][1]+f[k][2]))%md;
	dp[k][2]=(dp[k][2]+dp[p][2]*(f[k][1]+f[k][2]))%md;
	p=k;
  }
  for (int e=0; e<3; e++) f[i][e]=dp[p][e];
}
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) {
    scanf("%d",&x);
	g[x].push_back(i);
  }
  dp[0][0]=1;
  dfs(1);
  printf("%d\n",int((f[1][0]+f[1][2])%md));
  return 0;
}