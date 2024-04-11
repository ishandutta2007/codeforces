#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<tuple<int,int>> vt;
  REP(i,n) {
    int x,s;
    cin>>x>>s;
    vt.emplace_back(x,s);
  }
  sort(ALL(vt));
  constexpr int INF = 1e9;
  vector<vecint> dp(m+1, vecint(n+1, INF));
  dp[0][0] = 0;
  REP(i,n) {
    auto [x,s] = vt[i];
    FOR(j,0,2*m+1) {
      int inc = max(0,abs(j-x)-s);
      int opp = max(0,x-s-inc-1);
      int pos = min(j,m);
      REP(k,i+1) {
        dp[pos][i+1] = min(dp[pos][i+1], dp[opp][k]+inc);
      }
    }
    FOR(j,0,m) {
      int rev = m-j;
      dp[rev-1][i+1] = min(dp[rev-1][i+1], dp[rev][i+1]);
    }
    //FOR(j,0,m+1) {
    //  cerr<<dp[j][i+1]<<' ';
    //}
    //cerr<<endl;
  }
  cout<<*min_element(ALL(dp[m]))<<endl;
  return 0;
}