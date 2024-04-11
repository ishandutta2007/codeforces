#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,a[200200];
vector<int> g[200200];
long long r;
void dfs(int i, int p) {
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    a[i]+=a[k];
  }
  if (i!=1) r+=min(a[i],m-a[i]);
}
int main() {
  scanf("%d%d",&n,&m);
  m*=2;
  for (i=0; i<m; i++) { scanf("%d",&x); a[x]=1; }
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  printf("%I64d\n",r);
  return 0;
}