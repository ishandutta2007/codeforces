#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int n,k,i,a[100010];
set<int> r;
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) {
    if (a[i]%k==0 && r.count(a[i]/k)) continue;
	r.insert(a[i]);
  }
  printf("%d\n",int(r.size()));
  return 0;
}