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

i32 calc(const string& s) {
  i32 first = 0;
  i32 second = 0;
  rep(i,10) {
    if (s[i] == '1') {
      if (i%2 == 0) ++first;
      else ++second;
    }
    i32 rem_f = (10-i-1) / 2;
    i32 rem_s = (10-i) / 2;
    if (second > first + rem_f || first > second + rem_s) return i+1;
  }
  return 10;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    string s;
    cin>>s;
    auto s0 = s;
    auto s1 = s;
    rep(i,10) {
      if (s[i] == '?') {
        if (i%2 == 0) {
          s0[i] = '0';
          s1[i] = '1';
        } else {
          s0[i] = '1';
          s1[i] = '0';
        }
      }
    }
    cout<<min(calc(s0),calc(s1))<<"\n";
  }
  return 0;
}