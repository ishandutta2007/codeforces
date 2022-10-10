#include <cstdio>
#include <vector>
using namespace std;
const int MX=5050;
int r,x,y,n,i,it,f[MX],v[MX];
vector <int> g[MX],a;
void dfs(int i, int p) {
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=p) dfs(g[i][j],i);
  a.clear(); v[i]=1;
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=p) {
    a.push_back(v[g[i][j]]);
    v[i]+=a.back();
  }
  a.push_back(n-v[i]);
  int m=a.size();
  int mx=0;
  f[0]=++it;
  for (int i=0; i<m; i++) {
    for (int j=mx; j>=0; j--) if (f[j]==it) f[j+a[i]]=it;
    mx+=a[i];
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  for (i=1; i<n-1; i++) if (f[i]!=0) r++;
  printf("%d\n",r);
  for (i=1; i<n-1; i++) if (f[i]!=0) printf("%d %d\n",i,n-1-i);
  return 0;
}