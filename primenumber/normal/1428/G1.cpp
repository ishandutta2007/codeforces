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
  ll k;
  cin>>k;
  vecll f(6);
  REP(i,6)cin>>f[i];
  constexpr ll INF = 1e16;
  vecll dp(1000000, -INF);
  dp[0] = 0;
  ll qsz = 3;
  ll p10 = 1;
  REP(i,6) {
    vecll nxt = dp;
    vector vq(qsz, deque<pair<ll,int>>());
    REP(j,1000000) {
      ll val = dp[j] - (j/qsz) * f[i];
      auto& q = vq[j%qsz];
      while (!q.empty() && val >= q.back().first) q.pop_back();
      q.emplace_back(val, j);
      REP(x,3) {
        ll jx = j - x*p10;
        if (jx < 0) break;
        ll r = jx % qsz;
        auto& q2 = vq[r];
        if (!q2.empty()) {
          auto [v, j2] = q2.front();
          nxt[j] = max(nxt[j], dp[j2] + ((j-j2)/qsz) * f[i]);
        }
      }
      ll rmj = j - 9*(k-1)*p10 - 2*p10;
      if (rmj >= 0) {
        auto& q2 = vq[rmj%qsz];
        if (!q2.empty() && q2.front().second == rmj) q2.pop_front();
      }
      FOR(x,3,10) {
        ll idx = j - 9 * (k-1) * p10 - x * p10;
        if (idx < 0) continue;
        ll fix = 0;
        if (x % 3 == 0) fix = f[i] * (x / 3);
        ll val = dp[idx] + 3 * (k-1) * f[i] + fix;
        nxt[j] = max(nxt[j], val);
      }
    }
    qsz *= 10;
    p10 *= 10;
    swap(dp, nxt);
  }
  int q;
  cin>>q;
  while(q--) {
    int n;
    cin>>n;
    cout<<dp[n]<<"\n";
  }
  return 0;
}