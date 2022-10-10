#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,i,j,best,ctm,t[MX],x[MX],y[MX],f[MX],mx[MX];
int main() {
  scanf("%d%d",&n,&m);
  x[0]=y[0]=1;
  for (i=1; i<=m; i++) {
    scanf("%d%d%d",&t[i],&x[i],&y[i]);
    best=-1;
    for (j=i-1; j>=0; j--) {
      ctm=t[i]-t[j];
      if (ctm>2*n) break; 
      if (best<f[j] && ctm>=abs(x[i]-x[j])+abs(y[i]-y[j])) {
        best=f[j];
      }
    }
    if (j>=0) best=max(best,mx[j]);
    f[i]=best;
    if (best>=0) ++f[i];
    mx[i]=max(mx[i-1],f[i]);
  }
  printf("%d\n",mx[m]);
  return 0;
}