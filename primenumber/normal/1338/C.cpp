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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  vector<vecint> nums = {
    {0, 0, 0},
    {1, 2, 3},
    {2, 3, 1},
    {3, 1, 2}
  };
  REP(casenum,t) {
    ll n;
    cin>>n;
    ll p4 = 1;
    ll cnt = 0;
    while (p4*4 <= n) {
      p4 *= 4;
      ++cnt;
    }
    ll idx = (n - p4) / 3;
    int m3 = (n - p4) % 3;
    p4 = 1;
    ll ans = 0;
    REP(i,cnt) {
      ans += nums[idx % 4][m3] * p4;
      idx /= 4;
      p4 *= 4;
    }
    ans += nums[1][m3] * p4;
    cout << ans << '\n';
  }
  return 0;
}