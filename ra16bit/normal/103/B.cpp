#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,x,y,z;
vector <int> g[111];
bool u[111];
void dfs(int i) {
  u[i]=true; z++;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (n!=m) { puts("NO"); return 0; }
  dfs(1);
  if (z==n) puts("FHTAGN!"); else puts("NO");
  return 0;
}