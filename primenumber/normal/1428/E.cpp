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
  ll n,k;
  cin>>n>>k;
  using T = tuple<ll,ll,ll>;
  priority_queue<T> q;
  auto cost = [](ll a, ll c) {
    ll d = (a + c - 1) / c;
    ll ds = a / c;
    ll r = a % c;
    return r * d * d + (c - r) * ds * ds;
  };
  auto diff = [&](ll a, ll c) {
    if (a == c) return 0ll;
    return cost(a, c) - cost(a, c+1);
  };
  REP(i,n) {
    ll a;
    cin>>a;
    q.emplace(diff(a, 1), a, 1);
  }
  while (n < k) {
    auto [df, a, c] = q.top();
    q.pop();
    ++c;
    ++n;
    q.emplace(diff(a, c), a, c);
  }
  ll ans = 0;
  while (!q.empty()) {
    auto [df, a, c] = q.top();
    ans += cost(a, c);
    q.pop();
  }
  cout<<ans<<endl;
  return 0;
}