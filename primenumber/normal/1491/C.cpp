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
    i64 n;
    cin>>n;
    vi64 s(n);
    rep(i,n)cin>>s[i];
    i64 ans = 0;
    vi64 reduce(n+2, 0);
    rep(i,n) {
      i64 z = 0;
      i64 needed = max(z, s[i] - 1 - reduce[i]);
      //dump<<needed<<endl;
      ans += needed;
      i64 extra = max(z, reduce[i] - (s[i] - 1));
      i64 last = min(n, i + s[i] + 1);
      i64 first = i+2;
      if (first < last) {
        reduce[last] -= 1;
        reduce[first] += 1;
      }
      reduce[i+1] += extra;
      reduce[i+2] -= extra;
      reduce[i+1] += reduce[i];
    }
    cout<<ans<<"\n";
  }
  return 0;
}