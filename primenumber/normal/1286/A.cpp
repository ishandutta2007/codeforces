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
  i32 n;
  cin>>n;
  vi32 p(n);
  rep(i,n)cin>>p[i];
  vi32 r(2, 0);
  rep2(i,1,n+1) {
    bool has = false;
    rep(j,n) {
      if (p[j] == i) has = true;
    }
    if (!has) {
      ++r[i%2];
    }
  }
  i32 prev = -1;
  i32 pi = -1;
  vector<vi32> s(2);
  i32 ans = 0;
  rep(i,n) {
    if (p[i] == 0) continue;
    if (p[i] % 2 == prev) {
      if (pi < i-1) {
        s[p[i]%2].push_back(i - pi - 1);
      }
    } else if (prev >= 0) {
      ++ans;
    }
    prev = p[i] % 2;
    pi = i;
  }
  i32 fst = -1, lst = n;
  rep(i,n) {
    if (fst < 0 && p[i] > 0) {
      fst = i;
    }
    if (p[i] > 0) lst = i;
  }
  if (fst < 0) {
    if (n == 1) {
      cout<<0<<endl;
    } else {
      cout<<1<<endl;
    }
    return 0;
  }
  vector<vi32> e(2);
  if (fst > 0) e[p[fst]%2].push_back(fst);
  if (lst < n-1) e[p[lst]%2].push_back(n-1-lst);
  rep(i,2) {
    sort(all(s[i]));
    for(auto&&len:s[i]) {
      if (len <= r[i]) {
        r[i] -= len;
      } else {
        ans += 2;
      }
    }
    sort(all(e[i]));
    for(auto&&len:e[i]) {
      if (len <= r[i]) {
        r[i] -= len;
      } else {
        ans += 1;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}