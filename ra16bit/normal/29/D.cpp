#include <stdio.h>
int n,i,j,k,x,y,m,s,g[333][333],v[333],r[3333];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) g[i][j]=1000000000;
    g[i][i]=0;
  }
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x][y]=g[y][x]=1;
    v[x]++; v[y]++;
  }
  for (k=1; k<=n; k++) for (i=1; i<=n; i++) for (j=1; j<=n; j++) if (g[i][k]+g[k][j]<g[i][j]) g[i][j]=g[i][k]+g[k][j];
  for (i=2; i<=n; i++) if (v[i]==1) m++;
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) if (g[i][j]>=1000000000) { puts("-1"); return 0; }
  for (i=x=0,s=1; i<=m; i++) {
    if (i==m) k=1; else scanf("%d",&k);
    if (i==0) r[x++]=s;
    while (g[s][k]>0) for (j=1; j<=300; j++) if (g[s][j]==1 && g[j][k]<g[s][k]) { r[x++]=s=j; break; }
    if (x>=2*n) break;
  }
  if (x==2*n-1) {
    for (i=0; i<x; i++) {
      if (i) putchar(' ');
      printf("%d",r[i]);
    }
  } else puts("-1");
  return 0;
}