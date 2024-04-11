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
  while(t--) {
    i32 n,m;
    cin>>n>>m;
    vi32 k(n);
    rep(i,n){
      cin>>k[i];
      --k[i];
    }
    vi32 c(m);
    rep(i,m)cin>>c[i];
    sort(all(k), greater<int>());
    i32 bought = 0;
    i64 ans = 0;
    rep(i,n) {
      if (bought < k[i]) {
        ans += c[bought];
        ++bought;
      } else {
        ans += c[k[i]];
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}