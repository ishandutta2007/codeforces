#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=100100,MQ=19;
int i,j,n,x,y,z,m,all,c[MX],r[MX],d[MX],w[MX],a[MQ][2*MX],q[2*MX];
vector <int> g[MX],f[MX];
void dfs(int i, int p) {
  d[i]=d[p]+1;
  w[i]=++all;
  a[0][all]=i;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    a[0][++all]=i;
  }
}
int rfs(int i, int e) {
  int cnt=c[i];
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j],l=f[i][j];
    if (l==e) continue;
    cnt+=rfs(k,l);
  }
  return r[e]=cnt;
}
int lca(int x, int y) {
  x=w[x]; y=w[y];
  if (x>y) swap(x,y);
  int s=q[y-x+1];
  return d[a[s][x]]<=d[a[s][y-(1<<s)+1]]?a[s][x]:a[s][y-(1<<s)+1];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y); f[x].push_back(i);
    g[y].push_back(x); f[y].push_back(i);
  }
  dfs(1,0);
  scanf("%d",&m);
  for (j=1; j<MQ; j++) {
    x=1<<(j-1);
    for (i=1; i<=all; i++) {
      a[j][i]=a[j-1][i];
      y=i+x;
      if (y<=all && d[a[j-1][y]]<d[a[j][i]]) a[j][i]=a[j-1][y];
    }
  }
  for (x=0, i=1; i<=all; i++) {
    if (i==(1<<(x+1))) x++;
    q[i]=x;
  }
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    c[x]++;
    c[y]++;
    c[lca(x,y)]-=2;
  }
  rfs(1,0);
  for (i=1; i<n; i++) printf("%d%c",r[i],(i<n-1)?' ':'\n');
  return 0;
}