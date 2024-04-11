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
  cin.tie(0);
  int t;
  cin>>t;
  REP(cnum,t) {
    int n,k,z;
    cin>>n>>k>>z;
    vecint a(n);
    REP(i,n) cin>>a[i];
    int z1 = z+1;
    vector dp(2*z1, vecint(k+1, -1e8));
    dp[0][0] = a[0];
    REP(i,k) {
      REP(j,z1) {
        int x = i - 2*j;
        if (x < 0) break;
        REP(pl,2) {
          if (pl == 0 && j < z && x > 0) {
            dp[z1 + j+1][i+1] = max(dp[z1 + j+1][i+1], dp[j][i] + a[x-1]);
          }
          dp[j][i+1] = max(dp[j][i+1], dp[pl * z1 + j][i] + a[x+1]);
        }
      }
    }
    int mx = 0;
    REP(i,2*z1) mx = max(mx, dp[i][k]);
    cout<<mx<<"\n";
  }
  return 0;
}