#include <cstdio>
#include <vector>
using namespace std;
int n,m,x,y,i;
long long f[50005][505],r;
vector <int> g[50005];
void dfs(int i, int p) {
  int j,k,e;
  f[i][0]=1;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    for (e=0; e<m; e++) f[i][e+1]+=f[k][e];
  }
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k==p) continue;;
    for (e=0; e<m-1; e++) r+=f[k][e]*(f[i][m-e-1]-f[k][m-e-2]);
    r+=f[k][m-1]*2;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  printf("%I64d\n",r/2);
  return 0;
}