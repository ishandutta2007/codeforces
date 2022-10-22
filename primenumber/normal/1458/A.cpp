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
  i64 n,m;
  cin>>n>>m;
  vi64 a(n);
  rep(i,n)cin>>a[i];
  vi64 b(m);
  rep(i,m)cin>>b[i];
  i64 mn = *min_element(all(a));
  i64 g = 0;
  rep(i,n) {
    g = gcd(g, a[i] - mn);
  }
  rep(i,m) {
    if(i)cout<<" ";
    cout<<gcd(g, mn + b[i]);
  }
  cout<<endl;
  return 0;
}