#include <bits/stdc++.h>
using namespace std;
const int MX=400200;
int t,n,m,i,j,x,y,tot,f[MX],a[MX];
vector<int> g[MX],o[MX],r;
bool u[MX];
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
  a[++tot]=i;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) {
      g[i].clear();
      o[i].clear();
      u[i]=false;
      f[i]=0;
    }
    for (tot=i=0; i<m; i++) {
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      o[y].push_back(x);
    }
    for (i=1; i<=n; i++) if (!u[i]) dfs(i);
    r.clear();
    for (i=n; i>0; i--) {
      x=a[i];
      for (j=0; j<o[x].size(); j++) f[x]=max(f[x],f[o[x][j]]+1);
      if (f[x]==2) {
        r.push_back(x);
        f[x]=-1;
      }
    }
    printf("%d\n",int(r.size()));
    for (i=0; i<r.size(); i++) printf("%d ",r[i]);
    puts("");
  }
  return 0;
}