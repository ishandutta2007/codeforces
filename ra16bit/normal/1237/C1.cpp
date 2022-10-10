#include <bits/stdc++.h>
using namespace std;
const int MX=50500;
int n,i,cx,cy,x[MX],y[MX],z[MX],k[MX];
set<tuple<int,int,int,int>> s;
bool cmp(int i, int j) {
  if (x[i]!=x[j]) return x[i]<x[j];
  if (y[i]!=y[j]) return y[i]<y[j];
  return z[i]<z[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    s.insert({x[i],y[i],z[i],i});
  }
  while (!s.empty()) {
    auto it=s.begin();
    i=get<3>(*it);
    it=s.erase(it);
    cx=get<0>(*it);
    it=s.lower_bound({cx,y[i],-1000000000,0});
    if (it==s.end() || get<0>(*it)!=cx) --it;
    cy=get<1>(*it);
    it=s.lower_bound({cx,cy,z[i],0});
    if (it==s.end() || get<0>(*it)!=cx || get<1>(*it)!=cy) --it;
    printf("%d %d\n",i+1,get<3>(*it)+1);
    s.erase(it);
  }
  return 0;
}