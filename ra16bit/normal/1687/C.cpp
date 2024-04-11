#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,i,fi,fr,q[MX],a[MX],b[MX],l[MX],r[MX];
long long cur,s[MX];
bool good[MX],was[MX];
vector<int> g[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      s[i]=s[i-1]+a[i];
    }
    cur=0;
    good[0]=true;
    g[0].clear();
    set<int> all;
    for (i=1; i<=n; i++) {
      scanf("%d",&b[i]);
      cur+=b[i];
      good[i]=(cur==s[i]);
      if (!(good[i] && good[i-1])) all.insert(i);
      g[i].clear();
    }
    for (fi=fr=i=0; i<m; i++) {
      scanf("%d%d",&l[i],&r[i]);
      --l[i];
      was[i]=false;
      if (good[l[i]] && good[r[i]]) {
        was[i]=true;
        q[fr++]=i;
      }
      g[l[i]].push_back(i);
      g[r[i]].push_back(i);
    }
    while (fi<fr && !all.empty()) {
      i=q[fi++];
      auto it=all.upper_bound(l[i]);
      while (it!=all.end()) {
        if (*it>r[i]) break;
        if (!good[*it]) {
          good[*it]=true;
          for (int e: g[*it]) if (!was[e] && good[l[e]] && good[r[e]]) {
            was[e]=true;
            q[fr++]=e;
          }
        }
        it=all.erase(it);
      }
    }
    if (all.empty()) puts("YES"); else puts("NO");
  }
  return 0;
}