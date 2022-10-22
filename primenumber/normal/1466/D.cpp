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
    vi64 w(n);
    rep(i,n)cin>>w[i];
    vi64 deg(n);
    rep(i,n-1) {
      i32 u,v;
      cin>>u>>v;
      --u;--v;
      ++deg[u];
      ++deg[v];
    }
    vi64 val;
    rep(i,n) {
      rep(j,deg[i]-1) {
        val.push_back(w[i]);
      }
    }
    while (size(val) < n) val.push_back(0);
    sort(all(val));
    reverse(all(val));
    i64 sum = 0;
    rep(i,n) sum += w[i];
    rep(i,n-1) {
      if(i)cout<<" ";
      cout<<sum;
      sum += val[i];
    }
    cout<<"\n";
  }
  return 0;
}