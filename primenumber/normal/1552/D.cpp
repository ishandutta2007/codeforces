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
    vector<bool> can(1000001, false);
    can[0] = true;
    bool ok = false;
    rep(i,n) {
      i32 a;
      cin>>a;
      a = abs(a);
      auto nxt = can;
      rep(j,1000000) {
        if (j + a > 1000000) break;
        if (!can[j]) continue;
        if (nxt[j+a]) ok = true;
        nxt[j+a] = true;
      }
      swap(can, nxt);
    }
    if (ok) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
  
  return 0;
}