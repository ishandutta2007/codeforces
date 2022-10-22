#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

void solve() {
  i64 n,m,k;
  cin>>n>>m>>k;
  vector<unordered_set<i32>> g(n);
  rep(i,m) {
    i32 u,v;
    cin>>u>>v;
    --u;--v;
    g[u].insert(v);
    g[v].insert(u);
  }
  if (k * (k-1) / 2 > m) {
    cout<<-1<<"\n";
    return;
  }
  set<pair<i32,i32>> sci;
  rep(i,n) {
    sci.emplace(size(g[i]), i);
  }
  while (!sci.empty()) {
    auto [cnt, idx] = *begin(sci);
    if (cnt == k-1) {
      bool ok = true;
      for (auto&& to1 : g[idx]) {
        for (auto&& to2 : g[idx]) {
          if (to1 == to2) break;
          if (g[to1].count(to2) == 0) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) {
        cout<<2<<"\n";
        cout<<(idx+1);
        for(auto&&to : g[idx]) {
          cout<<" "<<(to+1);
        }
        cout<<"\n";
        return;
      }
    } else if (cnt >= k) {
      break;
    }
    for (auto&&to : g[idx]) {
      sci.erase(make_pair(size(g[to]), to));
      g[to].erase(idx);
      sci.emplace(size(g[to]), to);
    }
    sci.erase(make_pair(cnt, idx));
    g[idx].clear();
  }
  if (sci.empty()) {
    cout<<-1<<"\n";
  } else {
    cout<<1<<" "<<size(sci)<<"\n";
    bool first = true;
    for(auto&&[cnt,idx] : sci) {
      if (first) {
        first = false;
      } else {
        cout<<" ";
      }
      cout<<(idx+1);
    }
    cout<<"\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    solve();
  }
  return 0;
}