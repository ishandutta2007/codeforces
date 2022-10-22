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
  i32 n,m;
  cin>>n>>m;
  vector<set<i32>> in(n), out(n);
  rep(i,m) {
    i32 u,v;
    cin>>u>>v;
    --u;--v;
    if (u > v) swap(u,v);
    out[u].insert(v);
    in[v].insert(u);
  }
  set<i32> rem;
  rep(i,n) {
    if (out[i].empty()) rem.insert(i);
  }
  i32 q;
  cin>>q;
  rep(qc,q) {
    i32 t;
    cin>>t;
    if (t == 1) {
      i32 u,v;
      cin>>u>>v;
      --u;--v;
      if (u > v) swap(u,v);
      if (out[u].empty()) rem.erase(u);
      out[u].insert(v);
      in[v].insert(u);
    } else if (t == 2) {
      i32 u,v;
      cin>>u>>v;
      --u;--v;
      if (u > v) swap(u,v);
      out[u].erase(v);
      in[v].erase(u);
      if (out[u].empty()) rem.insert(u);
    } else {
      cout<<size(rem)<<"\n";
    }
  }
  return 0;
}