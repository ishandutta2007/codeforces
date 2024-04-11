#include <bits/stdc++.h>
using namespace std;
const int MX=2020;
int n,i,x,t,fi[MX],cnt[MX],c[MX],r[MX],o[MX];
vector<int> g[MX];
bool ok=true;
void dfs(int i) {
  fi[i]=++t;
  cnt[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    dfs(g[i][j]);
    cnt[i]+=cnt[g[i][j]];
  }
  if (cnt[i]<=c[i]) ok=false;
  if (ok) {
    for (r[i]=1; c[i]>0; r[i]++) if (o[r[i]]>=fi[i]) c[i]--;
    if (o[r[i]]) {
      for (int j=n; j>r[i]; j--) o[j]=o[j-1];
      for (int j=1; j<=n; j++) if (i!=j && r[j]>=r[i]) r[j]++;
    }
    o[r[i]]=fi[i];
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x,&c[i]);
    g[x].push_back(i);
  }
  dfs(g[0][0]);
  if (ok) {
    puts("YES");
    for (i=1; i<=n; i++) printf("%d ",r[i]);
  } else puts("NO");
  return 0;
}