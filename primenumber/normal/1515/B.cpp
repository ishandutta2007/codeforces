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

bool is_psq(i32 n) {
  for (i32 i = 1; i * i <= n; ++i) {
    if (i * i == n) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    bool ok = false;
    if (n % 2 == 1) {
      ok = false;
    } else {
      if (is_psq(n)) ok = true;
      if (is_psq(n / 2)) ok = true;
    }
    if (ok) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
  return 0;
}