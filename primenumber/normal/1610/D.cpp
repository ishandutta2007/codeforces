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
  i32 n;
  cin>>n;
  vi32 hist(30);
  rep(i,n) {
    i32 cnt = 0;
    i32 a;
    cin>>a;
    while (a%2 == 0) {
      ++cnt;
      a /= 2;
    }
    ++hist[cnt];
  }
  constexpr i64 mod = 1000000007;
  vi64 p2(n+1);
  p2[0] = 1;
  rep(i,n) {
    p2[i+1] = p2[i] * 2 % mod;
  }
  i64 ans = 0;
  rep(i,30) {
    i32 larger = 0;
    rep2(j,i+1,30) {
      larger += hist[j];
    }
    if (i == 0) {
      i64 tmp = p2[hist[i]] + mod - 1;
      tmp %= mod;
      ans += p2[larger] * tmp % mod;
      ans %= mod;
    } else if (hist[i] > 0) {
      i64 tmp = p2[hist[i] - 1];
      tmp += mod - 1;
      tmp %= mod;
      ans += p2[larger] * tmp % mod;
      ans %= mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}