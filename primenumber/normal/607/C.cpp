#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

constexpr ll mod = 0x1fffffffffffffff;
constexpr ll base = 257;

ll mul(ll a, ll b) {
  __uint128_t ans = __uint128_t(a) * b;
  ans = (ans >> 61) + (ans & mod);
  if(ans >= mod) ans -= mod;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  --n;
  string s,t;
  cin>>s>>t;
  reverse(ALL(s));
  map<char,char> m = {
    {'N', 'S'},
    {'S', 'N'},
    {'E', 'W'},
    {'W', 'E'}
  };
  for (auto&&e:t) {
    e = m[e];
  }
  ll hs = 0, ht = 0;
  ll pwr = 1;
  REP(i,n) {
    hs += mul(pwr, s[i]);
    hs %= mod;
    pwr = mul(pwr, base);
    ht = mul(ht, base);
    ht += t[n-i-1];
    ht %= mod;
    if (hs == ht) {
      cout<<"NO\n";
      return 0;
    }
  }
  cout<<"YES\n";
  return 0;
}