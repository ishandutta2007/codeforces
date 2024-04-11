#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,p,i,j,x,y,m,c[100100],cnt[100100],cur,cp,z,r;
vector<int> g[100100];
void dfs(int i, int p, int d) {
  m=max(d,m);
  c[d]++;
  for (int j=0; j<g[i].size(); j++)
    if (g[i][j]!=p) dfs(g[i][j],i,d+1);
}
int main() {
  scanf("%d%d%d",&n,&k,&p);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0,0);
  for (j=i=m; i>0; i--) {
    for (; j>0; j--) {
      z=min(c[j]-cnt[j],k-cur);
      if (j<i) z=min(z,(p-cp)/(i-j));
      cnt[j]+=z;
      cur+=z;
      cp+=z*(i-j);
      if (cnt[j]<c[j]) break;
    }
    r=max(r,cur);
    cur-=cnt[i];
    cp-=cur;
    if (j==i) j--;
  }
  printf("%d\n",r);
  return 0;
}