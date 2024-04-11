#include <cstdio>
#include <vector>
using namespace std;
int n,m,num,cnt,c,e,odd,i,j,k,wi,wj,it,w[1000100],a[1010][1010],b[1010][1010],l[1010][1010],u[1010][1010];
vector<int> g[1000100];
bool was;
void dfs(int i) {
  w[i]=it; cnt++;
  if (g[i].size()%2) odd++;
  for (int j=0; j<g[i].size(); j++) if (w[g[i][j]]!=it) dfs(g[i][j]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
    scanf("%d",&a[i][j]);
    if (a[i][j]) {
      l[i][j]=l[i][j-1]+1;
      u[i][j]=u[i-1][j]+1;
      if (wi==0) { wi=i; wj=j; }
      c++;
    }
  }
  if (c>1) for (k=2; k<max(n,m); k++) {
    num=cnt=odd=e=0; ++it;
    for (i=wi; i<=n; i+=k) for (j=wj%k; j<=m; j+=k) if (a[i][j]) {
      b[i][j]=++num;
      g[num].clear();
    }
    for (i=wi; i<=n; i+=k) for (j=wj%k; j<=m; j+=k) if (a[i][j]) {
      if (i+k<=n && a[i+k][j] && u[i+k][j]>k) {
        g[b[i][j]].push_back(b[i+k][j]);
        g[b[i+k][j]].push_back(b[i][j]);
        e++;
      }
      if (j+k<=m && a[i][j+k] && l[i][j+k]>k) {
        g[b[i][j]].push_back(b[i][j+k]);
        g[b[i][j+k]].push_back(b[i][j]);
        e++;
      }
    }
    if (e*(k-1)+num!=c) continue;
    dfs(1);
    if (cnt==num && odd<=2) { printf("%d ",k); was=true; }
  }
  if (!was) puts("-1");
  return 0;
}