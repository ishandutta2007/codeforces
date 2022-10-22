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
    vecint old(n+1, -1);
    vecint mx(n+1, 0);
    REP(i,n) {
      int a;
      cin>>a;
      int len = i - old[a];
      mx[a] = max(mx[a], len);
      old[a] = i;
    }
    FOR(a,1,n+1) {
      if (old[a] < 0) continue;
      int len = n - old[a];
      mx[a] = max(mx[a], len);
    }
    const int INF = 1e8;
    vecint ans(n+1, INF);
    FOR(a,1,n+1) {
      if (mx[a] == 0) continue;
      ans[mx[a]] = min(ans[mx[a]], a);
    }
    REP(i,n) {
      ans[i+1] = min(ans[i+1], ans[i]);
    }
    FOR(i,1,n+1) {
      if (i>1) cout<<" ";
      if (ans[i] < INF) {
        cout << ans[i];
      } else {
        cout << -1;
      }
    }
    cout<<"\n";
  }
  return 0;
}