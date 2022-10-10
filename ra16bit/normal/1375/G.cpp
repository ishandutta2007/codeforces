#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,x,y,i,cnt[2];
vector<int> g[MX];
void dfs(int i, int p, int cur) {
  cnt[cur]++;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,cur^1);
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0,0);
  printf("%d\n",min(cnt[0],cnt[1])-1);
  return 0;
}