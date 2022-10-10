#include <cstdio>
using namespace std;
int n,m,i,j,k,l,x,y,g[777][777][3];
long long r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    x--; y--;
    g[x][y][0]=1;
    g[y][x][0]=1;
  }
  for (l=0; l<2; l++) for (i=0; i<n; i++) for (j=0; j<n; j++) if (g[i][j][l]) for (k=0; k<n; k++) if (g[j][k][0]) g[i][k][l+1]+=g[i][j][l];
  for (i=0; i<n; i++) for (j=i+1; j<n; j++) for (k=0; k<n; k++) if (g[i][k][0] && g[j][k][0] && g[i][j][2]) {
    r+=g[i][j][2]-g[i][k][1]-g[j][k][1];
    if (g[i][j][0]) r-=g[i][i][1]+g[j][j][1]-3;
  }
  printf("%I64d\n",r/5);
  return 0;
}