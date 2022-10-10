#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,n,l,r,h,xx[100100],yy[100100],k[100100],f[100100],s[100100];
long long x[100100],y[100100],nx[100100],ny[100100],v;
bool cmp(int i, int j) { return x[i]<x[j] || (x[i]==x[j] && y[i]<y[j]); }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&xx[i],&yy[i]);
  scanf("%I64d",&v);
  for (i=0; i<n; i++) {
    nx[i]=x[i]=-xx[i]-v*yy[i];
    ny[i]=y[i]=xx[i]-v*yy[i];
  }
  sort(nx,nx+n+1);
  sort(ny,ny+n+1);
  for (i=0; i<=n; i++) {
    l=0; r=n;
    while (l<r) {
      h=(l+r)/2;
      if (x[i]>nx[h]) l=h+1; else r=h;
    }
    x[i]=r+1; l=0; r=n;
    while (l<r) {
      h=(l+r)/2;
      if (y[i]>ny[h]) l=h+1; else r=h;
    }
    y[i]=r+1; k[i]=i;
  }
  sort(k,k+n+1,cmp);
  for (r=i=0; i<=n; i++) {
    for (j=y[k[i]]; j>0; j&=j-1) f[i]=max(f[i],s[j]);
    if (k[i]!=n) {
      if (++f[i]>r) r=f[i];
      for (j=y[k[i]]; j<=n+10; j=(j<<1)-(j&(j-1))) s[j]=max(s[j],f[i]);
    } else l=f[i];
  }
  printf("%d %d\n",l,r);
  return 0;
}