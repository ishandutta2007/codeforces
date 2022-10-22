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
    i32 n,m;
    cin>>n>>m;
    vector<string> tb(n);
    rep(i,n)cin>>tb[i];
    i32 col = 0;
    if (m % 3 == 0) col = 1;
    rep(i,n)rep(j,m) {
      if (j % 3 == col) tb[i][j] = 'X';
    }
    rep(i,m) {
      if (i % 3 == col) continue;
      i32 j = i+1;
      if (j % 3 == col) j = i-1;
      if (j < 0 || j >= m) {
        continue;
      }
      if (n >= 2 && (tb[1][i] == 'X' || tb[1][j] == 'X')) {
        tb[1][i] = 'X';
      } else {
        tb[0][i] = 'X';
      }
    }
    rep(i,n) cout<<tb[i]<<"\n";
  }
  return 0;
}