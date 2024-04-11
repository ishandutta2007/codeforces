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
  i64 n,m;
  cin>>n>>m;
  vector dp(2, vector(n+1, vi64(n+1, 0)));
  dp[0][1][0] = 1;
  rep2(i,1,n) {
    vector nxt(2, vector(n+1, vi64(n+1, 0)));
    rep(l,i+1) {
      vi64 psum0(n+2);
      vi64 psum1(n+2);
      partial_sum(all(dp[0][l]), begin(psum0)+1);
      partial_sum(all(dp[1][l]), begin(psum1)+1);
      for(auto&& e : psum0) e %= m;
      for(auto&& e : psum1) e %= m;
      rep(k,i+1) {
        nxt[0][l+1][k] += psum0[l] + m - psum0[k];
        nxt[0][l+1][k] %= m;
        nxt[1][l+1][k] += psum0[k];
        nxt[1][l+1][k] += psum1[k];
        nxt[1][l+1][k] %= m;
      }
      rep(j,l) {
        nxt[0][l][n] += dp[0][l][j];
        nxt[0][l][n] += dp[1][l][j];
        nxt[0][l][n] %= m;
      }
      rep(k,l+1) {
        nxt[0][l+1][k] += dp[0][l][n];
        nxt[0][l+1][k] %= m;
      }
    }
    swap(dp, nxt);
  }
  i64 sum = 0;
  rep(i,n+1) {
    rep(j,i) {
      sum += dp[0][i][j];
      sum += dp[1][i][j];
      sum %= m;
    }
  }
  cout<<sum<<endl;
  return 0;
}