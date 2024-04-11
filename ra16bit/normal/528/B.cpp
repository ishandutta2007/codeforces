#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,i,l,r,h,mx,cur,f[200200];
pair<int,int> a[200200];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  memset(f,120,sizeof(f));
  f[0]=-2000000000;
  for (i=0; i<n; i++) {
    cur=a[i].first-a[i].second;
    l=0; r=mx+1;
    while (l<r) {
      h=(l+r)/2;
      if (f[h]<=cur) l=h+1; else r=h;
    }
    f[r]=min(f[r],a[i].first+a[i].second);
    if (r>mx) mx++;
  }
  printf("%d\n",mx);
  return 0;
}