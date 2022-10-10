#include <cstdio>
#include <vector>
using namespace std;
const int md=1000000007;
int n,m,i,x,y,z,r,c[100100];
vector<pair<int,int> > g[100100];
bool dfs(int i, int cc) {
  if (c[i]!=-1) return c[i]==cc;
  c[i]=cc;
  for (int j=0; j<g[i].size(); j++)
    if (!dfs(g[i][j].first,cc^g[i][j].second))
      return false;
  return true;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) c[i]=-1;
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(make_pair(y,z^1));
    g[y].push_back(make_pair(x,z^1));
  }
  for (i=1; i<=n; i++) if (c[i]==-1) {
    r++;
    if (!dfs(i,1)) { puts("0"); return 0; }
  }
  for (z=i=1; i<r; i++) z=(z*2)%md; 
  printf("%d\n",z);
  return 0;
}