#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,x,y,z,u[1111];
bool q;
vector <int> g[1111],o[1111],r[4];
vector <bool> w[1111];
void dfs(int i, int p) {
  u[i]=z;
  for (int j=0; j<g[i].size(); j++) if (w[i][j]) {
    int k=g[i][j];
    if (k==p) continue;
    if (u[k]==0) dfs(k,i); else if (q) {
      q=false; x=i; y=j;
    }
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    o[x].push_back(g[y].size());
    o[y].push_back(g[x].size());
    g[x].push_back(y); w[x].push_back(true);
    g[y].push_back(x); w[y].push_back(true);
  }
  while (!q) {
    q=true;
    for (i=1; i<=n; i++) u[i]=0;
    for (i=1; i<=n; i++) if (u[i]==0) {
      z++; dfs(i,0);
      if (!q) {
        r[0].push_back(x);
        r[1].push_back(g[x][y]);
        w[x][y]=false;
        w[g[x][y]][o[x][y]]=false;
        for (j=1; j<=n; j++) if (u[j]!=z) {
          r[2].push_back(i); o[i].push_back(g[j].size());
          r[3].push_back(j); o[j].push_back(g[i].size());
          g[i].push_back(j); w[i].push_back(true);
          g[j].push_back(i); w[j].push_back(true);
          break;
        }
        break;
      }
    }
  }
  n=r[0].size();
  printf("%d\n",n);
  for (i=0; i<n; i++) printf("%d %d %d %d\n",r[0][i],r[1][i],r[2][i],r[3][i]);
  return 0;
}