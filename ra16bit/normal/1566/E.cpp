#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,i,x,y,tot,sum,cnt[MX];
vector<int> g[MX];
void dfs(int i, int p) {
  cnt[i]=0;
  for (int j: g[i]) if (j!=p) {
    dfs(j,i);
    if (cnt[j]==0) ++cnt[i];
  }
  if (cnt[i]!=0) ++tot;
  sum+=cnt[i];
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=1; i<n; i++) {
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    tot=sum=0;
    dfs(1,0);
    printf("%d\n",sum-tot+1);
  }
  return 0;
}