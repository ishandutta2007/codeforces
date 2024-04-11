#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,x,y,a[100100];
bool u[100100],w[100100];
vector <int> g[100100],o[100100];
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
}
void ofs(int i) {
  w[i]=true;
  if (a[i]==1) return;
  for (int j=0; j<o[i].size(); j++) if (!w[o[i][j]]) ofs(o[i][j]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    o[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (a[i]==1 && (!u[i])) dfs(i);
  for (i=1; i<=n; i++) if (a[i]==2 && (!w[i])) ofs(i);
  for (i=1; i<=n; i++) printf("%d\n",int(u[i] && w[i]));
  return 0;
}