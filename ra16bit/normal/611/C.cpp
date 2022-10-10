#include <stdio.h>
int n,m,q,i,j,xa,ya,xb,yb,r,a[505][505],b[505][505];
char s[505][505];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='.') {
    if (i+1<n && s[i+1][j]=='.') a[i+1][j+1]=1;
    if (j+1<m && s[i][j+1]=='.') b[i+1][j+1]=1;
  }
  for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
    a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    r = a[xb-1][yb]-a[xb-1][ya-1]-a[xa-1][yb]+a[xa-1][ya-1];
    r+= b[xb][yb-1]-b[xa-1][yb-1]-b[xb][ya-1]+b[xa-1][ya-1];
    printf("%d\n",r);
  }
  return 0;
}