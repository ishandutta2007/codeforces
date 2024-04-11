#include <bits/stdc++.h>
using namespace std;
const int inf=2000000000;
int n,e,iter,i,x,y,w,S,T,q[2020],pe[2020],u[2020],t[12012],f[12012];
long long tot;
map<pair<int,int>, int> m;
vector<int> g[2020];
void addedge(int fr, int to, int w) {
  g[fr].push_back(e); t[e]=to; f[e++]=w;
  g[to].push_back(e); t[e]=fr; f[e++]=0;
}
bool bfs() {
  int fi=0,fr=1;
  u[S]=++iter;
  q[fi]=S;
  while (fi<fr) {
    int x=q[fi++];
    for (int ed: g[x]) if (f[ed]>0) {
      int y=t[ed];
      if (u[y]!=iter) {
        pe[y]=ed;
        u[y]=iter;
        q[fr++]=y;
      }
    }
  }
  return u[T]==iter;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&x,&y,&w);
    m[{x,y}]=i;
    addedge(i,n+i,w);
    tot+=w;
  }
  S=2*n; T=S+1;
  for (auto it=m.begin(); it!=m.end(); it++) {
    x=it->first.first;
    y=it->first.second;
    i=it->second;
    if (x&1) {
      if (y&1) addedge(n+i,T,inf); else {
        addedge(S,i,inf);
        auto oth=m.find({x-1,y});
        if (oth!=m.end()) addedge(n+i,oth->second,inf);
        oth=m.find({x+1,y});
        if (oth!=m.end()) addedge(n+i,oth->second,inf);
      }
    } else if (y&1) {
      auto oth=m.find({x-1,y});
      if (oth!=m.end()) addedge(n+i,oth->second,inf);
      oth=m.find({x+1,y});
      if (oth!=m.end()) addedge(n+i,oth->second,inf);
    } else {
      auto oth=m.find({x,y-1});
      if (oth!=m.end()) addedge(n+i,oth->second,inf);
      oth=m.find({x,y+1});
      if (oth!=m.end()) addedge(n+i,oth->second,inf);
    }
  }
  while (bfs()) {
    w=inf;
    for (i=T; i!=S; i=t[pe[i]^1]) w=min(w,f[pe[i]]);
    tot-=w;
    for (i=T; i!=S; i=t[pe[i]^1]) {
      f[pe[i]]-=w;
      f[pe[i]^1]+=w;
    }
  }
  printf("%lld\n",tot);
  return 0;
}