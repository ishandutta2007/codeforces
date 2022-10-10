#include <bits/stdc++.h>
using namespace std;
int n,k,m,x,y,z,i,ii,i1,j,w,le,ri,e,r,inf,f[2][82][82][82];
vector<int> g[82],v[82];
int main() {
  scanf("%d%d%d",&n,&k,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y);
    v[x].push_back(z);
  }
  memset(f,100,sizeof(f));
  r=inf=f[0][0][0][0];
  for (i=1; i<=n; i++) f[0][1][n][i]=0;
  for (i=0; i<k-1; i++) {
    ii=i&1; i1=1-ii;
    memset(f[i1],100,sizeof(f[i1]));
    for (le=1; le<=n; le++) for (ri=le; ri<=n; ri++) for (e=le; e<=ri; e++) if (f[ii][le][ri][e]<r) {
      for (j=0; j<g[e].size(); j++) {
        w=g[e][j];
        if (w>=le && w<=ri) {
          if (w<e) {
            f[i1][le][e-1][w]=min(f[i1][le][e-1][w],f[ii][le][ri][e]+v[e][j]);
          } else if (w>e) {
            f[i1][e+1][ri][w]=min(f[i1][e+1][ri][w],f[ii][le][ri][e]+v[e][j]);
          }
        }
      }
    }
  }
  for (le=1; le<=n; le++) for (ri=le; ri<=n; ri++) for (e=le; e<=ri; e++) r=min(r,f[(k-1)&1][le][ri][e]);
  if (r==inf) puts("-1"); else printf("%d\n",r);
  return 0;
}