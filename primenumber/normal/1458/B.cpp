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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 n;
  cin>>n;
  constexpr i32 INF = 1e8;
  vector dp(n+1, vi32(n*100+100, -INF));
  dp[0][0] = 0;
  i32 sum = 0;
  rep(i,n) {
    i32 a,b;
    cin>>a>>b;
    sum += b;
    auto nxt = dp;
    rep(j,n) {
      rep(k,n*100) {
        nxt[j+1][k+a] = max(nxt[j+1][k+a], dp[j][k] + b);
      }
    }
    swap(nxt, dp);
  }
  rep2(i,1,n+1) {
    double res = 0;
    rep(j,n*100+1) {
      double cap = j;
      i32 amount = dp[i][j];
      //dump<<i<<" "<<j<<" "<<cap<<" "<<amount<<endl;
      i32 rem = sum - amount;
      res = max(res, min(cap, amount + rem / 2.0));
    }
    if (i>1) cout<<" ";
    cout<<fixed<<setprecision(10)<<res;
  }
  cout<<endl;
  return 0;
}