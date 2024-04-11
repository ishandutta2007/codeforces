#include <stdio.h>
int n,m,a,i,j,li,lj;
long long s[1010],c[1010],rs[1010],rc[1010],r;
long long sqr(long long x) { return x*x; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a);
    s[i]+=a;
    c[j]+=a;
  }
  for (i=0; i<n; i++) for (j=0; j<=n; j++) rs[j]+=s[i]*sqr(i*4+2-j*4);
  for (i=0; i<m; i++) for (j=0; j<=m; j++) rc[j]+=c[i]*sqr(i*4+2-j*4);
  for (i=0; i<=n; i++) for (j=0; j<=m; j++) if (rs[i]+rc[j]<r || (i==0 && j==0)) {
    r=rs[i]+rc[j];
    li=i; lj=j;
  }
  printf("%I64d\n%d %d\n",r,li,lj);
  return 0;
}