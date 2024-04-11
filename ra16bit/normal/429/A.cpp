#include <cstdio>
#include <vector>
using namespace std;
int n,x,y,i,a[100100],b[100100];
vector<int> g[100100],r;
void dfs(int i, int p, int x, int y, int d) {
  if (d) {
    a[i]^=y;
    if (a[i]!=b[i]) { r.push_back(i); y^=1; }
  } else {
    a[i]^=x;
    if (a[i]!=b[i]) { r.push_back(i); x^=1; }
  }
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=p) dfs(g[i][j],i,x,y,d^1);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) scanf("%d",&b[i]);
  dfs(1,0,0,0,0);
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d\n",r[i]);
  return 0;
}