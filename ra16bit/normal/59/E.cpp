#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,k,x,y,z,fi,fr,q[10000000],e[10000000],p[3010][3010],f[3010][3010];
vector <int> g[3010],w[3010][3010];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=0; i<k; i++) {
    scanf("%d%d%d",&x,&y,&z);
    w[y][x].push_back(z);
  }
  for (x=1; x<=n; x++) {
    for (y=1; y<=n; y++) if (w[x][y].size()) sort(w[x][y].begin(),w[x][y].end());
    sort(g[x].begin(),g[x].end());
  }
  p[1][0]=q[0]=fr=1;
  while (fi<fr) {
    x=q[fi]; y=e[fi++];
    if (x==n) break;
    for (i=j=0; i<g[x].size(); i++) {
      z=g[x][i];
      while (j<w[x][y].size() && w[x][y][j]<z) j++;
      if (j<w[x][y].size() && w[x][y][j]==z) continue;
      if (p[z][x]==0) {
        p[z][x]=p[x][y]+1;
        f[z][x]=y;
        q[fr]=z;
        e[fr++]=x;
      }
    }
  }
  printf("%d\n",p[n][y]-1);
  if (p[n][y]<=0) return 0;
  for (z=0; y!=0; x=fi) {
    q[z++]=x;
    fi=y;
    y=f[x][y];
  }
  q[z]=x;
  for (i=z; i>=0; i--) {
    printf("%d",q[i]);
    if (i) putchar(' '); else putchar('\n');
  }
  return 0;
}