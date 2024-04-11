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
    i32 n;
    cin>>n;
    vector<string> m(n);
    rep(i,n)cin>>m[i];
    vi32 cnt(3);
    rep(i,n)rep(j,n) {
      if (m[i][j] == 'X') {
        cnt[(i+j)%3] += 1;
      }
    }
    i32 idx = min_element(all(cnt))-begin(cnt);
    rep(i,n)rep(j,n) {
      if (m[i][j] == 'X' && (i+j) % 3 == idx) {
        m[i][j] = 'O';
      }
    }
    rep(i,n) cout<<m[i]<<"\n";
  }
  return 0;
}