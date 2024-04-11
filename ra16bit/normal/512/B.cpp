#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1000000000;
int n,m,ii,i,j,x,cur,r=inf,a[303],c[303],p[14],f[(1<<14)+1];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  for (ii=0; ii<n; ii++) {
    swap(a[ii],a[0]);
    swap(c[ii],c[0]);
    x=a[0]; cur=1; m=0;
    for (i=2; i*i<=x; i++) if (x%i==0) {
      p[m++]=i;
      while (x%i==0) x/=i;
    }
    if (x>1) p[m++]=x;
    f[0]=c[0];
    for (i=1; i<(1<<m); i++) f[i]=inf;
    for (i=1; i<n; i++) {
      for (cur=j=0; j<m; j++) if (a[i]%p[j]) cur|=(1<<j);
      for (j=0; j<(1<<m); j++) if (f[j]<inf) f[j|cur]=min(f[j|cur],f[j]+c[i]);
    }
    r=min(r,f[(1<<m)-1]);
    swap(a[ii],a[0]);
    swap(c[ii],c[0]);
  }
  printf("%d\n",(r==inf)?-1:r);
  return 0;
}