#include <stdio.h>
int ii,i,j,k,n,md,a[1000100],e[2][2];
long long x,y,s,f[2][2],b[2][2];
void mul(long long x) {
  for (i=0; i<2; i++) for (j=0; j<2; j++) f[i][j]=int(i==j);
  for (ii=62; ii>=0; ii--) {
    for (i=0; i<2; i++) for (j=0; j<2; j++) {
      b[i][j]=0;
      for (k=0; k<2; k++) b[i][j]=(b[i][j]+f[i][k]*f[k][j])%md;
    }
    if (x&(1LL<<ii)) {
      for (i=0; i<2; i++) for (j=0; j<2; j++) {
        f[i][j]=0;
        for (k=0; k<2; k++) f[i][j]=(f[i][j]+b[i][k]*e[k][j])%md;
      }
    } else for (i=0; i<2; i++) for (j=0; j<2; j++) f[i][j]=b[i][j];
  }
}
void findsum() {
  s=((s%md)*f[1][1])%md;
  s-=(a[0]*f[0][1])%md;
  if (s<0) s+=md;
  s-=(a[n-1]*f[0][1])%md;
  if (s<0) s+=md;
}
int main() {
  scanf("%d%I64d%I64d%d",&n,&x,&y,&md);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); s+=a[i]; }
  if (n==1) { printf("%d\n",a[0]%md); return 0; }
  e[0][0]=e[0][1]=1; e[1][0]=0; e[1][1]=3; mul(x);
  findsum();
  e[0][0]=0; e[0][1]=e[1][0]=e[1][1]=1; mul(x);
  a[n-1]=(f[1][0]*a[n-2]+f[1][1]*a[n-1])%md;
  e[0][0]=e[0][1]=1; e[1][0]=0; e[1][1]=3; mul(y);
  findsum();
  printf("%d\n",int(s%md));
  return 0;
}