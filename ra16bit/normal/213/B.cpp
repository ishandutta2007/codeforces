#include <stdio.h>
const int md=1000000007;
int i,j,k,n,r,a[11],f[11][111];
long long c[111][111];
int main() {
  scanf("%d",&n);
  for (i=0; i<10; i++) scanf("%d",&a[i]);
  for (i=0; i<=n; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  for (i=a[9]; i<=n; i++) f[9][i]=1;
  for (i=8; i>=1; i--) for (j=a[i]; j<=n; j++) for (k=a[i]; k<=j; k++) f[i][j]=(f[i][j]+c[j][k]*f[i+1][j-k])%md;
  for (j=a[0]; j<=n; j++) for (k=a[0]; k<=j; k++) r=(r+c[j-1][k]*f[1][j-k])%md;
  printf("%d\n",r);
  return 0;
}