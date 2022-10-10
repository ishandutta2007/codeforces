#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,j,l,a[100100],b[100100],c[100100],k[100100],p[100100],r[100100],x[100100],y[100100],e[100100],u[100100];
vector <int> g[100100],f[100100];
long long all,mx,s[100100];
bool cmp(int i, int j) { return c[i]<c[j]; }
int dfs(int x, int p, int z, bool b) {
  u[x]=i;
  int j,k=e[x];
  for (j=0; j<g[x].size(); j++) if (g[x][j]!=p) k+=dfs(g[x][j],x,f[x][j],b);
  if (b) s[z]+=(all-k)*k;
  return k;
}
int findset(int i) {
  if (p[i]!=i) p[i]=findset(p[i]);
  return p[i];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) { p[i]=i; e[i]=1; }
  for (i=1; i<n; i++) { scanf("%d%d%d",&a[i],&b[i],&c[i]); k[i]=i; }
  sort(k+1,k+n,cmp);
  for (i=1; i<n; i=j) {
    for (j=i; c[k[i]]==c[k[j]]; j++) {
      x[j]=findset(a[k[j]]);
      y[j]=findset(b[k[j]]);
      g[x[j]].clear(); f[x[j]].clear();
      g[y[j]].clear(); f[y[j]].clear();
    }
    for (l=i; l<j; l++) {
      g[x[l]].push_back(y[l]); f[x[l]].push_back(k[l]);
      g[y[l]].push_back(x[l]); f[y[l]].push_back(k[l]);
    }
    for (l=i; l<j; l++) if (u[x[l]]!=i) {
      all=dfs(x[l],0,0,false);
      dfs(x[l],0,0,true);
    }
    for (l=i; l<j; l++) {
      x[l]=findset(x[l]);
      y[l]=findset(y[l]);
      if (r[x[l]]<r[y[l]]) {
        p[x[l]]=y[l];
        e[y[l]]+=e[x[l]];
      } else {
        p[y[l]]=x[l];
        e[x[l]]+=e[y[l]];
        if (r[x[l]]==r[y[l]]) r[x[l]]++;
      }
    }
  }
  for (i=1; i<n; i++) {
    if (s[i]>mx) { mx=s[i]; l=0; }
    if (s[i]==mx) l++;
  }
  printf("%I64d %d\n",2LL*mx,l); l=0;
  for (i=1; i<n; i++) if (s[i]==mx) {
    if (l) putchar(' ');
    printf("%d",i); l=1;
  }
  return 0;
}