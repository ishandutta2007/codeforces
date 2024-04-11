#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,r,a[500500];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n); j=n/2;
  for (i=0; i<n/2 && j<n; i++) {
    while (j<n && a[i]*2>a[j]) j++;
    if (j<n) { r++; j++; }
  }
  printf("%d\n",n-r);
  return 0;
}