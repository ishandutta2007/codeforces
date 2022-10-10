#include <bits/stdc++.h>
using namespace std;
const int MX=500500;
int n,m,i,ii,x,y,cnt,k[MX],a[MX],was[MX];
vector<int> g[MX];
bool cmp(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); k[i-1]=i; }
  sort(k,k+n,cmp);
  for (ii=0; ii<n; ii++) {
    i=k[ii]; cnt=0;
    for (auto j : g[i]) {
      if (a[j]==a[i]) { puts("-1"); return 0; }
      if (a[j]<a[i] && was[a[j]]!=i) {
        was[a[j]]=i;
        ++cnt;
      }
    }
    if (cnt!=a[i]-1) { puts("-1"); return 0; }
  }
  for (ii=0; ii<n; ii++) printf("%d ",k[ii]);
  return 0;
}