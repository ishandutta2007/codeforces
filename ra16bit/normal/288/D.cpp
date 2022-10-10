#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int n,i,x,y;
unsigned long long v[80008],r;
vector <int> g[80008];
void dfs(int i, int p) {
  v[i]=1;
  unsigned long long inner=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
	if (k==p) continue;
	dfs(k,i);
	inner+=v[k]*v[i];
	v[i]+=v[k];
  }
  r-=inner*(inner+2*v[i]*(n-v[i]));
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
	g[x].push_back(y);
	g[y].push_back(x);
  }
  r=(n*(n-1LL))/2LL;
  r*=r;
  dfs(1,0);
  cout<<r<<'\n';
  return 0;
}