#include <cstdio>
#include <vector>
using namespace std;
int n,x,y,i,j,k;
vector<int> g[200200];
long long r;
int dfs(int i, int p) {
  int can=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    can+=dfs(k,i);
  }
  if (can>=2) {
    r+=2;
    return 0;
  }
  r+=can;
  return 1;
}
int main() {
  scanf("%d%d%d",&n,&x,&y);
  for (i=1; i<n; i++) {
    scanf("%d%d",&j,&k);
    g[j].push_back(k);
    g[k].push_back(j);
  }
  if (x>=y) {
    for (i=1; i<=n; i++) if (g[i].size()==n-1) break;
    if (i<=n) printf("%I64d\n",y*(n-2LL)+x); else printf("%I64d\n",y*(n-1LL));
    return 0;
  }
  dfs(1,0);
  printf("%I64d\n",r*x+(n-1-r)*y);
  return 0;
}