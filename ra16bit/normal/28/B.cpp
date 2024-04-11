#include <cstdio>
#include <vector>
using namespace std;
int n,i,x,e,a[111],b[111],u[111];
vector <int> g[111];
void dfs(int i) {
  u[i]=e; b[a[i]]=e;
  for (int j=0; j<g[i].size(); j++) if (u[g[i][j]]==0) dfs(g[i][j]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
    if (i-x>0) {
      g[i].push_back(i-x);
      g[i-x].push_back(i);
    }
    if (i+x<=n) {
      g[i].push_back(i+x);
      g[i+x].push_back(i);
    }
  }
  for (i=1; i<=n; i++) if (u[i]==0) {
    e++; dfs(i);
  }
  for (i=1; i<=n; i++) if (b[i]!=u[i]) { puts("NO"); return 0; }
  puts("YES"); return 0;
}