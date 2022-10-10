#include <stdio.h>
#include <memory.h>
long long l,r,p,f[20][50][2520][2];
int i,j,jx,k,kx,kk,n,t,it,e,z,a[20],nx[2520][10],g[52],o[2520];
short u[20][50][2520][2];
int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
long long solve(long long x) {
  if (x==0) return 1; else ++it;
  for (n=1; x>0; n++, x/=10) a[n]=x%10;
  u[--n][1][0][1]=it;
  f[n][1][0][1]=1;
  for (i=n; i>0; i--) for (j=1; j<=e; j++) for (jx=0; jx<2520; jx++) {
    if (u[i][j][jx][0]==it) {
      p=f[i][j][jx][0];
      for (k=0; k<10; k++) {
        kx=nx[jx][k];
        if (k<2) kk=j; else kk=o[(g[j]*k)/gcd(g[j],k)];
        if (u[i-1][kk][kx][0]!=it) {
          u[i-1][kk][kx][0]=it;
          f[i-1][kk][kx][0]=p;
        } else f[i-1][kk][kx][0]+=p;
      }
    }
    if (u[i][j][jx][1]==it) {
      p=f[i][j][jx][1];
      for (k=0; k<a[i]; k++) {
        kx=nx[jx][k];
        if (k<2) kk=j; else kk=o[(g[j]*k)/gcd(g[j],k)];
        if (u[i-1][kk][kx][0]!=it) {
          u[i-1][kk][kx][0]=it;
          f[i-1][kk][kx][0]=p;
        } else f[i-1][kk][kx][0]+=p;
      }
      kx=nx[jx][k];
      if (k<2) kk=j; else kk=o[(g[j]*k)/gcd(g[j],k)];
      if (u[i-1][kk][kx][1]!=it) {
        u[i-1][kk][kx][1]=it;
        f[i-1][kk][kx][1]=p;
      } else f[i-1][kk][kx][1]+=p;
    }
  }
  long long r=0;
  for (j=1; j<=e; j++) for (jx=0; jx<2520; jx+=g[j]) for (k=0; k<2; k++) if (u[0][j][jx][k]==it) r+=f[0][j][jx][k];
  return r;
}
int main() {
  for (i=0; i<2520; i++) for (j=0; j<10; j++) nx[i][j]=(i*10+j)%2520;
  e=1; g[1]=1; o[1]=1;
  for (i=0; i<256; i++) {
    z=1;
    for (j=0; j<8; j++) if (i&(1<<j)) z=(z*(j+2))/gcd(z,j+2);
    if (o[z]==0) { o[z]=++e; g[e]=z; }
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%I64d%I64d",&l,&r);
    printf("%I64d\n",solve(r)-solve(l-1));
  }
  return 0;
}