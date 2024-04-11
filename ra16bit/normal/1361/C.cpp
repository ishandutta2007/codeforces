#include <bits/stdc++.h>
using namespace std;
const int MX=(1<<20)+5;
int n,N[2],nxt,mn,v,i,le,ri,h,j,vis,it,cur,tot,ans[MX],a[MX],sa[MX],cnt[MX],u[MX],p[MX];
vector<int> g[MX];
bool cmp(int i, int j) { return a[i]<a[j]; }
void dfs(int i) {
  u[i]=it;
  //printf("dfs %d\n",i);
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    int nxt=a[k];
    if (u[nxt]!=it) dfs(nxt);
    ++vis;
  }
}
void wfs(int i) {
  //printf("wfs %d\n",i);
  while (p[i]<g[i].size()) {
    int j=p[i]++;
    int k=g[i][j];
    if (u[k/2]==it) continue;
    u[k/2]=it;
    wfs(a[k]);
    ans[tot++]=k;
    ans[tot++]=k^1;
  }
}
bool solve(int x) {
  int msk=(1<<x)-1;
  for (i=0; i<=msk; i++) g[i].clear();
  for (i=0; i<n; i++) a[i]=(sa[i]&msk);
  for (i=0; i<n; i+=2) {
    g[a[i]].push_back(i^1);
    g[a[i^1]].push_back(i);
  }
  for (i=0; i<=msk; i++) if (g[i].size()&1) break;
  if (i<=msk) return false;
  vis=0; ++it; dfs(a[0]);
  //printf("%d: %d %d\n",x,vis,n);
  return (vis==n);
}
int main() {
  scanf("%d",&n); n*=2;
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    sa[i]=a[i];
  }
  le=0; ri=20;
  while (le<ri) {
    h=(le+ri)/2+1;
    if (solve(h)) le=h; else ri=h-1;
  }
  printf("%d\n",ri);
  solve(ri);
  ++it;
  wfs(a[0]);
  for (i=0; i<tot; i++) printf("%d ",ans[i]+1,a[ans[i]]);
  //prv->fi
  //res+=last
  return 0;
}