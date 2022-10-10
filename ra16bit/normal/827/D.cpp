#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=200200;
int n,m,fr,T,i,mem[MX],x[MX],y[MX],z[MX],c[MX],d[MX],u[MX],r[MX],p[MX],rk[MX],k[MX],pr[MX][19],mr[MX][19];
vector<int> g[MX],f[MX];
bool w[MX];
priority_queue<pii,vector<pii>,greater<pii>> q[MX];
void dfs(int i, int p, int pw, int dep) {
  d[i]=dep; u[i]=++T;
  pr[i][0]=p;
  mr[i][0]=pw;
  for (int e=1; e<19; e++) {
    pr[i][e]=pr[pr[i][e-1]][e-1];
    mr[i][e]=max(mr[i][e-1],mr[pr[i][e-1]][e-1]);
  }
  int mx=-1,wk;
  for (int j=0; j<g[i].size(); j++) if (w[f[i][j]]) {
    int k=g[i][j];
    if (!u[k]) {
      dfs(k,i,z[f[i][j]],dep+1);
      while (!q[c[k]].empty() && u[q[c[k]].top().second]>=u[k]) q[c[k]].pop();
      r[f[i][j]]=q[c[k]].empty()?-1:(q[c[k]].top().first-1);
      if (int(q[c[k]].size())>mx) { mx=q[c[k]].size(); c[i]=c[k]; wk=k; }
    }
  }
  if (mx==-1) c[i]=mem[fr++];
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (u[k]>=u[i]) {
      if (c[k]!=c[i] && c[k]!=-1) {
        while (!q[c[k]].empty()) {
          q[c[i]].push(q[c[k]].top());
          q[c[k]].pop();
        }
        mem[--fr]=c[k];
        c[k]=-1;
      }
    } else if (k!=p) q[c[i]].push({z[f[i][j]],k});
  }
  if (mx!=-1) c[wk]=-1;
}
int mxedge(int x, int y) {
  if (d[x]<d[y]) swap(x,y);
  int r=0;
  for (int i=18; i>=0; i--) if (d[x]-(1<<i)>=d[y]) {
    r=max(r,mr[x][i]); x=pr[x][i];
  }
  for (int i=18; i>=0; i--) if (pr[x][i]!=pr[y][i]) {
    r=max(r,mr[x][i]); x=pr[x][i];
    r=max(r,mr[y][i]); y=pr[y][i];
  }
  if (x!=y) {
    r=max(r,mr[x][0]);
    r=max(r,mr[y][0]);
  }
  return r;
}
int fs(int x) {
  if (p[x]!=x) p[x]=fs(p[x]);
  return p[x];
}
void un(int ed) {
  int X=fs(x[ed]);
  int Y=fs(y[ed]);
  if (X==Y) return;
  w[ed]=true;
  if (rk[X]>=rk[Y]) {
    p[Y]=X;
    if (rk[X]==rk[Y]) rk[X]++;
  } else p[X]=Y;
}
bool cmp(int i, int j) { return z[i]<z[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    g[x[i]].push_back(y[i]); f[x[i]].push_back(i);
    g[y[i]].push_back(x[i]); f[y[i]].push_back(i);
    k[i]=i;
  }
  sort(k,k+m,cmp);
  for (i=1; i<=n; i++) { p[i]=i; mem[i]=i; }
  for (i=0; i<m; i++) { un(k[i]); r[i]=-2; }
  dfs(1,0,0,0);
  for (i=0; i<m; i++) printf("%d ",(r[i]==-2)?mxedge(x[i],y[i])-1:r[i]);
  return 0;
}