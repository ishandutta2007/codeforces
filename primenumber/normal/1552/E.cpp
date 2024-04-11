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
  i32 n,k;
  cin>>n>>k;
  i32 mx = (n + k - 2) / (k - 1);
  vi32 c(n*k);
  rep(i,n*k) cin>>c[i];
  rep(i,n*k) --c[i];
  using T = pair<i32,i32>;
  vector<queue<T>> vq(n);
  vi32 prev(n, -1);
  rep(i,n*k) {
    if (prev[c[i]] >= 0) {
      vq[c[i]].emplace(prev[c[i]], i);
    }
    prev[c[i]] = i;
  }
  vector<bool> used(n, false);
  vi32 last(mx, -1);
  vector<pair<i32,i32>> ans(n);
  rep(i,n) {
    i32 j = i % mx;
    i32 mn = n*k;
    i32 mnk = -1;
    rep(k,n) {
      if (used[k]) continue;
      while (true) {
        auto[fr,to] = vq[k].front();
        if (fr < last[j]) {
          vq[k].pop();
          continue;
        }
        if (to < mn) {
          mn = to;
          mnk = k;
        }
        break;
      }
    }
    ans[mnk] = vq[mnk].front();
    vq[mnk].pop();
    used[mnk] = true;
    last[j] = mn;
  }
  rep(i,n) {
    auto[fr,to] = ans[i];
    ++fr;++to;
    cout<<fr<<" "<<to<<endl;
  }
  return 0;
}