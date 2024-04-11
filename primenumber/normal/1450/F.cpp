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
    vi32 hist(n+1, 0);
    ++hist[a.front()];
    ++hist[a.back()];
    i32 need = 0;
    rep(i,n-1) {
      if (a[i] == a[i+1]) {
        hist[a[i]] += 2;
        ++need;
      }
    }
    i32 mode = max_element(all(hist)) - begin(hist);
    if (hist[mode] - 2 <= need) {
      cout<<need<<endl;
      continue;
    }
    i32 can = 0;
    rep(i,n-1) {
      if (a[i] != a[i+1] && a[i] != mode && a[i+1] != mode) {
        ++can;
      }
    }
    i32 rem = hist[mode] - 2 - need;
    if (rem <= can) {
      cout<<need + rem<<endl;
    } else {
      cout<<-1<<endl;
    }
  }
  return 0;
}