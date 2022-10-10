#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,j,k,x,r;
vector <int> g[222];
bool u[222],q;
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&k);
	if (k>0) q=true;
	for (j=0; j<k; j++) {
	  scanf("%d",&x);
	  g[i].push_back(n+x);
	  g[n+x].push_back(i);
	}
  }
  for (i=0; i<n; i++) if (!u[i]) { r++; dfs(i); }
  printf("%d\n",r-int(q));
  return 0;
}