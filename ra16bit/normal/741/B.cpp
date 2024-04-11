#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,w,i,j,e,r,nj,ne,cur,x,y,cc,a[1010],b[1010],ca[1010],cb[1010],u[1010],k[1010],f[1010][1010][2];
vector<int> g[1010];
bool st[1010];
bool cmp(int i, int j) {
  return u[i]<u[j];
}
void dfs(int i) {
  ca[cc]+=a[i];
  cb[cc]+=b[i];
  u[i]=cc;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (!u[k]) dfs(k);
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&w);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) scanf("%d",&b[i]);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=0; i<n; i++) {
    if (!u[i]) { ++cc; dfs(i); }
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (i=0; i<n; i++) if (i==0 || u[k[i]]!=u[k[i-1]]) st[i]=true;
  for (i=0; i<n; i++) {
    cur=k[i];
    for (j=0; j<=w; j++) for (e=0; e<2; e++) {
      ne=int(e==1 || st[i]);
      f[i+1][j][ne]=max(f[i+1][j][ne],f[i][j][e]);
      if (ne) {
        nj=j+a[cur];
        if (nj<=w) f[i+1][nj][0]=max(f[i+1][nj][0],f[i][j][e]+b[cur]);
        if (st[i]) {
          nj=j+ca[u[cur]];
          if (nj<=w) f[i+1][nj][0]=max(f[i+1][nj][0],f[i][j][e]+cb[u[cur]]);
        }
      }
    }
  }
  for (j=0; j<=w; j++) for (e=0; e<2; e++) r=max(r,f[n][j][e]);
  printf("%d\n",r);
  return 0;
}