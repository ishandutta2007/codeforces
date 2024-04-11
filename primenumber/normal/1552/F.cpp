#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

//using namespace harudake;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n;
  cin>>n;
  vi64 x(n), y(n), s(n);
  rep(i,n) cin>>x[i]>>y[i]>>s[i];
  vi64 t(n, 0), st(n+1, 0);
  constexpr i64 mod = 998244353;
  rep(i,n) {
    i64 nxt = lower_bound(all(x), y[i]) - begin(x);
    t[i] = st[i] + mod - st[nxt] + (x[i] - y[i]);
    t[i] %= mod;
    st[i+1] = (st[i] + t[i]) % mod;
  }
  i64 ans = (x[n-1] + 1) % mod;
  rep(i,n) {
    if (s[i]) {
      ans += t[i];
      ans %= mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}