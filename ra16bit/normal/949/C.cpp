#include <bits/stdc++.h>
using namespace std;
int n,m,h,cc,tot,res,i,j,x,y,a[100100],all[100100],c[100100],cnt[100100];
vector<int> g[100100],o[100100];
bool u[100100],w[100100];
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
  all[++tot]=i;
}
void ofs(int i) {
  c[i]=cc;
  cnt[cc]++;
  for (int j=0; j<o[i].size(); j++) if (!c[o[i][j]]) ofs(o[i][j]);
}
int main() {
  scanf("%d%d%d",&n,&m,&h);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  while (m--) {
    scanf("%d%d",&x,&y);
    if ((a[x]+1)%h==a[y]) {
      g[x].push_back(y);
      o[y].push_back(x);
    }
    if ((a[y]+1)%h==a[x]) {
      g[y].push_back(x);
      o[x].push_back(y);
    }
  }
  for (i=1; i<=n; i++) if (!u[i]) dfs(i);
  for (i=tot; i>0; i--) if (!c[all[i]]) {
    ++cc;
    ofs(all[i]);
  }
  for (i=1; i<=n; i++) for (j=0; j<g[i].size(); j++) if (c[i]!=c[g[i][j]]) w[c[i]]=true;
  for (i=1; i<=cc; i++) if (!w[i] && (res==0 || cnt[i]<cnt[res])) res=i;
  printf("%d\n",cnt[res]);
  for (i=1; i<=n; i++) if (c[i]==res) printf("%d ",i);
  return 0;
}