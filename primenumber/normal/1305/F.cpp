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
  int n;
  cin>>n;
  vecll a(n);
  for(auto&& e:a)cin>>e;
  random_device rd;
  mt19937 mt(rd());
  shuffle(ALL(a),mt);
  vecll tb(1210001, 0);
  FOR(i,2,1101) {
    if (tb[i] == 0) {
      for(ll j=2*i; j <= 1210000; j += i) {
        tb[j] = i;
      }
    }
  }
  vecll primes;
  FOR(i,2,1210000) if(tb[i] == 0) primes.push_back(i);
  ll lo = max(INT64_C(2), a[0] - n);
  ll hi = a[0] + n;
  ll len = hi - lo + 1;
  set<ll> s;
  vecll rs(len);
  REP(i,len) {
    rs[i] = i + lo;
  }
  for(ll p:primes) {
    ll from = lo + p - 1;
    from -= from % p;
    if (from <= hi) s.insert(p);
    for(ll j = from - lo; j < len; j += p) {
      while (rs[j] % p == 0) rs[j] /= p;
    }
  }
  REP(i,len) {
    if (rs[i] > 1) {
      s.insert(rs[i]);
    }
  }
  auto cost = [](ll x, ll p) {
    if (x < p) return p - x;
    x %= p;
    return min(x, p - x);
  };
  ll ans = n;
  for (auto&& p:s) {
    ll sum = 0;
    REP(i,n) {
      sum += cost(a[i], p);
      if (sum >= ans) break;
    }
    ans = min(ans, sum);
  }
  cout<<ans<<endl;
  return 0;
}