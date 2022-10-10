#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a[100100];
long long l,r,h,s;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) s+=a[n-1]-a[i];
  l=0; r=a[n-1];
  while (l<r) {
    h=(l+r)/2;
	for (i=0; i<n; i++) if (s-a[n-1]+(n-1LL)*h<0) break;
	if (i>=n) r=h; else l=h+1;
  }
  printf("%I64d\n",a[n-1]+r);
  return 0;
}