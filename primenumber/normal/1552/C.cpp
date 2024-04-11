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
    i32 n,k;
    cin>>n>>k;
    vector<bool> used(2*n, false);
    vector<pair<i32,i32>> vc;
    rep(i,k) {
      i32 x,y;
      cin>>x>>y;
      --x;--y;
      if (x > y) swap(x, y);
      used[x] = true;
      used[y] = true;
      vc.emplace_back(x,y);
    }
    i32 re = n-k;
    i32 rv = 2*re;
    i32 ans = re * (re-1) / 2;
    for(auto&&[fr,to] : vc) {
      i32 cnt = 0;
      rep2(i,fr,to) {
        if (!used[i]) ++cnt;
      }
      ans += min(cnt, rv - cnt);
    }
    rep(i,k)rep(j,i) {
      auto&&[f0,t0] = vc[i];
      auto&&[f1,t1] = vc[j];
      if (f0 < f1 && f1 < t0 && t0 < t1) ++ans;
      else if (f1 < f0 && f0 < t1 && t1 < t0) ++ans;
    }
    cout<<ans<<"\n";
  }
  
  return 0;
}