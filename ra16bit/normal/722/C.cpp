#include <bits/stdc++.h>
using namespace std;
int n,i,a,le,ri;
long long s[100100];
map<int, long long> all;
multiset<long long> sum;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    s[i]=s[i-1]+a;
  }
  all[0]=n;
  sum.insert(-s[n]);
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    auto it=all.lower_bound(a);
    it--;
    le=it->first;
    ri=it->second;
    sum.erase(sum.find(s[le]-s[ri]));
    all.erase(it);
    if (le+1<a) {
      all[le]=a-1;
      sum.insert(s[le]-s[a-1]);
    }
    if (a<ri) {
      all[a]=ri;
      sum.insert(s[a]-s[ri]);
    }
    if (i==n) puts("0"); else printf("%I64d\n",-*sum.begin());
  }
  return 0;
}