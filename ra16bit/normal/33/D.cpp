#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,ii,l,r,h,q,k[1111],R[1111],x[1111],y[1111],xx[1111],yy[1111],e[1111];
vector <int> g[1111];
long long sqr(long long x) { return x*x; }
bool cmp(int i, int j) { return R[i]>R[j]; }
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=0; i<n; i++) scanf("%d%d",&xx[i],&yy[i]);
  for (i=0; i<m; i++) { scanf("%d%d%d",&R[i],&x[i],&y[i]); k[i]=i; }
  sort(k,k+m,cmp);
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (sqr(xx[i]-x[k[j]])+sqr(yy[i]-y[k[j]])<sqr(R[k[j]])) g[i].push_back(j);
  for (i=0; i<n; i++) e[i]=g[i].size();
  for (ii=0; ii<q; ii++) {
    scanf("%d%d",&i,&j); i--; j--;
    if (e[i]==0 || e[j]==0) { printf("%d\n",e[i]+e[j]); continue; }
    if (g[i][0]!=g[j][0]) { printf("%d\n",e[i]+e[j]); continue; }
    if (g[i][e[i]-1]==g[j][e[j]-1]) { puts("0"); continue; }
    l=0; r=min(e[i],e[j])-1;
    if (g[i][r]==g[j][r]) { printf("%d\n",e[i]-r+e[j]-r-2); continue; }
    while (l<r) {
      h=(l+r)/2;
      if (g[i][h]==g[j][h]) l=h+1; else r=h;
    }
    printf("%d\n",e[i]-r+e[j]-r);
  }
  return 0;
}