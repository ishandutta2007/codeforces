#include <cstdio>
#include <vector>
using namespace std;
const int md=1000000007;
int n,m,i,x,y,r,d[105],f[105][105][25];
long long dp[105][105][25];
vector<int> g[105];
void dfs(int i, int p) {
  int prev=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    d[i]=max(d[i],d[k]+1);
    for (int dep=0; dep<=d[i]; dep++) for (int dist=0; dist<=m && dist<=d[i]; dist++) if (dp[prev][dep][dist])
      for (int de=0; de<=d[k]+1; de++) for (int di=0; di<=m && di<=d[k]+1; di++) if (f[k][de][di]) {
        int ni=max((dep>0 && di>0 && dep+di<=m)?0:di,(de>0 && dist>0 && de+dist<=m)?0:dist);
        if (ni<=m) {
          int ne=(dep>0 && de>0)?min(dep,de):(dep+de);
          dp[k][ne][ni]=(dp[k][ne][ni]+dp[prev][dep][dist]*f[k][de][di])%md;
        }
      }
    prev=k;
  }
  for (int dep=0; dep<=d[i]; dep++) for (int dist=0; dist<=m && dist<=d[i]; dist++) if (dp[prev][dep][dist]) {
    int ne=dep?dep+1:0;
    int ni=dist?dist+1:int(dep==0 || dep>m);
    f[i][ne][ni]=(f[i][ne][ni]+dp[prev][dep][dist])%md;
    f[i][1][0]=(f[i][1][0]+dp[prev][dep][dist])%md;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dp[0][0][0]=1;
  dfs(1,0);
  for (i=0; i<=n; i++) r=(r+f[1][i][0])%md;
  printf("%d\n",r);
  return 0;
}