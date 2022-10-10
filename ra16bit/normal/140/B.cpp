#include <stdio.h>
int n,i,j,x,y,a[321],b[321][321],c[321],d[321][321];
bool u[321];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) scanf("%d",&b[i][j]);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) {
    u[i]=true; x=-1; y=-1;
    for (j=1; j<=n; j++) if (u[a[j]]) {
      if (x==-1) x=a[j]; else if (y==-1) {
        y=a[j]; break;
      }
    }
    for (j=1; j<=n; j++) if (x==j) d[j][y]=i; else d[j][x]=i;
  }
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) if (d[i][b[i][j]]>0) {
      printf("%d",d[i][b[i][j]]); break;
    }
    if (i==n) puts(""); else printf(" ");
  }
  return 0;
}