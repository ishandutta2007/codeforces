#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,x,a[200200],r=2000000000;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  x=n-n/2-1;
  for (i=0; i<=x && i<n; i++) r=min(r,a[n-1-x+i]-a[i]);
  printf("%d\n",r);
  return 0;
}