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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,p,k;
    cin>>n>>p>>k;
    string a;
    cin>>a;
    i32 x,y;
    cin>>x>>y;
    i64 ans = 1e9;
    rep(i,k) {
      i32 need = 0;
      for (i64 j = p + i; j <= n; j += k) {
        if (a[j-1] == '0') ++need;
      }
      for (i64 j = p + i; j <= n; j += k) {
        ans = min(ans, need * x + (j - p) * y);
        if (a[j-1] == '0') --need;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}