#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif
 
using namespace std;
using namespace std::string_literals;
 
using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

//using namespace harudake;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    vector<pair<i32,i32>> vp;
    rep(i,n) {
      i32 a,b;
      cin>>a>>b;
      vp.emplace_back(a,b);
    }
    i32 le = 1;
    i32 gt = n + 1;
    while (gt - le > 1) {
      i32 mid = (gt  + le) / 2;
      i32 invited = 0;
      for(auto&& [a,b] : vp) {
        if (b < invited) continue;
        if (invited + 1 + a >= mid) {
          ++invited;
        }
      }
      if (invited >= mid) {
        le = mid;
      } else {
        gt = mid;
      }
    }
    cout<<le<<"\n";
  }
  return 0;
}