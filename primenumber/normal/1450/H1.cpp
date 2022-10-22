#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

constexpr i64 mod = 998244353;

// a^-1 mod p
i64 inv(i64 a,i64 p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  i64 cx = 0;
  i64 cy = 0;
  rep(i,n) {
    if (s[i] == '?') continue;
    bool even = i%2 == 0;
    bool b = s[i] == 'b';
    if (even == b) {
      ++cx;
    } else {
      ++cy;
    }
  }
  i64 rem = n - cx - cy;
  i64 comb = 1;
  i64 sum = 0;
  i64 ans = 0;
  rep(i,rem+1) {
    i64 x = cx + i;
    i64 y = cy + (rem - i);
    i64 d = abs(x - y);
    if (d % 4 == 0) {
      i64 val = d / 4;
      ans += val * comb % mod;
      ans %= mod;
      sum += comb;
      sum %= mod;
    }
    if (i < rem) {
      comb *= rem - i;
      comb %= mod;
      comb *= inv(i+1, mod);
      comb %= mod;
    }
  }
  if (sum == 0) {
    cout<<0<<endl;
    return 0;
  }
  ans *= inv(sum, mod);
  ans %= mod;
  cout<<ans<<endl;
  return 0;
}