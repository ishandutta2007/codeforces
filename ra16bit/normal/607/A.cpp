#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,x,r,f[100100];
pair<int,int> a[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  for (i=0; i<n; i++) {
    x=lower_bound(a,a+i+1,make_pair(a[i].first-a[i].second,0))-a;
    f[i]=x?(f[x-1]+1):1;
    r=max(r,f[i]);
  }
  printf("%d\n",n-r);
  return 0;
}