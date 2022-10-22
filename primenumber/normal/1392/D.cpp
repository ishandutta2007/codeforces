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
  int t;
  cin>>t;
  REP(cnum,t) {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res = 1e8;
    REP(st,4) {
      vector dp(4, vecint(n+1, 1e8));
      int cnt = 0;
      REP(j,2) {
        bool iss_l = s[j] == 'L';
        bool ist_l = ((st>>j) & 1) == 1;
        if (iss_l != ist_l) ++cnt;
      }
      dp[st][2] = cnt;
      FOR(i,2,n) {
        REP(j,4) {
          vector<bool> dir(2);
          REP(k,2) {
            dir[k] = ((j>>k) & 1) == 1;
          }
          if (dir[0] != dir[1]) {
            bool nx = dir[1];
            bool iss_l = s[i] == 'L';
            int cost = 0;
            if (nx != iss_l) ++cost;
            auto& val = dp[j>>1 | (nx << 1)][i+1];
            val = min(val, dp[j][i] + cost);
          }
          bool nx = !dir[1];
          bool iss_l = s[i] == 'L';
          int cost = 0;
          if (nx != iss_l) ++cost;
          auto& val = dp[j>>1 | (nx << 1)][i+1];
          val = min(val, dp[j][i] + cost);
        }
      }
      REP(i,4) {
        int bits = st << 2 | i;
        int to0 = bits & 0b111;
        int to1 = bits >> 1;
        if (to0 == 0 || to0 == 0b111) continue;
        if (to1 == 0 || to1 == 0b111) continue;
        res = min(res, dp[i][n]);
      }
    }
    cout<<res<<"\n";
  }
  return 0;
}