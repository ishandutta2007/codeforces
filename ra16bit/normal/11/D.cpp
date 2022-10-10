#include <cstdio>
using namespace std;
int n,m,i,j,k,x,y;
bool g[20][20],q;
long long f[600000][20],r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y); x--; y--;
    if (x>y) { k=x; x=y; y=k; }
    g[x][y]=g[y][x]=true;
    f[(1<<x)+(1<<y)][y]++;
  }
  for (i=0; i<(1<<n); i++) {
    q=true;
    for (j=0; j<n; j++) if ((i&(1<<j))!=0 && f[i][j]==0) {
      if (q) { k=j; q=false; continue; }
      for (y=k+1; y<n; y++) if ((i&(1<<y))!=0 && g[y][j]) f[i][j]+=f[i-(1<<j)][y];
      if (g[k][j]) r+=f[i][j];
    }
  }
  printf("%I64d\n",r/2);
  return 0;
}