#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,m,r=100,i,j,k,p,mx,bc[77],w[77],f[42][77][77];
int main() {
  scanf("%d%d",&n,&m);
  if (n>m) swap(n,m);
  if (m==1) { puts("0"); return 0; }
  memset(f,120,sizeof(f));
  mx=(1<<n)-1;
  for (i=1; i<=mx; i++) {
    bc[i]=bc[i/2]+(i&1);
    for (j=0; j<n; j++) {
      p=0;
      if (i&(1<<j)) p=1;
      if (j>0 && (i&(1<<(j-1)))) p=1;
      if (j<n-1 && (i&(1<<(j+1)))) p=1;
      if (p) w[i]|=1<<j;
    }
  }
  f[0][mx][0]=0;
  for (p=0; p<=m; p++) for (i=0; i<=mx; i++) for (j=0; j<=mx; j++) if (f[p][i][j]<100) 
    for (k=0; k<=mx; k++) if ((i|k)==mx) f[p+1][j|w[k]][k]=min(f[p+1][j|w[k]][k],f[p][i][j]+bc[k]);
  for (i=0; i<=mx; i++) if (f[m][mx][i]<r) r=f[m][mx][i];
  printf("%d\n",n*m-r);
  return 0;
}