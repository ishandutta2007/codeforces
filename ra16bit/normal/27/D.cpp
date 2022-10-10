#include <stdio.h>
int i,j,n,m,x[111],y[111],z[111];
bool g[111][111],q;
void dfs(int i, int c) {
  if (z[i]!=0) {
    if (z[i]!=c) q=true;
    return;
  }
  z[i]=c;
  for (int j=0; j<m; j++) if (g[i][j]) dfs(j,3-c);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x[i],&y[i]);
    if (x[i]>y[i]) { j=x[i]; x[i]=y[i]; y[i]=j; }
    for (j=0; j<i; j++) if (z[j]==z[i] && ((x[j]<x[i] && y[j]>x[i] && y[j]<y[i]) || (y[j]>y[i] && x[j]>x[i] && x[j]<y[i]))) g[i][j]=g[j][i]=true;
  }
  for (i=0; i<m; i++) if (z[i]==0) dfs(i,1);
  if (!q) {
    for (i=0; i<m; i++) if (z[i]==1) putchar('o'); else putchar('i');
  } else puts("Impossible");
  return 0;
}