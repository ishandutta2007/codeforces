#include <stdio.h>
const int md=1000000007;
int i,j,k,n,x,a[5],C[505][505],f[505][505];
long long c,p[505];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&x); a[x]++; }
  p[0]=1;
  for (i=1; i<=n; i++) p[i]=(p[i-1]*i)%md;
  f[0][0]=1;
  for (i=0; i<=a[2]; i++) {
    C[i][0]=1;
	for (j=1; j<=i; j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%md;
  }
  for (i=0; i<=a[2]; i++) {
    f[i][0]=p[i];
    for (j=1; j<=a[1]; j++) {
	  c=i;
	  f[i][j]=(f[i][j-1]+f[i-1][j]*c)%md;
	  for (k=0; k<=i; k++) {
	    c=(C[i][k]*p[k])%md;
	    if (j>1) f[i][j]=(f[i][j]+((c*(j-1))%md)*f[i-k][j-2])%md;
	  }
    }
  }
  printf("%d\n",f[a[2]][a[1]]);
  return 0;
}