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
    i32 n;
    cin>>n;
    map<i32,i32> cnt;
    rep(i,n){
      i32 x;
      cin>>x;
      for (i32 j=2; j*j <= x; ++j) {
        while ((x % (j*j)) == 0) {
          x /= j*j;
        }
      }
      ++cnt[x];
    }
    i32 r0 = 0;
    map<i32,i32> cnt1;
    for (auto&&[k,v] : cnt) {
      r0 = max(r0, v);
      if (v % 2 == 0) {
        cnt1[1] += v;
      } else {
        cnt1[k] += v;
      }
    }
    i32 r1 = 0;
    for (auto&&[k,v] : cnt1) {
      r1 = max(r1, v);
    }
    i32 q;
    cin>>q;
    rep(qc,q) {
      i64 w;
      cin>>w;
      if (w > 0) {
        cout<<r1<<"\n";
      } else {
        cout<<r0<<"\n";
      }
    }
  }
  return 0;
}