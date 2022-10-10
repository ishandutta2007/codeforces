#include <cstdio>
#include <vector>
using namespace std;
int n,i,x,y,z,d[100100];
long long r;
vector <int> g[100100],f[100100];
void dfs(int i, int p, long long s) {
  int j,k;
  d[i]=s;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k!=p) dfs(k,i,s+f[i][j]);
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
    r+=2*z;
  }
  dfs(1,0,0); x=1;
  for (i=2; i<=n; i++) if (d[i]>d[x]) x=i;
  printf("%I64d\n",r-d[x]);
  return 0;
}