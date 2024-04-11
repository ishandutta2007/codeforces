#include <bits/stdc++.h>
using namespace std;
long long f[100100][5],dp[100100][5][3];
int n,i,x,y,a[100100];
vector<int> g[100100];
void dfs(int i, int p) {
  int prev=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    for (int e=0; e<5; e++) for (int z=0; z<3; z++) if (dp[prev][e][z]!=-1) for (int ne=0; e+ne<5; ne++) {
      int nz=z+int(ne==1 || ne==3);
      if (nz>=3) continue;
      dp[k][e+ne][nz]=max(dp[k][e+ne][nz],dp[prev][e][z]+f[k][ne]);
    }
    prev=k;
  }
  for (int e=0; e<5; e++) for (int z=0; z<3; z++) if (dp[prev][e][z]!=-1) f[i][e]=max(f[i][e],dp[prev][e][z]+int(z>0)*a[i]);
  f[i][1]=max(f[i][1],1LL*a[i]);
  for (int e=1; e<5; e++) f[i][e]=max(f[i][e],f[i][e-1]);
}
int main() {
  scanf("%d",&n);
  memset(dp,255,sizeof(dp));
  dp[0][0][0]=0;
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    dp[i][0][0]=0;
  }
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  
  dfs(1,0);
  printf("%I64d\n",f[1][4]);
  return 0;
}