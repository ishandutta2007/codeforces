#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,i,j,k,l,x,a[155],f[155][155][155],g[155][155],r[155];
char s[155];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  scanf("%s",s);
  memset(f,255,sizeof(f));
  for (l=0; l<n; l++) for (i=0; i+l<n; i++) {
    j=i+l;
    if (l==0) f[i][j][1]=0;
    g[i][j]=-1;
    for (k=1; k<=l+1; k++) {
      if (s[i]==s[j] && k>1) f[i][j][k]=(k==2?g[i+1][j-1]:f[i+1][j-1][k-2]);
      for (x=i+1; x<=j; x++) {
        if (g[i][x-1]>=0 && f[x][j][k]>=0) f[i][j][k]=max(f[i][j][k],g[i][x-1]+f[x][j][k]);
        if (g[x][j]>=0 && f[i][x-1][k]>=0) f[i][j][k]=max(f[i][j][k],g[x][j]+f[i][x-1][k]);
      }
      if (f[i][j][k]>=0 && a[k]>=0) g[i][j]=max(g[i][j],f[i][j][k]+a[k]);
    }
  }
  for (i=0; i<n; i++) {
    r[i]=max(g[0][i],i?r[i-1]:0);
    for (j=1; j<=i; j++) r[i]=max(r[i],r[j-1]+g[j][i]);
  }
  printf("%d\n",r[n-1]);
  return 0;
}