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
  int r,n;
  cin>>r>>n;
  const int INF = 100000000;
  vecint dp(n+1,-INF);
  dp[0] = 0;
  vecint pmax(n+1);
  vector<tuple<int,int,int>> vt;
  vt.reserve(n+1);
  vt.emplace_back(0,1,1);
  FOR(i,1,n+1) {
    int t,x,y;
    cin>>t>>x>>y;
    if (i >= 1000) {
      dp[i] = pmax[i-1000] + 1;
    }
    FOR(j,1,1000) {
      if (i-j < 0) break;
      auto[tj,xj,yj] = vt[i-j];
      if (t - tj >= abs(x-xj) + abs(y-yj)) {
        dp[i] = max(dp[i], dp[i-j] + 1);
      }
    }
    vt.emplace_back(t,x,y);
    pmax[i] = max(pmax[i-1], dp[i]);
  }
  cout<<pmax[n]<<endl;
  return 0;
}