#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,q,i,j,cc,qx,qy,qz,ans[MX],c[MX],d[MX],x[MX],y[MX],z[MX],bz[MX];
vector<int> g[MX],h[MX],w[MX];
bool ok;
void dfs(int i, int p, int tot, int cur) {
  c[i]=cur;
  d[i]=tot;
  for (int ed: g[i]) {
    int nxt=(x[ed]^y[ed]^i);
    if (nxt==p) continue;
    if (z[ed]==-1) {
      ++cc;
      dfs(nxt,i,0,cc);
    } else dfs(nxt,i,(tot^bz[ed]),cur);
  }
}
void hfs(int i, int col) {
  if (ans[i]!=-1) {
    if (ans[i]!=col) ok=false;
    return;
  }
  ans[i]=col;
  for (int j=0; j<h[i].size(); j++) {
    hfs(h[i][j],(col^w[i][j]));
    if (!ok) return;
  }
}
void addedge(int i, int j, int z) {
  h[i].push_back(j); w[i].push_back(z);
  h[j].push_back(i); w[j].push_back(z);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&q);
    for (i=1; i<=n; i++) {
      g[i].clear();
      h[i].clear();
      w[i].clear();
      ans[i]=-1;
    }
    for (i=1; i<n; i++) {
      scanf("%d%d%d",&x[i],&y[i],&z[i]);
      g[x[i]].push_back(i);
      g[y[i]].push_back(i);
      bz[i]=0;
      if (z[i]!=-1) for (j=0; j<30; j++) bz[i]^=((z[i]>>j)&1);
    }
    cc=1;
    dfs(1,0,0,1);
    ok=true;
    for (i=0; i<q; i++) {
      scanf("%d%d%d",&qx,&qy,&qz);
      if (c[qx]==c[qy]) {
        if ((d[qx]^d[qy])!=qz) ok=false;
      } else addedge(c[qx],c[qy],(d[qx]^d[qy]^qz));
    }
    for (i=1; i<=cc; i++) if (ok && ans[i]==-1) hfs(i,0);
    if (ok) {
      puts("YES");
      for (i=1; i<n; i++) {
        if (z[i]==-1) z[i]=(ans[c[x[i]]]^ans[c[y[i]]]^d[x[i]]^d[y[i]]);
        printf("%d %d %d\n",x[i],y[i],z[i]);
      }
    } else puts("NO");
  }
  return 0;
}