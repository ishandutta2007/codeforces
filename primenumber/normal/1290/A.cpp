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
  int cs;
  cin>>cs;
  REP(ds,cs) {
    int n,m,k;
    cin>>n>>m>>k;
    vecint a(n);
    for(auto&& e:a) cin>>e;
    vecint mx(m);
    REP(i,m) {
      int j=i+n-m;
      mx[i] = max(a[i], a[j]);
    }
    int fix = min(m-1, k);
    int rem = m-1 - fix;
    constexpr int INF = 1000000001;
    vector<vecint> mn(m+1, vecint(m+1, INF));
    REP(i,m) {
      int len = i+1;
      REP(j,m) {
        mn[len][j] = min(mn[len-1][j+1], mx[j]);
      }
    }
    int ans = 0;
    REP(i,fix+1) {
      ans = max(ans, mn[rem+1][i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}