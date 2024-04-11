#include <bits/stdc++.h>
using namespace std;
int n,m,i,cnt,mn,x,y,a[300300],b[300300];
vector<int> g[300300],f[300300],r;
bool u[300300];
void dfs(int i) {
  u[i]=true;
  if (a[i]==1) b[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (u[k]) continue;
    dfs(k);
    b[i]+=b[k];
    if (b[k]&1) r.push_back(f[i][j]);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (a[i]==1) cnt++;
    if (a[i]==-1) mn=i;
  }
  if (cnt&1) {
    if (mn==0) { puts("-1"); return 0; }
    a[mn]=1;
  }
  for (i=1; i<=m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y); f[x].push_back(i);
    g[y].push_back(x); f[y].push_back(i);
  }
  dfs(1);
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d\n",r[i]);
  return 0;
}