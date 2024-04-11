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
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    vi32 a(n);
    rep(i,n) cin>>a[i];
    a.insert(begin(a), 0);
    a.push_back(0);
    i64 ans = 0;
    rep(i,n) {
      if (a[i] < a[i+1] && a[i+1] > a[i+2]) {
        i64 mx = max(a[i], a[i+2]);
        ans += a[i+1] - mx;
        a[i+1] = mx;
      }
    }
    rep(i,n+1) {
      ans += abs(a[i] - a[i+1]);
    }
    cout<<ans<<"\n";
  }
  return 0;
}