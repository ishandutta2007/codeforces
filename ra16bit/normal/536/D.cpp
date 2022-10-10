#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<long long,int> pli;
int n,m,i,j,x,y,z,s[2],w[2][2005],a[2005];
long long p[2][2005],dp[2005][2005][2][2],cur,e;
bool was[2005][2005][2][2];
vector<int> g[2005],f[2005];
priority_queue<pli, vector<pli>, greater<pli> > q;
pli all[2][2005];
long long F(int i, int j, int who, int pass) {
  if (i>=n || j>=n) return 0;
  if (was[i][j][who][pass]) return dp[i][j][who][pass];
  was[i][j][who][pass]=true;
  if (who) {
    int cur=all[who][j].second;
    bool can=w[who^1][cur]>=i;
    dp[i][j][who][pass]=F(i,j+1,who,int(pass || can))-(can?a[cur]:0);
  } else {
    int cur=all[who][i].second;
    bool can=w[who^1][cur]>=j;
    dp[i][j][who][pass]=F(i+1,j,who,int(pass || can))+(can?a[cur]:0);
  }
  if (pass) {
    if (who) {
      if (all[who][j].first!=all[who][j-1].first)
        dp[i][j][who][pass]=min(dp[i][j][who][pass],F(i,j,who^1,0));
    } else if (all[who][i].first!=all[who][i-1].first)
        dp[i][j][who][pass]=max(dp[i][j][who][pass],F(i,j,who^1,0));
  }
  return dp[i][j][who][pass];   
}
int main() {
  scanf("%d%d%d%d",&n,&m,&s[0],&s[1]);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  while (m--) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  for (i=0; i<2; i++) {
    q.push(make_pair(0,s[i]));
    memset(p[i],120,sizeof(p[i]));
    p[i][s[i]]=m=0;
    while (!q.empty()) {
      cur=q.top().first;
      x=q.top().second;
      q.pop();
      if (cur!=p[i][x]) continue;
      w[i][x]=m;
      all[i][m++]=make_pair(cur,x);
      for (j=0; j<g[x].size(); j++) {
        y=g[x][j];
        e=cur+f[x][j];
        if (e<p[i][y]) {
          p[i][y]=e;
          q.push(make_pair(e,y));
        }
      }
    }
  }
  e=F(0,0,0,0);
  puts((e>0)?"Break a heart":((e<0)?"Cry":"Flowers"));
  return 0;
}