#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,x,y,a[200200],b[200200],c[200200];
vector<int> g[200200];
void dfs(int i, int p, int d) {
  bool was=false;
  int abest=d?n:1,bbest=d?0:n;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,d^1);
    c[i]+=c[k];
    if (d) {
      abest=min(abest,c[k]-a[k]);
      bbest+=b[k];
    } else {
      abest+=a[k]-1;
      bbest=min(bbest,b[k]);
    }
    was=true;
  }
  if (!was) {
    a[i]=b[i]=c[i]=1;
  } else if (d) {
    a[i]=c[i]-abest;
    b[i]=bbest;
  } else {
    a[i]=abest;
    b[i]=bbest;
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0,1);
  printf("%d %d\n",a[1],b[1]);
  return 0;
}