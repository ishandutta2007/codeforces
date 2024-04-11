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
  while (t--) {
    i32 n;
    cin>>n;
    vector<double> miner, diamond;
    rep(i,2*n) {
      i32 x,y;
      cin>>x>>y;
      if (x == 0) {
        miner.push_back(abs(y));
      } else {
        diamond.push_back(abs(x));
      }
    }
    sort(all(miner));
    sort(all(diamond));
    double s = 0.;
    rep(i,n) {
      s += sqrt(miner[i]*miner[i] + diamond[i]*diamond[i]);
    }
    cout<<fixed<<setprecision(15)<<s<<"\n";
  }
  return 0;
}