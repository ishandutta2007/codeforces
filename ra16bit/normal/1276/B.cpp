#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,it,n,m,i,cc,x,y,a[2],c[2][MX],u[2][MX];
long long ca,cb;
vector<int> g[MX];
void dfs(int i, int e) {
  u[e][i]=it;
  c[e][i]=cc;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (u[e][k]!=it) {
      if (i==a[e]) ++cc;
      dfs(k,e);
    }
  }
}
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d%d%d",&n,&m,&a[0],&a[1]);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=0; i<m; i++) {
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    cc=0; dfs(a[0],0);
    cc=0; dfs(a[1],1);
    ca=cb=0;
    for (i=1; i<=n; i++) if (i!=a[0] && i!=a[1]) {
      if (c[0][i]!=c[0][a[1]]) ++ca;
      if (c[1][i]!=c[1][a[0]]) ++cb;
    }
    printf("%I64d\n",ca*cb);
  }
  return 0;
}