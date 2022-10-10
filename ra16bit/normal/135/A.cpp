#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,a[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  if (a[n-1]==1) {
    for (i=0; i<n-1; i++) printf("%d ",a[i]);
    printf("2");
  } else {
    printf("1");
    for (i=0; i<n-1; i++) printf(" %d",a[i]);
  }
  return 0;
}