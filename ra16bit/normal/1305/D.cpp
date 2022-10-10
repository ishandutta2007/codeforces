#include <bits/stdc++.h>
using namespace std;
int n,i,x,y,z,cnt,it,u[1010],p[1010],d[1010];
vector<int> g[1010];
bool rm[1010];
void dfs(int i, int pv, int dp) {
  ++cnt; u[i]=it; p[i]=pv; d[i]=dp;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==pv || rm[k]) continue;
    dfs(k,i,dp+1);
  }
}
int main() {
  scanf("%d",&n);
  for (z=i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  while (true) {
    cnt=x=y=0;
    ++it; dfs(z,0,0);
    if (cnt<=1) break;
    for (i=1; i<=n; i++) if (u[i]==it) {
      if (x==0 || d[i]>d[x]) x=i;
    }
    ++it; dfs(x,0,0);
    for (i=1; i<=n; i++) if (u[i]==it) {
      if (y==0 || d[i]>d[y]) y=i;
    }
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",&z);
    for (i=y; i>0; i=p[i]) if (i!=z) rm[i]=true;
  }
  printf("! %d\n",z);
  fflush(stdout);
  return 0;
}