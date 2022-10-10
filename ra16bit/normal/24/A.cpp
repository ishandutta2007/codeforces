#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,x,y,z,i;
vector <int> g[110],f[110];
int dfs(int x, int p) {
  if (x==1) return 0;
  int z=0;
  if (g[x][0]==p) z=1;
  return dfs(g[x][z],x)+f[x][z];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(0);
    g[y].push_back(x); f[y].push_back(z);
  }
  printf("%d\n",min(dfs(g[1][0],1)+f[1][0],dfs(g[1][1],1)+f[1][1]));
  return 0;
}