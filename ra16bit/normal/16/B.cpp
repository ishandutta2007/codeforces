#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int n,m,i,c,r;
pair <int, int> a[25];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d",&a[i].second,&a[i].first);
  sort(a,a+m);
  for (i=m; i>=0; i--) {
    c=min(n,a[i].second);
    r+=c*a[i].first; n-=c;
  }
  printf("%d\n",r);
  return 0;
}