#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int i,n,l,r;
vector <int> x;
pair <int, int> a[1010];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i].second,&a[i].first);
    if (a[i].first<a[i].second) swap(a[i].first,a[i].second);
  }
  sort(a,a+n); l=-100000;
  for (i=0; i<n; i++) if (a[i].second>l) {
    l=a[i].first; r++;
    x.push_back(l);
  }
  printf("%d\n",r);
  for (i=0; i<r; i++) {
    if (i>0) putchar(' ');
    printf("%d",x[i]);
  }
  return 0;
}