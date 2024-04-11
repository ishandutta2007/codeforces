#include <stdio.h>
int n,m,i,j,a,b,r,s[55][55];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
    scanf("%d",&s[i][j]);
    s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
  }
  scanf("%d%d",&a,&b); r=a*b;
  for (i=a; i<=n; i++) for (j=b; j<=m; j++)
    if (s[i][j]-s[i-a][j]-s[i][j-b]+s[i-a][j-b]<r) r=s[i][j]-s[i-a][j]-s[i][j-b]+s[i-a][j-b];
  for (i=b; i<=n; i++) for (j=a; j<=m; j++)
    if (s[i][j]-s[i-b][j]-s[i][j-a]+s[i-b][j-a]<r) r=s[i][j]-s[i-b][j]-s[i][j-a]+s[i-b][j-a];
  printf("%d\n",r);
  return 0;
}