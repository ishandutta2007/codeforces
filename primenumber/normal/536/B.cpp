#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n) for(ll i=(k);i<(ll)(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)
 
using namespace std;
using namespace std::string_literals;
using ll = int64_t;
using ull = uint64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

constexpr ll MOD = 1000000007;
constexpr ll HMOD = 0x1fffffffffffffff;
constexpr ll HBASE = 257;

inline ull mul(ull a, ull b) {
  __uint128_t ans = __uint128_t(a) * b;
  ans = (ans >> 61) + (ans & HMOD);
  if(ans >= HMOD) ans -= HMOD;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m;
  cin>>n>>m;
  string p;
  cin>>p;
  vecll y(m);
  REP(i,m)cin>>y[i];
  ll k = size(p);
  vecll pB(k+1);
  pB[0] = 1;
  REP(i,k) {
    pB[i+1] = mul(pB[i], HBASE);
  }
  vecll hf(k+1);
  REP(i,k) {
    hf[i+1] = mul(hf[i], HBASE) + p[i];
    if (hf[i+1] >= HMOD) hf[i+1] -= HMOD;
  }
  vecll hb(k+1);
  REP(ri,k) {
    int i = k - ri;
    hb[i-1] = mul(p[i-1], pB[ri]) + hb[i];
    if (hb[i-1] >= HMOD) hb[i-1] -= HMOD;
  }
  REP(i,m-1) {
    ll d = y[i+1] - y[i];
    if (d >= k) continue;
    if (hf[k-d] != hb[d]) {
      cout<<"0\n";
      return 0;
    }
  }
  vecll imos(n);
  REP(i,m) {
    ++imos[y[i]-1];
    --imos[y[i]+k-1];
  }
  REP(i,n-1) {
    imos[i+1] += imos[i];
  }
  ll cnt = 1;
  REP(i,n) {
    if (imos[i] == 0) {
      cnt *= 26;
      cnt %= MOD;
    }
  }
  cout<<cnt<<endl;
  return 0;
}