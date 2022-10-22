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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  ll fa = 1;
  REP(i,n) {
    fa *= (i+1);
    fa %= MOD;
  }
  ll pm = 1;
  REP(i,n-1) {
    pm *= 2;
    pm %= MOD;
  }
  ll ans = (fa + MOD - pm) % MOD;
  cout << ans << "\n";
  return 0;
}