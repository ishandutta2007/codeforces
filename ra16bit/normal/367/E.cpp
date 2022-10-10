#include <stdio.h>
const int md=1000000007;
int n,m,x,i,ii,i1,j,k,f[2][320][320];
long long fa;
int main() {
  scanf("%d%d%d",&m,&n,&x);
  if (n<m) { puts("0"); return 0; }
  f[0][0][0]=1;
  for (i=0; i<n; i++) {
    ii=i&1; i1=1-ii;
    for (j=0; j<=m; j++) for (k=0; k<=j; k++) f[i1][j][k]=0;
    for (j=0; j<=m; j++) for (k=0; k<=j; k++) if (f[ii][j][k]) {
      if (i!=x-1) {
        f[i1][j][k]=(f[i1][j][k]+f[ii][j][k])%md;
        if (k>0) f[i1][j][k-1]=(f[i1][j][k-1]+f[ii][j][k])%md;
      }
      if (j<m) {
        f[i1][j+1][k+1]=(f[i1][j+1][k+1]+f[ii][j][k])%md;
        f[i1][j+1][k]=(f[i1][j+1][k]+f[ii][j][k])%md;
      }
    }
  }
  for (fa=i=1; i<=m; i++) fa=(fa*i)%md;
  printf("%I64d\n",(f[n&1][m][0]*fa)%md);
  return 0;
}