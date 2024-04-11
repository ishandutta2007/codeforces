#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,cc,x,y,i,T,j,r,cur,best,cs,t[2002],low[2002],c[2002],sum[2002],cnt[2002],f[2002][2002];
vector<int> g[2002],h[2002];
bool b[2002][2002],hg[2002][2002];
void bridges(int i, int p) {
  low[i]=t[i]=++T;
  for (size_t j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    if (t[k]==0) {
      bridges(k,i);
      if (low[k]>t[i]) b[i][k]=b[k][i]=true; else low[i]=min(low[i],low[k]);
    } else low[i]=min(low[i],t[k]);
  }
}
void color(int i) {
  c[i]=cc; cnt[cc]++;
  for (size_t j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (!b[i][k]) {
      if (c[k]==0) color(k);
    } else if (c[k]!=0) {
      hg[cc][c[k]]=true;
      hg[c[k]][cc]=true;
    }
  }
}
void dfs(int i, int p) {
  sum[i]=0;
  for (size_t j=0; j<h[i].size(); j++) {
    int k=h[i][j];
    if (k==p) continue;
    dfs(k,i);
    sum[i]+=sum[k];
    cur+=cnt[i]*sum[k];
  }
  sum[i]+=cnt[i];
}
int main() {
  scanf("%d%d",&n,&m);
  while (m--) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bridges(1,0);
  for (i=1; i<=n; i++) if (c[i]==0) { ++cc; color(i); }
  for (i=1; i<=cc; i++) {
    for (j=1; j<=cc; j++) if (hg[i][j]) h[i].push_back(j);
    r+=cnt[i]*cnt[i];
  }
  //for (i=1; i<=n; i++) printf("%d, ",c[i]); puts("c");
  //for (i=1; i<=cc; i++) printf("%d, ",cnt[i]); puts("cnt");
  for (i=1; i<=cc; i++) {
    f[0][0]=i;
    int prev=0,cs=cur=0;
    dfs(i,0);
    for (j=0; j<h[i].size(); j++) {
      int k=h[i][j];
      for (int e=cs; e>=0; e--) if (f[prev][e]==i) {
        f[k][e+sum[k]]=i;
        f[k][e]=i;
      }
      cs+=sum[k];
      prev=k;
    }
    for (int e=cs; e>=0; e--) if (f[prev][e]==i && cur+e*(cs-e)>best) best=cur+e*(cs-e);
  }
  printf("%d\n",r+best);
  return 0;
}