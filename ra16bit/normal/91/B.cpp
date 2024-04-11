#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int i,c,n,r[100100];
pair <int, int> a[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i].first); a[i].second=i; }
  sort(a,a+n);
  for (i=0; i<n; i++) {
    if (a[i].second>c) c=a[i].second;
    r[a[i].second]=c-a[i].second-1;
  }
  for (i=0; i<n; i++) {
    if (i) putchar(' ');
    printf("%d",r[i]);
  }
  return 0;
}