#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
int n,i,t,r;
pair <int, int> a[1010];
double l,eps=1e-8;
int main() {
  scanf("%d%d",&n,&t);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  if (n>0) r=2; else r=0;
  for (i=1; i<n; i++) {
    l=a[i-1].first+0.5*a[i-1].second;
    l=a[i].first-0.5*a[i].second-l;
    if (fabs(l-t)<eps) r++; else if (l-t>0) r+=2;
  }
  printf("%d\n",r);
  return 0;
}