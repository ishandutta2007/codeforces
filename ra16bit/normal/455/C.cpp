#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=300100;
int n,m,q,x,y,t,best,w,a[MX],p[MX],r[MX];
vector<int> g[MX];
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
void un(int x, int y) {
  if (x==y) return;
  if (r[x]<r[y]) {
    p[x]=y;
    a[y]=max(max(a[x],a[y]),(a[x]+1)/2+(a[y]+1)/2+1);
  } else {
    p[y]=x;
    a[x]=max(max(a[x],a[y]),(a[x]+1)/2+(a[y]+1)/2+1);
    if (r[x]==r[y]) r[x]++;
  }
}
void dfs(int i, int prev, int d) {
  p[i]=x;
  if (d>best) { best=d; w=i; }
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=prev) dfs(g[i][j],i,d+1);
}
int main() {
  scanf("%d%d%d",&n,&m,&q);
  while (m--) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (x=1; x<=n; x++) if (!p[x]) {
    best=-1; dfs(x,0,0);
    best=-1; dfs(w,0,0);
    a[x]=best;
  }
  while (q--) {
    scanf("%d%d",&t,&x);
    if (t==2) {
      scanf("%d",&y);
      un(fs(x),fs(y));
    } else printf("%d\n",a[fs(x)]);
  }
  return 0;
}