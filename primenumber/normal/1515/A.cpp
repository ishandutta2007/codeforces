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
    i32 n,x;
    cin>>n>>x;
    vi32 w(n);
    rep(i,n) cin>>w[i];
    sort(all(w));
    vi32 ps(n);
    partial_sum(all(w), begin(ps));
    auto itr = lower_bound(all(ps), x);
    if (itr != end(ps) && *itr == x) {
      i32 idx = itr - begin(ps);
      if (idx == n-1) {
        cout<<"NO\n";
        continue;
      } else {
        swap(w[idx], w[idx+1]);
      }
    }
    cout<<"YES\n";
    rep(i,n) {
      if(i)cout<<" ";
      cout<<w[i];
    }
    cout<<"\n";
  }
  return 0;
}