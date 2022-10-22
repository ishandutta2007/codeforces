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
  i32 n;
  cin>>n;
  vi32 a(n);
  rep(i,n)cin>>a[i];
  vi32 hist(101, 0);
  rep(i,n) ++hist[a[i]];
  auto itr = max_element(all(hist));
  i32 mxv = itr - begin(hist);
  i32 ans = 0;
  rep2(v,1,101) {
    if (v == mxv) continue;
    vi32 d(n+1);
    rep(i,n) {
      if (a[i] == mxv) {
        d[i+1] = d[i] + 1;
      } else if (a[i] == v) {
        d[i+1] = d[i] - 1;
      } else {
        d[i+1] = d[i];
      }
    }
    vi32 mn(2*n+1, -1);
    vi32 mx(2*n+1, -1);
    rep(i,n+1) {
      if (mn[d[i]+n] < 0) mn[d[i]+n] = i;
      mx[d[i]+n] = i;
    }
    rep(i,2*n+1) {
      ans = max(ans, mx[i] - mn[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}