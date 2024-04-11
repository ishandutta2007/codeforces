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
  vector a(n, vi32(m));
  vector b(n, vi32(m));
  rep(i,n)rep(j,m) cin>>a[i][j];
  rep(i,n)rep(j,m) cin>>b[i][j];
  using bs = bitset<1500>;
  vector<bs> breaking(m);
  vector<bs> strict(m);
  rep(j,m){
    bs brk, str;
    rep(i,n-1) {
      if (b[i][j] > b[i+1][j]) brk.set(i);
      if (b[i][j] < b[i+1][j]) str.set(i);
    }
    breaking[j] = brk;
    strict[j] = str;
  }
  vi32 ans;
  bs ok;
  vector<bool> used(m, false);
  rep(i,m) {
    bool finish = true;
    rep(j,m) {
      if (used[j]) continue;
      if ((breaking[j] & ~ok).none()) {
        ans.push_back(j);
        ok |= strict[j];
        used[j] = true;
      } else {
        finish = false;
      }
    }
    if (finish) break;
  }
  sort(all(a), [&] (auto&& lhs, auto&& rhs) {
      for (auto&& idx : ans) {
        if (lhs[idx] < rhs[idx]) return true;
        else if (lhs[idx] > rhs[idx]) return false;
      }
      return false;
  });
  if (a == b) {
    reverse(all(ans));
    i32 sz = size(ans);
    cout<<sz<<endl;
    rep(i,sz) {
      if(i)cout<<" ";
      cout<<(ans[i]+1);
    }
    cout<<endl;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}