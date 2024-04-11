#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,it,cc,c,d,r,re,T,a[2020],t[111],l[111],w[111],b[2020];
vector <int> g[111],f[111];
bool x[2020];
void dfs(int i, int p, int e) {
  int j,k;
  w[i]=it; l[i]=t[i]=++T;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k==p || x[f[i][j]]) continue;
    if (w[k]!=it) {
      dfs(k,i,e);
      if (l[k]>t[i] && (i!=d || cc>1)) b[f[i][j]]=it;
      l[i]=min(l[i],l[k]);
    } else l[i]=min(l[i],t[k]);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<=m; i++) scanf("%d",&a[i]);
  for (it=m; it>0; it--) {
    c=a[it]; d=a[it-1];
    g[c].push_back(d); f[c].push_back(it);
    g[d].push_back(c); f[d].push_back(it);
    cc=g[d].size(); T=0; dfs(d,0,0); r=1000000;
    for (i=0; i<g[d].size(); i++) if (b[f[d][i]]!=it && g[d][i]>c && g[d][i]<r) { r=g[d][i]; re=f[d][i]; }
    if (r!=1000000) break;
  }
  if (it) {
    for (i=0; i<it; i++) printf("%d ",a[i]);
    for (i=0; i<=n; i++) w[i]=0;
    for (i=0; i<=m; i++) b[i]=0;
    for (; it<m; it++) {
      printf("%d ",r); x[re]=true; d=r;
      for (cc=i=0; i<g[d].size(); i++) if (!x[f[d][i]]) cc++;
      T=0; dfs(d,0,it); r=1000000;
      for (i=0; i<g[d].size(); i++) if (b[f[d][i]]!=it && (!x[f[d][i]]) && g[d][i]<r) { r=g[d][i]; re=f[d][i]; }
    }
    printf("%d\n",r);
  } else puts("No solution");
  return 0;
}