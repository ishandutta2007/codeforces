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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    i64 w;
    cin>>n>>w;
    vector<pair<i64,i64>> m;
    rep(i,n) {
      i64 v;
      cin>>v;
      if (v > w) continue;
      m.emplace_back(v,i+1);
    }
    n = size(m);
    if (n == 0) {
      cout<<-1<<"\n";
      continue;
    }
    i64 h = (w + 1) / 2;
    auto itr = max_element(all(m));
    if (itr->first >= h) {
      cout<<1<<"\n";
      cout<<(itr->second)<<"\n";
    } else {
      vi64 ans;
      i64 s = 0;
      rep(i,n) {
        s += m[i].first;
        ans.push_back(m[i].second);
        if (s >= h) {
          break;
        }
      }
      if (s < h) {
        cout<<-1<<"\n";
      } else {
        cout<<size(ans)<<"\n";
        i32 s=size(ans);
        rep(i,s) {
          if(i)cout<<" ";
          cout<<ans[i];
        }
        cout<<"\n";
      }
    }
  }
  return 0;
}