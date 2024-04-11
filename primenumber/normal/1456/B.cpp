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
  constexpr i32 INF = 1'000'000'000;
  i64 ans = INF;
  vi32 a(n);
  rep(i,n)cin>>a[i];
  rep(i,n) {
    i32 x1 = 0;
    rep2(j,1,31) {
      if (i+j > n) break;
      x1 ^= a[i+j-1];
      i32 x2 = 0;
      rep2(k,1,31) {
        if (i+j+k > n) break;
        x2 ^= a[i+j+k-1];
        if (x1 > x2) {
          ans = min(ans, j-1 + k-1);
        }
      }
    }
  }
  if (ans < INF) {
    cout<<ans<<endl;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}