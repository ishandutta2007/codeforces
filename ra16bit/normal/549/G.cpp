#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a[200200];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  reverse(a,a+n);
  for (i=0; i<n; i++) a[i]-=i;
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i++) {
    a[i]+=i;
    if (i>0 && a[i]>a[i-1]) { puts(":("); return 0; }
  }
  reverse(a,a+n);
  for (i=0; i<n; i++) printf("%d ",a[i]);
  return 0;
}