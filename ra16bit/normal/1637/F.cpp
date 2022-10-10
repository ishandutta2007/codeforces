#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int n,i,x,y,rt,a[MX],mx[MX],mx2[MX],w[MX],w2[MX];
vector<int> g[MX];
long long res;
void dfs(int i, int p) {
  mx[i]=mx2[i]=0;
  for (int j: g[i]) if (j!=p) {
    dfs(j,i);
    int v=max(mx[j],a[j]);
    if (v>mx[i]) {
      mx2[i]=mx[i];
      w2[i]=w[i];
      mx[i]=v;
      w[i]=j;
    } else if (v>mx2[i]) {
      mx2[i]=v;
      w2[i]=j;
    }
  }
}
void solve(int i, int p, int v) {
  if (g[i].size()==1) { res+=v; return; }
  for (int j: g[i]) if (j!=p) {
    if (j==w[i]) solve(j,i,max(v,a[j])); else solve(j,i,a[j]);
  }
}
int main() {
  scanf("%d",&n);
  for (rt=i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (a[i]>a[rt]) rt=i;
  }
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(rt,0);
  for (int j: g[rt]) if (j==w[rt] || j==w2[rt]) solve(j,rt,a[rt]); else solve(j,rt,a[j]);
  if (g[rt].size()==1) res+=a[rt];
  printf("%lld\n",res);
  return 0;
}