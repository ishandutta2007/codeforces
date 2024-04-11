#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,a[MX],mn[MX],res[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    set<int> s;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      s.insert(i);
      res[i]=0;
    }
    mn[n]=a[n];
    for (i=n-1; i>0; i--) mn[i]=min(mn[i+1],a[i]);
    for (i=1; i<n; i++) if (a[i]>mn[i+1]) {
      auto it=s.lower_bound(a[i]-mn[i+1]);
      if (it==s.end()) --it;
      res[*it]=i+1;
      s.erase(it);
    }
    for (i=1; i<=n; i++) {
      if (res[i]==0) res[i]=n;
      printf("%d%c",res[i],(i==n)?'\n':' ');
    }
  }
  return 0;
}