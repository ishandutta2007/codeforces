#include <cstdio>
#include <vector>
using namespace std;
const int MX=300030;
int n,m,k,i,j,x,y,xx,yy,fi,fr,s,t,a[MX],d[MX],q[MX],p[MX],r[MX];
vector <int> g[MX];
int findset(int i) {
  if (i!=p[i]) p[i]=findset(p[i]);
  return p[i];
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=1; i<=k; i++) {
    scanf("%d",&x);
    a[x]=i;
    p[i]=i;
    q[fr++]=x;
  }
  for (i=1; i<=m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(n+i); g[n+i].push_back(x);
    g[y].push_back(n+i); g[n+i].push_back(y);
  }
  scanf("%d%d",&s,&t);
  if (a[s]==0) { puts("-1"); return 0; }
  if (a[t]==0) {
    a[t]=++k;
    p[k]=k;
    q[fr++]=t;
  }
  while (fi<fr) {
    x=q[fi++];
    for (j=0; j<g[x].size(); j++) {
      y=g[x][j];
      if (a[y]==0) {
        d[y]=d[x]+1;
        a[y]=a[x];
        q[fr++]=y;
      } else {
        xx=findset(a[x]);
        yy=findset(a[y]);
        if (xx!=yy) {
          if (r[xx]<r[yy]) p[xx]=yy; else {
            if (r[xx]==r[yy]) r[xx]++;
            p[yy]=xx;
          }
        }
      }
    }
    if (findset(a[s])==findset(a[t])) { printf("%d\n",d[x]+1); return 0; }
  }
  puts("-1");
  return 0;
}