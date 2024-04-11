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
    vector r(n, vi32(5, 0));
    rep(i,n)rep(j,5) cin>>r[i][j];
    vi32 top = r[0];
    auto cmp = [] (auto&& lhs, auto&& rhs) {
      i32 cnt = 0;
      rep(i,5) {
        if (lhs[i] < rhs[i]) ++cnt;
      }
      return cnt >= 3;
    };
    i32 ans = 0;
    rep(i,n) {
      if (cmp(r[i], top)){
        top = r[i];
        ans = i;
      }
    }
    bool ok = true;
    rep(i,n) {
      if (cmp(r[i], top)) ok = false;
    }
    if (ok) {
      cout<<(ans+1)<<"\n";
    } else {
      cout<<"-1\n";
    }
  }

  
  return 0;
}