#include <cstdio>
#include <vector>
using namespace std;
const int MX=50050;
int n,m,T,it,i,j,r,a[222],p[222],q[222],w[222],g[222][222],f[222][222];
vector<int> v[222];
bool u[MX];
bool pe() {
  int fi=0,fr=1;
  q[0]=0; w[0]=++it;
  while (fi<fr) {
    int i=q[fi++];
    for (int j=0; j<=T; j++) if (f[i][j]<g[i][j] && w[j]!=it) {
      w[j]=it; p[j]=i; q[fr++]=j;
    }
    if (w[T]==it) return true;
  }
  return false;
}
void dfs(int i) {
  w[i]=it;
  v[m].push_back(i);
  for (int j=1; j<=n; j++) if (f[i][j]!=0 && w[j]!=it) dfs(j);
}
int main() {
  for (i=2; i<MX; i++) if (!u[i]) for (j=i+i; j<MX; j+=i) u[j]=true;
  scanf("%d",&n); T=n+1;
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (a[i]&1) g[0][i]=2; else g[i][T]=2;
    for (j=1; j<i; j++) if (!u[a[i]+a[j]]) {
      if (a[i]&1) g[i][j]=1; else g[j][i]=1;
    }
  }
  while (pe()) {
    for (i=T; i>0; i=p[i]) {
      f[p[i]][i]++;
      f[i][p[i]]--;
    }
    r++;
  }
  if (r==n) {
    ++it;
    for (i=1; i<=n; i++) if (w[i]!=it) { dfs(i); ++m; }
    printf("%d\n",m);
    for (i=0; i<m; i++) {
      printf("%d",int(v[i].size()));
      for (j=0; j<v[i].size(); j++) printf(" %d",v[i][j]);
      puts("");
    }
  } else puts("Impossible");
  return 0;
}