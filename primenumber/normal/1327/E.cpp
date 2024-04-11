#include <bits/stdc++.h>
#define FOR(i,k,n)  for(ll i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

constexpr ll MOD = 998244353;

ll powmod(ll base, ll index) {
  if (index == 0) return 1;
  if (index % 2) return powmod(base, index-1) * base % MOD;
  ll h = powmod(base, index/2);
  return h * h % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  FOR(i,1,n) {
    ll rem = n-i;
    ll ans = 2 * 90 * powmod(10, rem-1) % MOD;
    if (rem > 1) {
      ans += 810 * powmod(10, rem-2) % MOD * (rem-1) % MOD;
      ans %= MOD;
    }
    cout << ans << ' ';
  }
  cout<<"10\n";
  cout<<flush;
  return 0;
}