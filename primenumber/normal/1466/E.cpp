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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  constexpr i64 mod = 1'000'000'007;
  while(t--) {
    i32 n;
    cin>>n;
    vi64 x(n);
    rep(i,n)cin>>x[i];
    vi64 sum(60);
    rep(i,n) {
      rep(j,60) {
        sum[j] += (x[i] & (1ll << j)) % mod;
        sum[j] %= mod;
      }
    }
    i64 ans = 0;
    rep(i,n) {
      i64 y = 0, z = 0;
      rep(j,60) {
        if (((x[i] >> j) & 1) == 0) {
          z += sum[j];
          z %= mod;
        } else {
          y += sum[j];
          y %= mod;
          z += n * ((1ll << j) % mod) % mod;
          z %= mod;
        }
      }
      ans += y * z % mod;
      ans %= mod;
    }
    cout<<ans<<"\n";
  }
  return 0;
}