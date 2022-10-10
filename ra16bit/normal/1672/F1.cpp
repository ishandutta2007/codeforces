#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,i,j,k,mx,a[MX],cnt[MX];
vector<int> v[MX],nxt[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
      cnt[i]=0;
      nxt[i].clear();
      v[i].clear();
    }
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      ++cnt[a[i]];
    }
    for (mx=i=1; i<=n; i++) if (cnt[i]>cnt[mx]) mx=i;
    for (i=1; i<=cnt[mx]; i++) v[i].push_back(mx);
    k=1;
    for (i=1; i<=n; i++) if (cnt[i]>0 && i!=mx) {
      for (j=0; j<cnt[i]; j++) {
        v[k].push_back(i);
        if (++k>cnt[mx]) k=1;
      }
    }
    for (i=1; i<=cnt[mx]; i++) {
      nxt[v[i].back()].push_back(v[i][0]);
      for (j=1; j<v[i].size(); j++) nxt[v[i][j-1]].push_back(v[i][j]);
    }
    for (i=0; i<n; i++) {
      printf("%d%c",nxt[a[i]].back(),(i+1==n)?'\n':' ');
      nxt[a[i]].pop_back();
    }
  }
  return 0;
}