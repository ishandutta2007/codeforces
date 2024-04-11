#include <stdio.h>
int n,m,k,i,j,p,x,md=1000000007;
long long z,cur,cc,zz,sum,res,f[1010][1010],fc[1000100],fo[1000100],g[1010];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  f[1][1]=1;
  for (i=1; i<=n; i++) for (j=1; j<=i; j++) {
    f[i+1][j]=(f[i+1][j]+f[i][j]*j)%md;
    f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%md;
  }
  fc[0]=fc[1]=fo[0]=fo[1]=1;
  for (i=2; i<=1000010; i++) {
    fc[i]=(fc[i-1]*i)%md;
    fo[i]=pw(fc[i],md-2);
  }
  if (m==1) for (p=1; p<=k && p<=n; p++) {
    res=(res+f[n][p]*((fc[k]*fo[k-p])%md))%md;
  } else for (p=0; p<=k && p<=n; p++) {
    g[0]=0;
    for (i=1; i<=p; i++) g[0]=(g[0]+f[n][i]*((fc[p]*fo[p-i])%md))%md;
    for (i=1, j=2; j<=m; i++, j*=2) g[i]=(g[i-1]*g[i-1])%md;
    cur=(((fc[k]*fo[p])%md)*fo[k-p])%md;
    z=m-2;
    while (i>=0) {
      if (z>=j) {
        z-=j;
        cur=(cur*g[i])%md;
      }
      i--; j/=2;
    }
    for (sum=x=0; p+x+x<=k && p+x<=n; x++) {
      cc=(((fc[k-p]*fo[x])%md)*fo[k-p-x])%md;
      zz=(((fc[k-p-x]*fo[x])%md)*fo[k-p-x-x])%md;
      cc=(cc*zz)%md;
      zz=(f[n][p+x]*fc[p+x])%md;
      sum=(sum+((zz*zz)%md)*cc)%md;
    }
    res=(res+sum*cur)%md;
  }
  printf("%d\n",int(res));
  return 0;
}