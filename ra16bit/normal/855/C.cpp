#include <bits/stdc++.h>
using namespace std;
const int md=1000000007,MX=100100;
int n,m,K,X,i,x,y,res,f[MX][3][11];
long long dp[MX][3][11];
vector<int> g[MX];
void dfs(int i, int p) {
  int prev=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    for (int pj=0; pj<3; pj++) for (int pk=0; pk<=X; pk++) if (dp[prev][pj][pk])
      for (int cj=0; cj<3; cj++) for (int ck=0; pk+ck<=X; ck++) if (f[k][cj][ck]) {
        int nj=(pj==1 || cj==1)?1:max(pj,cj);
        dp[k][nj][pk+ck]=(dp[k][nj][pk+ck]+dp[prev][pj][pk]*f[k][cj][ck])%md;
      }
    prev=k;
  }
  for (int pk=0; pk<=X; pk++) {
    f[i][0][pk]=(((dp[prev][0][pk]+dp[prev][1][pk]+dp[prev][2][pk])%md)*(K-1))%md;
    if (pk<X) f[i][1][pk+1]=dp[prev][0][pk];
    f[i][2][pk]=(((dp[prev][0][pk]+dp[prev][2][pk])%md)*(m-K))%md;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  scanf("%d%d",&K,&X);
  dp[0][0][0]=1;
  dfs(1,0);
  for (i=0; i<3; i++) for (x=0; x<=X; x++) res=(res+f[1][i][x])%md;
  printf("%d\n",res);
  return 0;
}