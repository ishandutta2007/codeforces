#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,num,i,x[MX],y[MX],e[5];
vector<pair<int,int>> g[MX];
bool u[MX],w[MX];
char ans[MX];
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].first;
    if (u[k]) continue;
    ans[g[i][j].second]='0';
    dfs(k);
  }
}
void resolve(int i, int fnd) {
  w[i]=true;
  for (int j=0; j<g[i].size(); j++) {
    int ed=g[i][j].second;
    if (ans[ed]=='1') continue;
    int k=g[i][j].first;
    if (w[k]) continue;
    if (k==fnd) {
      ans[ed]='1';
      break;
    }
    resolve(k,fnd);
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) {
      g[i].clear();
      u[i]=false;
      w[i]=false;
    }
    for (i=0; i<m; i++) {
      scanf("%d%d",&x[i],&y[i]);
      if (x[i]>y[i]) swap(x[i],y[i]);
      g[x[i]].emplace_back(y[i],i);
      g[y[i]].emplace_back(x[i],i);
      ans[i]='1';
    }
    ans[m]=0;
    dfs(1);
    for (num=i=0; i<m; i++) if (ans[i]=='1') e[num++]=i;
    if (num==3) {
      bool ok=true;
      for (i=0; i<num && ok; i++) for (int j=0; j<i; j++) if (x[e[i]]==x[e[j]]) {
        int k=e[3-i-j];
        if (x[k]==min(y[e[i]],y[e[j]]) && y[k]==max(y[e[i]],y[e[j]])) {
          ok=false;
          resolve(x[k],y[k]);
          ans[k]='0';
          break;
        }
      }
    }
    puts(ans);
  }
  return 0;
}