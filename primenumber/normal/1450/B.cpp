#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,k;
    cin>>n>>k;
    vector<pair<i32,i32>> vp;
    rep(i,n) {
      i32 x,y;
      cin>>x>>y;
      vp.emplace_back(x,y);
    }
    bool can = false;
    for (auto&&[x,y] : vp) {
      bool ok = true;
      for (auto&&[z,w] : vp) {
        i32 d = abs(z-x)+abs(w-y);
        if (d > k) ok = false;
      }
      if (ok) can = true;
    }
    if (can) {
      cout<<1<<endl;
    } else {
      cout<<-1<<endl;
    }
  }
  return 0;
}