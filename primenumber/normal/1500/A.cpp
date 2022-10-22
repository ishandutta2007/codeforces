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
  i32 n;
  cin>>n;
  vi32 a(n);
  rep(i,n)cin>>a[i];
  if (n > 4000) {
    a.resize(4000);
    n = 4000;
  }
  vector<pair<i32,i32>> hist(5000001, make_pair(-1,-1));
  rep(i,n)rep(j,i) {
    i32 s = a[i] + a[j];
    auto [k, l] = hist[s];
    if (k >= 0) {
      if (i != k && k != j && l != j) {
        cout<<"YES"<<endl;
        cout<<(i+1)<<" "<<(j+1)<<" "<<(k+1)<<" "<<(l+1)<<endl;
        return 0;
      }
    } else {
      hist[s] = make_pair(i, j);
    }
  }
  cout<<"NO"<<endl;
  return 0;
}