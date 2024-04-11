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
  i32 t;
  cin>>t;
  while(t--) {
    string s;
    cin>>s;
    vi32 dp(4, 0);
    i32 n = size(s);
    rep(p,n) {
      vi32 nxt(4, 100001);
      rep(i,4) {
        bool fix = false;
        rep(j,2) {
          if (((i>>j)&1) == 0) {
            if (p-2+j >= 0 && s[p-2+j] == s[p]) fix = true;
          }
        }
        //dump<<p<<" "<<i<<" "<<fix<<endl;
        if (!fix) {
          nxt[i>>1] = min(nxt[i>>1], dp[i]);
        }
        nxt[(i>>1)|2] = min(nxt[(i>>1)|2], dp[i]+1);
      }
      swap(nxt, dp);
    }
    cout<<*min_element(all(dp))<<"\n";
  }
  return 0;
}