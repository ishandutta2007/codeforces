#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,it,n,cur,i,ii,num,mx,f[MX],u[MX],vis[MX],a[MX];
vector<int> g[MX];
void dfs(int i) {
  u[i]=it;
  for (int j: g[i]) if (u[j]!=it) dfs(j);
  a[num++]=i;
}
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
      scanf("%d",&cur);
      g[i].resize(cur);
      for (int j=0; j<cur; j++) scanf("%d",&g[i][j]);
    }
    num=0;
    for (i=1; i<=n; i++) if (u[i]!=it) dfs(i);
    bool ok=true;
    for (mx=ii=0; ii<num; ii++) {
      i=a[ii];
      f[i]=0;
      for (int x: g[i]) {
        if (vis[x]!=it) { ok=false; break; }
        f[i]=max(f[i],f[x]+int(x>i));
      }
      if (!ok) break;
      mx=max(mx,f[i]);
      vis[i]=it;
    }
    printf("%d\n",ok?mx+1:-1);
  }
  return 0;
}