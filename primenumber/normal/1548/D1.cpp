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
  vi64 cnt(4);
  rep(i,n) {
    i32 x,y;
    cin>>x>>y;
    x /= 2;
    y /= 2;
    x %= 2;
    y %= 2;
    i32 idx = x + y * 2;
    ++cnt[idx];
  }
  //rep(i,4)dump<<cnt[i]<<endl;
  i64 ans1 = 0, ans3 = 0;
  rep(i,4)rep(j,4) {
    if (i == j) continue;
    if (cnt[i] >= 2) {
      ans1 += cnt[i] * (cnt[i] - 1) / 2 * cnt[j];
    }
  }
  rep(i,4) {
    if (cnt[i] >= 3) ans3 += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
  }
  //dump<<ans1<<" "<<ans3<<endl;
  i64 ans = ans3 + ans1;
  cout<<ans<<endl;
  return 0;
}