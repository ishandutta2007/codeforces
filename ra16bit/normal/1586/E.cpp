#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int n,m,xx,yy,i,q,cnt,r,ed,all[MX],st[MX],x[MX],y[MX];
vector<int> g[MX],d[MX],e[MX];
bool u[MX];
void dfs(int i) {
  u[i]=true;
  for (int j: g[i]) if (!u[j]) {
    ++ed;
    d[i].push_back(j); e[i].push_back(ed);
    d[j].push_back(i); e[j].push_back(ed);
    dfs(j);
  }
}
void solve(int i, int y, int p, int dep) {
  if (i==y) {
    for (int j=0; j<dep; j++) st[all[j]]^=1;
    return;
  }
  for (int j=0; j<d[i].size(); j++) {
    int k=d[i][j];
    if (k==p) continue;
    all[dep]=e[i][j];
    solve(k,y,i,dep+1);
  }
}
void print(int i, int y, int p, int dep) {
  if (i==y) {
    printf("%d\n",dep+1);
    for (int j=0; j<dep; j++) printf("%d ",all[j]);
    printf("%d\n",y);
    return;
  }
  all[dep]=i;
  for (int j: d[i]) if (j!=p) print(j,y,i,dep+1);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&xx,&yy);
    g[xx].push_back(yy);
    g[yy].push_back(xx);
  }
  dfs(1);
  scanf("%d",&q);
  for (i=0; i<q; i++) {
    scanf("%d%d",&x[i],&y[i]);
    solve(x[i],y[i],0,0);
  }
  for (i=1; i<=n; i++) {
    cnt=0;
    for (int ee: e[i]) cnt+=st[ee];
    if (cnt&1) r++;
  }
  if (r==0) {
    puts("YES");
    for (i=0; i<q; i++) print(x[i],y[i],0,0);
  } else printf("NO\n%d\n",r/2);
  return 0;
}