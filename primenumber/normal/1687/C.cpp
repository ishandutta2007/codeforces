#include <bits/stdc++.h>

#include <variant>

#define rep2(i, k, n) for (i64 i = (i64)(k); i < (i64)(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)
#ifdef ENV_LOCAL
#define dump \
  if (1) cerr
#else
#define dump \
  if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

// using namespace harudake;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 t;
  cin >> t;
  while (t--) {
    i64 n, m;
    cin >> n >> m;
    vi64 a(n);
    rep(i, n) cin >> a[i];
    vi64 b(n);
    rep(i, n) cin >> b[i];
    vi64 d(n);
    rep(i, n) d[i] = a[i] - b[i];
    vi64 ps(n + 1);
    partial_sum(all(d), begin(ps) + 1);
    vector<pair<i64, i64>> ranges;
    rep(i, m) {
      i64 l, r;
      cin >> l >> r;
      --l;
      ranges.emplace_back(l, r);
    }
    set<i64> rem;
    rep(i, n + 1) rem.insert(i);
    queue<pair<i64, i64>> qe;
    queue<i64> qi;
    rep(i, n + 1) {
      if (ps[i] == 0) {
        rem.erase(i);
        qi.push(i);
      }
    }
    map<i64, set<i64>> ltor, rtol;
    for (auto&& [l, r] : ranges) {
      ltor[l].insert(r);
      rtol[r].insert(l);
    }
    while (!qi.empty()) {
      i64 i = qi.front();
      dump << i << endl;
      qi.pop();
      for (auto&& r : ltor[i]) {
        if (rtol[r].count(i) == 0) {
          auto first = rem.lower_bound(i);
          auto last = rem.lower_bound(r);
          for (auto itr = first; itr != last; ++itr) {
            qi.push(*itr);
          }
          rem.erase(first, last);
        }
      }
      ltor[i].clear();
      for (auto&& l : rtol[i]) {
        if (ltor[l].count(i) == 0) {
          auto first = rem.lower_bound(l);
          auto last = rem.lower_bound(i);
          for (auto itr = first; itr != last; ++itr) {
            qi.push(*itr);
          }
          rem.erase(first, last);
        }
      }
      rtol[i].clear();
    }
    if (rem.empty()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}