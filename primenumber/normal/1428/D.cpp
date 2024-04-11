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
  cin.tie(nullptr);
  int n;
  cin>>n;
  vecint a(n);
  REP(i,n)cin>>a[i];
  int last_r = n+1;
  vector<tuple<int,int>> vp;
  set<pair<int,int>> unused;
  set<pair<int,int>> used;
  REP(ri,n) {
    int i = n - 1 - ri;
    switch (a[i]) {
      case 0: break;
      case 1:
        {
          last_r -= 1;
          unused.emplace(last_r, i+1);
          vp.emplace_back(last_r, i+1);
          break;
        }
      case 2:
        {
          if (unused.empty()) {
            cout<<-1<<endl;
            return 0;
          }
          auto itr = begin(unused);
          auto r = itr->first;
          unused.erase(itr);
          used.emplace(r, i+1);
          vp.emplace_back(r, i+1);
          break;
        }
      case 3:
        {
          if (unused.empty() && used.empty()) {
            cout<<-1<<endl;
            return 0;
          }
          last_r -= 1;
          int last_c;
          if (used.empty()) {
            auto itr = begin(unused);
            last_c = itr->second;
            unused.erase(itr);
          } else {
            auto itr = begin(used);
            last_c = itr->second;
            used.erase(itr);
          }
          vp.emplace_back(last_r, last_c);
          used.emplace(last_r, i+1);
          vp.emplace_back(last_r, i+1);
          break;
        }
    }
  }
  cout<<size(vp)<<endl;
  for(auto[r,c] : vp) {
    cout<<r<<" "<<c<<"\n";
  }
  return 0;
}