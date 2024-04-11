#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,r,a[2020];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i+=m) r+=a[i]-1;
  printf("%d\n",2*r);
  return 0;
}