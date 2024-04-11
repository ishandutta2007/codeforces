#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
constexpr ll MOD = 1000000007;

pair<ll, bool> pmod(ll x, ll i) {
  if (i == 0) return make_pair(1, false);
  if (i%2 == 1) {
    auto [prev, large] = pmod(x, i-1);
    prev *= x;
    if (prev > 1e6) large = true;
    prev %= MOD;
    return make_pair(prev, large);
  }
  auto [prev, large] = pmod(x, i/2);
  prev *= prev;
  if (prev > 1e6) large = true;
  prev %= MOD;
  return make_pair(prev, large);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cin>>cases;
  REP(cnum,cases) {
    ll n,p;
    cin>>n>>p;
    vecll k(n);
    for(auto&&e:k)cin>>e;
    sort(ALL(k));
    reverse(ALL(k));
    ll diff = 0;
    bool is_mod = false;
    REP(i,n) {
      if (i) {
        ll shift = k[i-1] - k[i];
        auto [mul, large] = pmod(p, shift);
        diff *= mul;
        if ((diff > 0 && large) || diff > 1e6) {
          is_mod = true;
        }
        diff %= MOD;
      }
      if (diff > 0) {
        --diff;
      } else {
        if (is_mod) {
          diff = MOD - 1;
        } else {
          diff = 1;
        }
      }
    }
    ll shift = k.back();
    auto [mul, large] = pmod(p, shift);
    diff *= mul;
    if ((diff > 0 && large) || diff > 1e6) {
      is_mod = true;
    }
    diff %= MOD;
    cout<<diff<<"\n";
  }
  return 0;
}