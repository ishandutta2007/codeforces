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
  ll n,k,s;
  cin>>n>>k>>s;
  s = min(s, n*n/2);
  vecll q(n);
  REP(i,n) cin>>q[i];
  vector dp(s+1, vecint(k+1, 0));
  REP(i,k) {
    REP(rc,k) {
      REP(j,s) {
        int cost = k-i;
        int value = q[i];
        int c = k - rc - 1;
        if (j + cost > s) continue;
        dp[j+cost][c+1] = max(dp[j+cost][c+1], dp[j][c] + value);
      }
    }
  }
  REP(i,s)REP(j,k+1) {
    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
  }
  const int INF =5e8;
  vector dp2(s+1, vecint(k+1, INF));
  dp2[0][0] = 0;
  FOR(i,k,n) {
    REP(rc,k) {
      REP(j,s) {
        int cost = i - k;
        int value = q[i];
        int c = k - rc - 1;
        if (j + cost > s) continue;
        dp2[j+cost][c+1] = min(dp2[j+cost][c+1], dp2[j][c] + value);
      }
    }
  }
  REP(i,s)REP(j,k+1) {
    dp2[i+1][j] = min(dp2[i+1][j], dp2[i][j]);
  }
  int sum = 0;
  REP(i,k) sum += q[i];
  int mn = sum;
  REP(i,k+1)REP(j,s+1) {
    mn = min(mn, sum + dp2[j][i] - dp[s-j][i]);
  }
  cout<<mn<<endl;
  return 0;
}