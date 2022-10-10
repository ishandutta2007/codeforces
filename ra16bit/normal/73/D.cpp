#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,b,c,d,e,x,y,i;
bool u[1000100];
vector <int> g[1000100];
void dfs(int i) {
  u[i]=true; d++;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (!u[i]) {
    d=0; dfs(i);
    if (d==1) b++; else { c++; e+=min(k,d); }
  }
  if (b+c<3) { puts("0"); return 0; }
  if (k==1) { printf("%d\n",b+c-2); return 0; }
  if (c==0) { printf("%d\n",(b-1)/2); return 0; }
  e-=2*(c-1); b-=e;
  if (b<=0) puts("0"); else printf("%d\n",(b+1)/2);
  return 0;
}