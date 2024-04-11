#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,x,y,cc,r,a[2020],c[2020];
bool b[2020];
vector <int> g[2020];
void dfs(int i) {
  c[i]=cc;
  a[cc]++;
  for (int j=0; j<g[i].size(); j++) if (c[g[i][j]]==0) dfs(g[i][j]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (c[i]==0) { ++cc; dfs(i); }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    if (c[x]==c[y]) b[c[x]]=true;
  }
  for (i=1; i<=cc; i++) if (!b[i]) r=max(r,a[i]);
  printf("%d\n",r);
  return 0;
}