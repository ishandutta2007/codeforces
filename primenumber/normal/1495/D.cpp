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

constexpr i64 mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 n,m;
  cin>>n>>m;
  i32 INF = 1e8;
  vector<vi32> mat(n, vi32(n, INF));
  vector<vi32> nl(n);
  rep(i,m) {
    i32 a,b;
    cin>>a>>b;
    --a;--b;
    mat[a][b] = 1;
    mat[b][a] = 1;
    nl[a].push_back(b);
    nl[b].push_back(a);
  }
  rep(i,n) mat[i][i] = 0;
  rep(k,n)rep(i,n)rep(j,n) mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
  rep(x,n) {
    rep(y,n) {
      if (y) cout<<" ";
      i32 d = mat[x][y];
      i32 mid = 0;
      i64 ans = 1;
      rep(i,n) {
        if (mat[i][x] + mat[i][y] == d) {
          ++mid;
          continue;
        }
        i64 cnt = 0;
        for (auto&& to : nl[i]) {
          if (mat[to][x] < mat[i][x] && mat[to][y] < mat[i][y]) ++cnt;
        }
        ans *= cnt;
        ans %= mod;
      }
      if (mid > d + 1) ans = 0;
      cout<<ans;
    }
    cout<<"\n";
  }
  return 0;
}