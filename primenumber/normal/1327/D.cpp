#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int solve(const vecint& c) {
  int n = c.size();
  set<int> d;
  for(int i=1;i*i <= n;++i) {
    if ((n%i) == 0) {
      d.insert(i);
      d.insert(n/i);
    }
  }
  for (auto&& i:d) {
    vecint ok(i, true);
    REP(j,n) {
      if (c[j] != c[(j+i)%n]) ok[j%i] = false;
    }
    for(auto&& e:ok)
      if (e) return i;
  }
  return n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  REP(cs,t) {
    int n;
    cin>>n;
    vecint p(n);
    for(auto&& e:p) cin>>e;
    for(auto&& e:p) --e;
    vecint c(n);
    for(auto&& e:c) cin>>e;
    vector<bool> vis(n, false);
    int ans = n;
    REP(i,n) {
      if (vis[i]) continue;
      vecint sc;
      vis[i] = true;
      sc.push_back(c[i]);
      int s = p[i];
      while (s != i) {
        vis[s] = true;
        sc.push_back(c[s]);
        s = p[s];
      }
      ans = min(ans, solve(sc));
    }
    cout<<ans<<'\n';
  }
  cout<<flush;
  return 0;
}