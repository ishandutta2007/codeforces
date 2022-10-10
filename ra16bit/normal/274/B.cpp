#include <cstdio>
#include <vector>
using namespace std;
int n,i,x,y;
long long a[100100],b[100100],c[100100];
vector <int> g[100100];
void dfs(int i, int p) {
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
	if (k==p) continue;
	dfs(k,i);
	a[i]=max(a[i],a[k]);
	b[i]=max(b[i],b[k]);
  }
  c[i]+=a[i];
  c[i]-=b[i];
  if (c[i]<0) a[i]+=-c[i]; else b[i]+=c[i];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
	g[x].push_back(y);
	g[y].push_back(x);
  }
  for (i=1; i<=n; i++) scanf("%I64d",&c[i]);
  dfs(1,0);
  printf("%I64d\n",a[1]+b[1]);
  return 0;
}