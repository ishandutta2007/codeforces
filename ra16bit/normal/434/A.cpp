#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,k,a[100100];
long long c,r,ro;
vector<int> v[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d",&a[i]);
    if (i>0 && a[i]!=a[i-1]) {
      v[a[i]].push_back(a[i-1]);
      v[a[i-1]].push_back(a[i]);
      r+=abs(a[i]-a[i-1]);
    }
  }
  for (ro=r, i=1; i<=n; i++) if (v[i].size()) {
    sort(v[i].begin(),v[i].end());
    k=v[i][v[i].size()/2];
    for (c=ro, j=0; j<v[i].size(); j++) {
      c-=abs(i-v[i][j]);
      c+=abs(k-v[i][j]);
    }
    r=min(r,c);
  }
  printf("%I64d\n",r);
  return 0;
}