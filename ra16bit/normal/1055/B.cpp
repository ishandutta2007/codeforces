#include <bits/stdc++.h>
using namespace std;
int n,m,l,i,le,ri,x,w,t,a[100100];
bool o=false;
set<pair<int,int>> s;
int main() {
  scanf("%d%d%d",&n,&m,&l);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (a[i]>l) {
      if (!o) w=i;
      o=true;
    } else if (o) {
      s.insert({w,i});
      o=false;
    }
  }
  if (o) s.insert({w,n+1});
  while (m--) {
    scanf("%d",&t);
    if (t==0) {
      printf("%d\n",int(s.size()));
      continue;
    }
    scanf("%d%d",&i,&x);
    o=(a[i]<=l);
    a[i]+=x;
    if (a[i]>l) {
      a[i]=l+1;
      if (o) {
        auto it=s.lower_bound({i,0});
        le=i; ri=i+1;
        if (it!=s.end() && it->first==i+1) {
          ri=it->second;
          s.erase(it);
          it=s.lower_bound({i,0});
        }
        if (it!=s.begin()) {
          it--;
          if (it->second==i) {
            le=it->first;
            s.erase(it);
          }
        }
        s.insert({le,ri});
      }
    }
  }
  return 0;
}