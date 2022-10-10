#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=2000200200;
int n,m,T,sx,tx,xx,yy,i,j,ii,it,u[1010],p[1010],rk[1010],f[1010],t[1010],l[1010],x[30300],y[30300],c[30300],k[30300],r=inf,sz,e0,e1;
vector<int> g[30300],e[30300];
bool cmp(int i, int j) { return c[i]<c[j]; }
int fs(int i) {
  if (i!=p[i]) p[i]=fs(p[i]);
  return p[i];
}
bool un(int x, int y) {
  if (x==y) return false;
  if (rk[x]<rk[y]) p[x]=y; else {
    p[y]=x;
    if (rk[x]==rk[y]) rk[x]++;
  }
  return true;
}
void dfs(int i, int pe, int b) {
  u[i]=it; l[i]=t[i]=++T;
  for (int j=0; j<g[i].size(); j++) {
    int ed=e[i][j];
    if (ed==pe || ed==b) continue;
    int k=g[i][j];
    if (u[k]!=it) {
      dfs(k,ed,b);
      l[i]=min(l[i],l[k]);
    } else l[i]=min(l[i],t[k]);
  }
  f[i]=T;
}
int main() {
  scanf("%d%d",&n,&m);
  scanf("%d%d",&sx,&tx);
  for (i=1; i<=n; i++) p[i]=i;
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x[i],&y[i],&c[i]);
    g[x[i]].push_back(y[i]); e[x[i]].push_back(i);
    g[y[i]].push_back(x[i]); e[y[i]].push_back(i);
    k[i]=i;
  }
  ++it;
  dfs(sx,-1,-1);
  if (u[tx]!=it) { puts("0\n0"); return 0; }
  sort(k,k+m,cmp);
  for (ii=0; ii<m; ii++) {
    i=k[ii];
    if (c[i]>=r) break;
    if (un(fs(x[i]),fs(y[i]))) {
      ++it; T=0;
      dfs(sx,-1,i);
      if (u[tx]!=it) {
        r=c[i];
        sz=1;
        e0=i+1;
      } else for (j=0; j<m; j++) if (i!=j && c[i]+c[j]<r) {
        xx=x[j];
        yy=y[j];
        if (xx==yy || u[xx]!=it || u[yy]!=it) continue;
        if (t[xx]>t[yy]) swap(xx,yy);
        if (l[yy]>=t[yy] && t[tx]>=t[yy] && t[tx]<=f[yy]) {
          r=c[i]+c[j];
          sz=2;
          e0=i+1;
          e1=j+1;
        }
      }
    }
  }
  if (r<inf) {
    printf("%d\n%d\n%d",r,sz,e0);
    if (sz==2) printf(" %d",e1);
    puts("");
  } else puts("-1");
  return 0;
}