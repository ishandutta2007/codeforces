#include <cstdio>
#include <vector>
using namespace std;
int n,m,x,y,z,i,j,r,w,T,t[2222],l[2222],c[2222],p[2222],q[2222],fi,fr;
vector <int> g[2222],h[2222];
bool u[2222];
void dfs(int i, int p) {
  int j,k;
  l[i]=t[i]=++T;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k==p) continue;
    if (t[k]==0) {
      dfs(k,i);
      l[i]=min(l[i],l[k]);
    } else l[i]=min(l[i],t[k]);
  }
}
void cdfs(int i, int w) {
  int j,k;
  c[i]=w;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (!c[k]) cdfs(k,(l[k]<=t[i])?w:(++z));
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (t[i]==0) dfs(i,0);
  for (i=1; i<=n; i++) if (c[i]==0) { z++; cdfs(i,z); }
  for (i=1; i<=n; i++) for (x=0; x<g[i].size(); x++) {
    y=c[g[i][x]];
    if (c[i]!=y) h[c[i]].push_back(y);
  }
  for (i=1; i<=z; i++) if (!u[i]) {
    fi=0; fr=1; q[fi]=i; u[i]=true;
    while (fi<fr) {
      x=q[fi++];
      for (j=0; j<h[x].size(); j++) if (!u[h[x][j]]) {
        u[h[x][j]]=true; q[fr++]=h[x][j];
      }
    }
    fi=0; fr=1; q[fi]=x; p[x]=1;
    while (fi<fr) {
      x=q[fi++];
      for (j=0; j<h[x].size(); j++) if (p[h[x][j]]==0) {
        p[h[x][j]]=p[x]+1; q[fr++]=h[x][j];
      }
    }
    if (i==1) r+=p[x]; else r+=p[x]-1;
    if (p[x]>1) w+=2;
  }
  for (i=1; i<=z; i++) if (h[i].size()==1) r++;
  printf("%d\n",n-r+w);
  return 0;
}