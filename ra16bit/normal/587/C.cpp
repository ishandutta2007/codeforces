#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=100010,SZ=182;
int n,m,q,i,x,y,oth,cur,cnt=10,s[2],c[2][11],best[MX][11],b[MX],all[MX],d[MX],p[MX],up[MX];
vector<int> g[MX],a[MX];
void mergea(int k) {
  int se=a[k].size(),z=min(cnt,s[cur]+se);
  s[oth]=0;
  for (int e=0, cc=0; s[oth]<z; )
    c[oth][s[oth]++] = (cc>=s[cur] || (e<se && a[k][e]<=c[cur][cc])) ? a[k][e++] : c[cur][cc++];
  swap(cur,oth);
}
void mergeb(int y) {
  s[oth]=0;
  int z=min(cnt,s[cur]+b[y]);
  for (int e=0, cc=0; s[oth]<z; )
    c[oth][s[oth]++] = (cc>=s[cur] || (e<b[y] && best[y][e]<=c[cur][cc])) ? best[y][e++] : c[cur][cc++];
  swap(cur,oth);
}
void dfs(int i, int prev, int dep) {
  all[dep]=i; d[i]=dep; p[i]=prev;
  if (dep>=SZ) {
    up[i]=all[dep-SZ];
    cur=0; oth=1;
    s[cur]=0;
    for (int j=0; j<SZ; j++) mergea(all[dep-j]);
    b[i]=s[cur];
    for (int j=0; j<s[cur]; j++) best[i][j]=c[cur][j];
  }
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==prev) continue;
    dfs(k,i,dep+1);
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=1; i<=n-1; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=m; i++) {
    scanf("%d",&x);
    if (a[x].size()<10) a[x].push_back(i);
  }
  dfs(1,0,0);
  while (q--) {
    scanf("%d%d%d",&x,&y,&cnt);
    cur=0; oth=1;
    s[0]=0;
    for (; d[x]<=d[y]-SZ; y=up[y]) mergeb(y);
    for (; d[x]<d[y]; y=p[y]) mergea(y);
    for (; d[y]<=d[x]-SZ; x=up[x]) mergeb(x);
    for (; d[y]<d[x]; x=p[x]) mergea(x);
    for (; d[x]>=SZ && up[x]!=up[y]; x=up[x], y=up[y]) {
      mergeb(x);
      mergeb(y);
    }
    for (; x!=y; x=p[x], y=p[y]) {
      mergea(x);
      mergea(y);
    }
    mergea(x);
    printf("%d",s[cur]);
    for (i=0; i<s[cur]; i++) printf(" %d",c[cur][i]);
    puts("");
  }
  return 0;
}