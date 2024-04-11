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
  i32 q;
  cin>>q;
  while(q--) {
    string s,t;
    cin>>s>>t;
    string rs = s;
    reverse(all(rs));
    i32 n = size(s);
    i32 m = size(t);
    bool ok = false;
    rep(i,n) {
      rep2(j,i,n) {
        if (s[j] != t[j-i]) break;
        i32 rem = m - (j-i+1);
        if (rem == 0) {
          //dump<<i<<" "<<j<<endl;
          ok = true;
          break;
        }
        i32 from = (n-1) - (j-1);
        //dump<<t.substr(j-i+1)<<" "<<rs.substr(from,rem)<<endl;
        if (t.substr(j-i+1) == rs.substr(from,rem)) {
          //dump<<i<<" "<<j<<endl;
          ok = true;
        }
      }
    }
    if (ok) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
  return 0;
}