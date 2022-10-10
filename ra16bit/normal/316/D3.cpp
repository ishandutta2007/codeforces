#include <stdio.h>
const int md=1000000007;
int i,j,k,n,x,a[5],f[1000100];
long long c,p[1000100];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&x); a[x]++; }
  p[0]=1;
  for (i=1; i<=n; i++) p[i]=(p[i-1]*i)%md;
/*  f[0][0]=1;
  for (i=0; i<=a[2]; i++) {
    C[i][0]=1;
	for (j=1; j<=i; j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%md;
  }
  for (i=0; i<=a[2]; i++) {
    f[i][0]=p[i];printf("%d ",f[i][0]);
    for (j=1; j<=a[1]; j++) {
	  c=i;
	  f[i][j]=(f[i][j-1]+f[i-1][j]*c)%md;
	  for (k=0; k<=i; k++) {
	    c=(C[i][k]*p[k])%md;
	    if (j>1) f[i][j]=(f[i][j]+((c*(j-1))%md)*f[i-k][j-2])%md;
	  }
	  printf("%d ",f[i][j]);
    }
	puts("");
  }*/
  f[0]=f[1]=1;
  for (i=2; i<=a[1]; i++) f[i]=(f[i-1]+(i-1LL)*f[i-2])%md;
  c=(f[a[1]]*p[a[1]+a[2]])%md;
  c=(c*pw(p[a[1]],md-2))%md;
  printf("%d\n",int(c));
  return 0;
}