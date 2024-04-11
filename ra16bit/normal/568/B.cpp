#include <stdio.h>
const int md=1000000007;
int n,i,j,k,f[4040][4040];
long long c[4040][4040];
int main() {
  scanf("%d",&n);
  for (i=0; i<=n; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  f[0][0]=1;
  for (i=1; i<=n; i++) {
    f[i][0]=f[i-1][0];
    f[i][1]=(f[i-1][0]+2LL*f[i-1][1])%md;
    for (j=2; j<=i; j++) for (k=0; k<2; k++) f[i][k]=(f[i][k]+c[i-1][j-1]*f[i-j][k])%md;
  }
  printf("%d\n",f[n][1]);
  return 0;
}