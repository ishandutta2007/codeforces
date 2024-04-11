#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,x,y,a[MX];
vector<int> g[MX];
void dfs(int i, int p, int s, int up, int cur) {
  int cnt=0;
  for (int j: g[i]) if (j!=p) ++cnt;
  a[i]=s-cnt*cur;
  if (cnt==0) return;
  if (p>0) assert(cur==up);
  up+=cur*(cnt-1)+a[i];
  for (int j: g[i]) if (j!=p) dfs(j,i,cur,up,-cur);
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
    for (i=1; i<=n; i++) if (g[i].size()>1) {
      dfs(i,0,0,0,1);
      break;
    }
    for (i=1; i<=n; i++) printf("%d%c",a[i],(i==n)?'\n':' ');
  }
  return 0;
}