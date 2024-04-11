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
    vector<string> v(3);
    rep(i,3) cin>>v[i];
    vector cnt(2, vi32(3));
    rep(i,2) {
      rep(j,3) {
        for(auto&&c:v[j]) {
          if(c=='0'+i) ++cnt[i][j];
        }
      }
    }
    bool ok = false;
    rep(i,2){
      rep(j,3) {
        rep(k,j) {
          if (cnt[i][j] > n || cnt[i][k] > n) continue;
          string ans;
          i32 rem = max(2*n - cnt[i][j], 2*n - cnt[i][k]);
          i32 xj = 0, xk = 0;
          rep(y,rem) {
            while (xj < 2*n && xk < 2*n && v[j][xj] == '0'+i && v[k][xk] == '0'+i) {
              ++xj;
              ++xk;
              ans.push_back('0'+i);
            }
            while (xj < 2*n && v[j][xj] == '0'+i) {
              ++xj;
              ans.push_back('0'+i);
            }
            while (xk < 2*n && v[k][xk] == '0'+i) {
              ++xk;
              ans.push_back('0'+i);
            }
            ans.push_back('0'+(1-i));
            ++xj;++xk;
          }
          while (xj < 2*n && xk < 2*n && v[j][xj] == '0'+i && v[k][xk] == '0'+i) {
            ++xj;
            ++xk;
            ans.push_back('0'+i);
          }
          while (xj < 2*n && v[j][xj] == '0'+i) {
            ++xj;
            ans.push_back('0'+i);
          }
          while (xk < 2*n && v[k][xk] == '0'+i) {
            ++xk;
            ans.push_back('0'+i);
          }
          cout<<ans<<"\n";
          ok = true;
          break;
        }
        if (ok) break;
      }
      if (ok) break;
    }
  }
  return 0;
}