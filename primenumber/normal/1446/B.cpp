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
  i32 n,m;
  cin>>n>>m;
  string a,b;
  cin>>a>>b;
  vector dp(n+1, vi32(m+1, 0));
  rep(i,n)rep(j,m) {
    if (a[i] == b[j]) {
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 4 - 1 - 1);
    } else {
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j] - 1);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1] - 1);
    }
  }
  i32 ans = 0;
  rep(i,n+1)rep(j,m+1) ans = max(ans, dp[i][j]);
  cout<<ans<<endl;
  return 0;
}