#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vecint a(n);
  for(auto&&e:a)cin>>e;
  auto orig = a;
  vector<tuple<int,int>> vt;
  REP(i,n) {
    vector<tuple<int,int,int>> invs;
    FOR(j,i+1,n) {
      if (orig[j] < orig[i]) {
        invs.emplace_back(a[j], orig[j], j);
      }
    }
    sort(ALL(invs),greater<tuple<int,int,int>>());
    for(auto&&[num,old,j]:invs) {
      vt.emplace_back(i,j);
      swap(a[i], a[j]);
    }
  }
  int k=size(vt);
  cout<<k<<endl;
  for(auto&&[x,y]:vt) {
    cout<<(x+1)<<" "<<(y+1)<<"\n";
  }
  return 0;
}