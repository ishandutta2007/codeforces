#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long z,l,r,h,x,k,n;
vector<long long> a;
int main() {
  scanf("%I64d",&n);
  for (k=0; k<=61; k++) {
    z=(1LL<<k)-1;
    if (z>n) break;
    l=0; r=min(2000000000LL,z==0?2000000000LL:(n/z+1));
    while (l<r) {
      h=(l+r)/2;
      x=(h*(h-1LL))/2+h*z;
      if (x>=n) r=h; else l=h+1;
    }
    x=(r*(r-1LL))/2+r*z;
    if (x==n && r%2==1) a.push_back(r*(z+1));
  }
  sort(a.begin(),a.end());
  if (a.empty()) puts("-1"); else for (size_t i=0; i<a.size(); i++) printf("%I64d\n",a[i]);
  return 0;
}