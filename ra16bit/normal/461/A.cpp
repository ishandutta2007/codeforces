#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,a[300300];
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) r+=(i+2LL)*a[i];
  printf("%I64d\n",r-a[n-1]);
  return 0;
}