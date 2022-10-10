#include <stdio.h>
int n,i,j,k,x,y,g[55][55];
int main() {
  scanf("%d",&n);
  for (i=1; i<(n*(n-1))/2; i++) {
    scanf("%d%d",&x,&y);
    g[x][y]=1; g[y][x]=-1;
  }
  for (i=1; i<=n; i++) for (j=1; j<i; j++) if (g[i][j]==0) {
    x=i; y=j;
    for (k=1; k<=n; k++) if (i!=k && j!=k && g[i][k]==-1 && g[j][k]==1) { x=j; y=i; break; }
    printf("%d %d\n",x,y);
    return 0;
  }
}