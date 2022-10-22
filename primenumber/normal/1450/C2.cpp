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
    vi32 cntx(3);
    vi32 cnto(3);
    rep(i,n)rep(j,n) {
      if (m[i][j] == 'X') {
        cntx[(i+j)%3] += 1;
      } else if (m[i][j] == 'O') {
        cnto[(i+j)%3] += 1;
      }
    }
    i32 k = 0;
    rep(i,3) k += cntx[i] + cnto[i];
    i32 o = -1, x = -1;
    rep(i,3)rep(j,3) {
      if (i==j) continue;
      if (cntx[i] + cnto[j] <= k / 3) {
        o = i;
        x = j;
      }
    }
    rep(i,n)rep(j,n) {
      if (m[i][j] == 'X' && (i+j) % 3 == o) {
        m[i][j] = 'O';
      } else if (m[i][j] == 'O' && (i+j) % 3 == x) {
        m[i][j] = 'X';
      }
    }
    rep(i,n) cout<<m[i]<<"\n";
  }
  return 0;
}