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
  while (t--) {
    i32 n;
    cin>>n;
    vi32 a(n);
    rep(i,n)cin>>a[i];
    vi32 b(all(a));
    sort(all(b));
    vector<bool> ans(n+1, true);
    rep(i,n) {
      if (b[i] != i+1) ans[1] = false;
    }
    ans[n] = *min_element(all(a)) == 1;
    i32 l = 0, r = n-1;
    set<pair<i32,i32>> sv;
    rep(i,n) {
      sv.emplace(a[i],i);
    }
    rep(i,n-2) {
      if (!ans[n-i]) {
        ans[n-1-i] = false;
        continue;
      }
      i32 need = i+1;
      bool left = a[l] == need;
      bool right = a[r] == need;
      if (left && right) {
        ans[n-1-i] = false;
        continue;
      }
      if (left) {
        sv.erase(make_pair(need, l));
        if (begin(sv)->first != need+1) {
          ans[n-1-i] = false;
          continue;
        }
        ++l;
      }
      if (right) {
        sv.erase(make_pair(need, r));
        if (begin(sv)->first != need+1) {
          ans[n-1-i] = false;
          continue;
        }
        --r;
      }
      if (!left && !right) {
        ans[n-1-i] = false;
      }
    }
    rep2(i,1,n+1) {
      cout<<ans[i];
    }
    cout<<"\n";
  }
  return 0;
}