#include <bits/stdc++.h>
using namespace std;
const int MX=202,inf=100000000;
int n,m,i,j,x,y,z,mnx,cc,w,it,best,c[MX],d[MX],p[MX],g[MX][MX],dst[MX],dcc[MX],was[MX];
vector<int> v[MX],q,nq,G[MX],gz[MX];
bool check(int i, int x) {
  p[i]=x;
  for (int j=1; j<=n; j++) if (g[i][j]>=0) {
    if (p[j]>0) {
      if (p[i]==p[j]) return false;
    } else if (!check(j,3-x)) return false;
  }
  return true;
}
void dfs(int i, int diff) {
  c[i]=cc;
  d[i]=diff;
  v[cc].push_back(i);
  for (int j=1; j<=n; j++) if (g[i][j]>0 && c[j]==0) dfs(j,diff+((g[i][j]==j)?-1:1));
}
bool solve(int st) {
  for (int i=1; i<=n; i++) dst[i]=inf;
  dst[v[st][0]]=0;
  q.clear();
  q.push_back(v[st][0]);
  int cnt=0;
  for (cnt=0; cnt<=n; cnt++) {
    nq.clear();
    for (int i: q) {
      ++it;
      for (int j=0; j<G[i].size(); j++) {
        int y=G[i][j],z=gz[i][j];
        if (z==0 || z==i) {
          if (dst[y]>dst[i]+1) {
            dst[y]=dst[i]+1;
            if (was[y]!=it) {
              was[y]=it;
              nq.push_back(y);
            }
          }
        } else if (z==y) {
          if (dst[y]>dst[i]-1) {
            dst[y]=dst[i]-1;
            if (was[y]!=it) {
              was[y]=it;
              nq.push_back(y);
            }
          }
        }
      }
    }
    if (nq.empty()) break;
    swap(q,nq);
  }
  if (cnt>n) return false;
  int mn=0,mx=0;
  for (int i=1; i<=n; i++) {
    if (dst[i]>=inf) return false;
    mn=min(mn,dst[i]);
    mx=max(mx,dst[i]);
    for (int j=0; j<G[i].size(); j++) {
      int y=G[i][j],z=gz[i][j];
      if (z==0) {
        if (dst[y]!=dst[i]+1 && dst[i]!=dst[y]+1) return false;
      } else if (z==i) {
        if (dst[y]!=dst[i]+1) return false;
      } else if (z==j) {
        if (dst[i]!=dst[y]+1) return false;
      }
    }
  }
  if (best==-1 || mx-mn>best) { best=mx-mn; mnx=mn; w=st; }
  return true;
}
int main() {
  scanf("%d%d",&n,&m);
  memset(g,255,sizeof(g));
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    G[x].push_back(y);
    G[y].push_back(x);
    if (z==0) {
      g[x][y]=g[y][x]=0; 
      gz[x].push_back(0);
      gz[y].push_back(0);
    } else {
      g[x][y]=g[y][x]=x;
      gz[x].push_back(x);
      gz[y].push_back(x);
    }
  }
  if (!check(1,1)) { puts("NO"); return 0; }
  for (i=1; i<=n; i++) if (c[i]==0) {
    ++cc; dfs(i,0);
  }
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) if (g[i][j]>=0 && c[i]==c[j]) {
    if (g[i][j]==i) {
      if (d[i]+1!=d[j]) { puts("NO"); return 0; }
    } else if (g[i][j]==j) {
      if (d[j]+1!=d[i]) { puts("NO"); return 0; }
    } else {
      if (d[i]+1!=d[j] && d[j]+1!=d[i]) { puts("NO"); return 0; }
    }
  }
  best=-1;
  for (i=1; i<=cc; i++) solve(i);
  if (best==-1) { puts("NO"); return 0; }
  puts("YES");
  printf("%d\n",best);
  solve(w);
  for (i=1; i<=n; i++) printf("%d ",dst[i]-mnx);
  return 0;
}