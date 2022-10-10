#include <stdio.h>
const int md=1000000007;
int n,m,i,j,r,a[2005][2005],s[2005][2005];
long long f[2005],g[2005];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<m; i++) {
    for (j=1; j<=n; j++) {
      f[j]=(a[i][j-1]+1)%md;
	  g[j]=(a[i-1][j-1]+s[i-1][j-1]+1)%md;
	  s[i][j]=(f[j]+s[i-1][j])%md;
	  a[i][j]=(s[i][j]+a[i-1][j])%md;
	}
	for (j=1; j<=n; j++) r=(r+((f[j]*g[n-j+1])%md)*(m-i))%md;
  }
  printf("%d\n",r);
  return 0;
}