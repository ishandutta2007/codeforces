#include <stdio.h>
int n,m,q,e,i,j,t[10100],c[10100],a[10100],b[10100],x[10100],y[10100],v[10100],A[102][102];
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=0; i<q; i++) {
    scanf("%d%d",&t[i],&c[i]);
    if (t[i]==3) scanf("%d%d",&a[i],&b[i]);
  }
  for (i=q-1; i>=0; i--) {
    if (t[i]==1) {
      for (j=0; j<e; j++) if (x[j]==c[i]) if (++y[j]>m) y[j]=1;
    } else if (t[i]==2) {
      for (j=0; j<e; j++) if (y[j]==c[i]) if (++x[j]>n) x[j]=1;
    } else {
      x[e]=c[i]; y[e]=a[i]; v[e++]=b[i];
    }
  }
  for (i=0; i<e; i++) A[x[i]][y[i]]=v[i];
  for (i=1; i<=n; i++,puts("")) for (j=1; j<=m; j++) printf("%d ",A[i][j]);
  return 0;
}