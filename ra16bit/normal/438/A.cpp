#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,ki,kj,r,a[100100],k[100100];
vector<int> g[100100];
bool was[100100];
bool cmp(int i, int j) {
  return a[i]>a[j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    k[i]=i;
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
      if (!was[kj]) r+=a[kj];
    }
    was[ki]=true;
  }
  printf("%d\n",r);
  return 0;
}