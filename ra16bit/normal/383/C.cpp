#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,x,y,c[200200],q[200200],r[200200],s[2][200200];
vector<pair<int,int> > a[200200];
vector<int> b[200200],g[200200];
void dfs(int i, int p, int d) {
  for (int j=0; j<a[i].size(); j++)
    for (int k=a[i][j].first; k<=m; k=(k<<1)-(k&(k-1))) {
      s[d][k]+=a[i][j].second;
      s[1-d][k]-=a[i][j].second;
    }
  for (int j=0; j<b[i].size(); j++) {
    int cur=c[i];
    for (int k=b[i][j]; k>0; k&=k-1) cur+=s[d][k];
    r[b[i][j]]=cur;
  }
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,1-d);
  }
  for (int j=0; j<a[i].size(); j++)
    for (int k=a[i][j].first; k<=m; k=(k<<1)-(k&(k-1))) {
      s[d][k]-=a[i][j].second;
      s[1-d][k]+=a[i][j].second;
    }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&c[i]);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=m; i++) {
    scanf("%d%d",&q[i],&x);
    if (q[i]==1) {
      scanf("%d",&y);
      a[x].push_back(make_pair(i,y));
    } else b[x].push_back(i);
  }
  dfs(1,0,0);
  for (i=1; i<=m; i++) if (q[i]==2) printf("%d\n",r[i]);
  return 0;
}