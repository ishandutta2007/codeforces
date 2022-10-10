#include <cstdio>
#include <vector>
using namespace std;
int n,m,x,y,i,r;
vector<int> g[100100],f[100100],a;
bool u[100100];
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
  a.push_back(i);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y); f[x].push_back(i);
  }
  for (i=1; i<=n; i++) if (!u[i]) dfs(i);
  for (i=n-1; i>0; i--) {
    x=a[i];
    for (y=0; y<g[x].size(); y++) if (g[x][y]==a[i-1]) {
      r=max(r,f[x][y]);
      break;
    }
    if (y>=g[x].size()) { puts("-1"); return 0; }
  }
  printf("%d\n",r);
  return 0;
}