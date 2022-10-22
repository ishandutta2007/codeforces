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
  i32 n;
  cin>>n;
  vi32 a(n);
  rep(i,n)cin>>a[i];
  vi32 p,q;
  p.push_back(a[0]);
  i32 ans = 1;
  set<i32> candi;
  candi.insert(-1);
  rep(i,n-1) {
    i32 v = a[i+1];
    if (v == a[i]) {
      //nothing
    } else {
      if (candi.count(v) == 0) {
        ++ans;
      } else {
        candi.clear();
      }
      candi.insert(a[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}