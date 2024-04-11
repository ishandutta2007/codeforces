#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,tot,n,i,mx,b,fi,fr,q[MX],a[MX],cnt[MX];
vector<int> v[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
      cnt[i]=0;
      v[i].clear();
    }
    for (tot=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (++cnt[a[i]]==1) ++tot;
    }
    for (i=0; i<n; i++) {
      scanf("%d",&b);
      v[a[i]].push_back(b);
    }
    for (mx=i=1; i<=n; i++) if (cnt[i]>cnt[mx]) mx=i;
    q[fi=0]=mx;
    for (fr=1; fi<fr; fi++) {
      for (int nxt: v[q[fi]]) if (nxt!=mx) {
        if (--cnt[nxt]==0) q[fr++]=nxt;
      }
    }
    puts((fr==tot)?"AC":"WA");
  }
  return 0;
}