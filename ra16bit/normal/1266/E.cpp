#include <bits/stdc++.h>
using namespace std;
const int B=19,MSK=(1<<B)-1,MX=200200;
int n,q,x,y,i,a[MX],b[MX];
long long tot,z,w;
map<long long, int> m;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    tot+=a[i];
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%I64d%d",&x,&z,&y);
    w=(z<<B)+x;
    auto it=m.find(w);
    if (it!=m.end()) {
      i=it->second;
      m.erase(it);
      if (b[i]<=a[i]) ++tot;
      --b[i];
    }
    if (y>0) {
      m[w]=y;
      if (++b[y]<=a[y]) --tot;
    }
    printf("%I64d\n",tot);
  }
  return 0;
}