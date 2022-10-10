#include <stdio.h>
int n,m,p,i,j,b,z,a[1000010],d[5005][5005],f[10000010],g[1000010];
long long fc[5005],c[5005],e;
int main() {
  scanf("%d%d%d",&n,&m,&p);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  fc[0]=c[0]=d[1][1]=1;
  for (i=1; i<=5000 && i<=m; i++) { 
    fc[i]=(fc[i-1]*i)%p;
    c[i]=(c[i-1]*(m-i+1))%p;
  }
  for (i=1; i<5000; i++) for (j=1; j<=i; j++) if (d[i][j]) {
    d[i+1][j]=(d[i+1][j]+d[i][j]*(j-1LL))%p;
    d[i+1][j+1]+=d[i][j];
    if (d[i+1][j+1]>=p) d[i+1][j+1]-=p;
  }
  f[0]=1; g[0]=1;
  for (i=1; i<=n; b+=a[i++]) {
    for (j=1; j<=a[i] && j<=m; j++) {
      e=g[i-1]-((z+j<=b && f[z+j]>0)?(f[z+j]*fc[j])%p:0);
      if (e<0) e+=p;
      f[b+j]=(d[a[i]][j]*e)%p;
      g[i]=(g[i]+f[b+j]*c[j])%p;
    }
    z=b;
  }
  printf("%d\n",g[n]);
  return 0;
}