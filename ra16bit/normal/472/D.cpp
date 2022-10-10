#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,k,a[2002][2002],p[2002],q[2002];
vector<int> g[2002],f[2002];
long long d[2002];
bool u[2002];
void dfs(int i, int p, long long s) {
  d[i]=s;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,s+f[i][j]);
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) {
    scanf("%d",&a[i][j]);
    if (a[i][j]==0 && i!=j) { puts("NO"); return 0; }
  }
  for (i=1; i<n; i++) p[i]=2000000000;
  for (k=0; k<n; k++) {
    int best=-1;
    for (i=0; i<n; i++) if (!u[i] && (best==-1 || p[best]>p[i])) best=i;
    u[i=best]=true;
    if (i!=0) {
      g[q[i]].push_back(i); f[q[i]].push_back(p[i]);
      g[i].push_back(q[i]);    f[i].push_back(p[i]);
    }
    for (j=0; j<n; j++) if (!u[j] && a[i][j]<p[j]) {
      p[j]=a[i][j]; q[j]=i;
    }
  }
  for (i=0; i<n; i++) {
    dfs(i,-1,0);
    for (j=0; j<n; j++) if (d[j]!=a[i][j]) { puts("NO"); return 0; }
  }
  puts("YES");
  return 0;
}