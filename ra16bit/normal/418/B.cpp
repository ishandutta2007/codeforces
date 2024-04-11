#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,m,b,k[102],c[102],mask[102],i,j,x,aa,ii,i1;
long long a[102],f[2][1100100],r,inf;
bool cmp(int i, int j) {
  return a[i]>a[j];
}
int main() {
  scanf("%d%d%d",&n,&m,&b);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&c[i],&aa,&j);
    a[i]=aa; a[i]*=b;
    while (j--) {
      scanf("%d",&x);
      mask[i]|=1<<(x-1);
    }
    k[i]=i;
  }
  sort(k,k+n,cmp);
  memset(f,120,sizeof(f));
  inf=f[0][0];
  f[0][0]=0;
  for (x=0; x<n; x++) {
    i=k[x]; ii=x&1; i1=1-ii;
    memset(f[i1],120,sizeof(f[i1]));
    for (j=0; j<(1<<m); j++) if (f[ii][j]<inf) {
      f[i1][j]=min(f[i1][j],f[ii][j]);
      f[i1][j|mask[i]]=min(f[i1][j|mask[i]],f[ii][j]+c[i]+(j==0)*a[i]);
    }
  }
  if (f[n&1][(1<<m)-1]<inf) printf("%I64d\n",f[n&1][(1<<m)-1]); else puts("-1");
  return 0;
}