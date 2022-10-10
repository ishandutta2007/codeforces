#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,i,x,y,le,ri,res,en[MX],a[MX],p[MX];
vector<int> st[MX];
set<int> cur,rgh;
int calc() {
  int L=le,R=ri;
  if (!cur.empty()) {
    L=min(L,*cur.begin());
    auto it=cur.end();
    --it;
    R=max(R,*it);
  }
  if (!rgh.empty()) {
    L=min(L,*rgh.begin());
    auto it=rgh.end();
    --it;
    R=max(R,*it);
  }
  return R-L+1;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    map<int,vector<int>> pos;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      en[i]=0;
      st[i].clear();
      pos[a[i]].push_back(i);
    }
    le=n+1;
    ri=0;
    for (i=0; i<m; i++) {
      scanf("%d%d",&x,&y);
      st[x].push_back(y);
      ++en[y];
    }
    multiset<int> all;
    cur.clear();
    rgh.clear();
    for (i=1; i<=n; i++) {
      for (int j: st[i]) all.insert(-j);
      if (!all.empty()) {
        int k=-*all.begin();
        int lx=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),i)-pos[a[i]].begin();
        int rx=upper_bound(pos[a[i]].begin(),pos[a[i]].end(),k)-pos[a[i]].begin()-1;
        if (rx>lx) {
          cur.insert(i);
          p[i]=pos[a[i]][rx];
          ++lx;
          --rx;
          if (lx<=rx) {
            le=min(le,pos[a[i]][lx]);
            ri=max(ri,pos[a[i]][rx]);
          }
        }
      }
      for (int j=0; j<en[i]; j++) all.erase(all.find(-i));
    }
    if (cur.empty()) { puts("0"); continue; }
    res=calc();
    while (!cur.empty()) {
      rgh.insert(p[*cur.begin()]);
      cur.erase(cur.begin());
      res=min(res,calc());
    }
    printf("%d\n",res);
  }
  return 0;
}