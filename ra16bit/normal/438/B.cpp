#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,ki,kj,a[100100],k[100100],p[100100],f[100100],rk[100100];
vector<int> g[100100];
bool was[100100];
long long r;
long long sz(long long x) {
  return x*(x-1LL);
}
int fs(int x) {
  if (p[x]!=x) p[x]=fs(p[x]);
  return p[x];
}
void un(int i, int j, int k) {
  if (i==j) return;
  r-=k*(sz(f[i])+sz(f[j]));
  if (rk[i]<rk[j]) {
    p[i]=j;
    f[j]+=f[i];
    r+=k*sz(f[j]);
  } else {
    if (rk[i]==rk[j]) rk[i]++;
    p[j]=i;
    f[i]+=f[j];
    r+=k*sz(f[i]);
  }
}
bool cmp(int i, int j) {
  return a[i]>a[j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    k[i]=i;
    p[i]=i;
    f[i]=rk[i]=1;
  }
  while (m--) {
    scanf("%d%d",&i,&j);
    g[i].push_back(j);
    g[j].push_back(i);
  }
  sort(k+1,k+n+1,cmp);
  for (i=1; i<=n; i++) {
    ki=k[i];
    for (j=0; j<g[ki].size(); j++) {
      kj=g[ki][j];
      if (was[kj]) un(fs(ki),fs(kj),a[ki]);
    }
    was[ki]=true;
  }
  printf("%.8lf\n",double(r)/double(sz(n)));
  return 0;
}