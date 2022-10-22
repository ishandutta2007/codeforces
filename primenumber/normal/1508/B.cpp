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
    i64 n,k;
    cin>>n>>k;
    vi64 dp(62);
    dp[0] = 1;
    rep2(i,1,62) {
      rep2(j,1,i+1) {
        dp[i] += dp[i-j];
      }
    }
    i64 b = dp.back();
    dp.resize(n+1, b);
    reverse(all(dp));
    if (k > dp.front()) {
      cout<<-1<<"\n";
      continue;
    }
    bool first = true;
    for(i32 i = 0; i < n; ) {
      for (i32 j = 1; i+j <= n; ++j) {
        if (dp[i+j] >= k) {
          rep(l,j) {
            if (!first) cout<<" ";
            else first=false;
            cout<<(i+j-l);
          }
          i += j;
          break;
        } else {
          k -= dp[i+j];
        }
      }
    }
    cout<<"\n";
  }
  return 0;
}