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
  i32 n,q;
  cin>>n>>q;
  vi32 a(n);
  rep(i,n)cin>>a[i];
  i32 ones = count(all(a),1);
  rep(cnt,q) {
    i32 t;
    cin>>t;
    if (t == 1) {
      i32 x;
      cin>>x;
      --x;
      if (a[x] == 1) {
        --ones;
      } else {
        ++ones;
      }
      a[x] = 1 - a[x];
    } else {
      i32 k;
      cin>>k;
      if (ones >= k) {
        cout<<1<<"\n";
      } else {
        cout<<0<<"\n";
      }
    }
  }
  return 0;
}