#include <bits/stdc++.h>
using namespace std;
const int MX=5050,MX2=MX*2;
int n,m[4],sz[4],i,j,it,x,v[MX],is[MX],f[2][MX2];
vector<int> g[MX],d[4],cmn,cur;
bool q;
void dfs(int i) {
  is[i]=-1;
  if (g[i].empty()) {
    for (int j=0; j<4; j++) if (i==m[j]) is[i]=j;
    v[i]=1;
    return;
  }
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
    if (is[k]!=-1) is[i]=is[k];
    v[i]+=v[k];
  }
  if (is[i]!=-1) for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (is[k]==-1) d[is[i]].push_back(v[k]);
  }
}
bool solve(int m) {
  int last=0;
  f[0][MX]=++it;
  for (int i=0; i<cur.size(); i++) {
    int ii=i&1,i1=1-ii;
    for (int j=0; j<MX2; j++) if (f[ii][j]==it) {
      f[i1][j+cur[i]]=it+1;
      f[i1][j-cur[i]]=it+1;
    }
    last=i1;
    it++;
  }
  return f[last][MX+m]==it;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<4; i++) scanf("%d",&m[i]);
  for (i=2; i<=n; i++) {
    scanf("%d",&x);
    g[x].push_back(i);
  }
  for (j=0; j<g[1].size(); j++) {
    x=g[1][j];
    dfs(x);
    if (is[x]==-1) cmn.push_back(v[x]); else sz[is[x]]=v[x];
  }
  cur=cmn;
  for (j=0; j<d[0].size(); j++) cur.push_back(d[0][j]);
  for (j=0; j<d[1].size(); j++) cur.push_back(d[1][j]);
  q=solve(sz[2]-sz[3]);
  cur=cmn;
  for (j=0; j<d[2].size(); j++) cur.push_back(d[2][j]);
  for (j=0; j<d[3].size(); j++) cur.push_back(d[3][j]);
  q&=solve(sz[0]-sz[1]);
  puts(q?"YES":"NO");
  return 0;
}