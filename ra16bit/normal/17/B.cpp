#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int i,q,n,m,r,x,y,z,t;
vector <int> a[1010];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&q);
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    a[y].push_back(z);
  }
  for (i=1; i<=n; i++) if (a[i].size()==0) t++; else sort(a[i].begin(),a[i].end());
  if (t>1) { printf("%d\n",-1); return 0; }
  for (i=1; i<=n; i++) if (a[i].size()>0) r+=a[i][0];
  printf("%d\n",r);
  return 0;
}