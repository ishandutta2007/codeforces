#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class BIT {
 public:
  explicit BIT(int n) : n_(n), t_(n, T(0)) {}

  void Add(int x, T v) {
    assert(x >= 0);
    for (; x < n_; x += (x + 1) & -(x + 1)) t_[x] += v;
  }

  // [l, r] INCLUSIVELY
  void Add(int l, int r, T v) {
    assert(l <= r && l >= 0 && r < n_);
    Add(l, v);
    Add(r + 1, -v);
  }

  T Get(int x) const {
    assert(x >= 0 && x < n_);
    T res(0);
    for (; x >= 0; x -= (x + 1) & -(x + 1)) res += t_[x];
    return res;
  }

  // [l, r] INCLUSIVELY
  T Get(int l, int r) const {
    assert(l <= r && r < n_ && l >= 0);
    return Get(r) - (l ? Get(l - 1) : T(0));
  }

 private:
  int n_;
  vector<T> t_;
};

void Solve(int test) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> ls;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c;
      cin >> c;
      ls.push_back({c, {i, j}});
    }
  }
  long long res = 0;
  sort(ls.begin(), ls.end());
  BIT<int> num_t(m);
  BIT<long long> sum_t(m);
  for (int l = 0, r = 0; l < ls.size(); l = r) {
    while (r < ls.size() && ls[l].first == ls[r].first) r++;
    vector<int> changed;
    int num = 0;
    long long sum = 0;
    for (int i = l; i < r; i++) {
      auto [u, v] = ls[i].second;
      res += 1ll * u * num - sum;
      auto num_l = num_t.Get(v);
      auto num_r = num_t.Get(m - 1) - num_l;
      auto sum_l = sum_t.Get(v);
      auto sum_r = sum_t.Get(m - 1) - sum_l;
      res += 1ll * v * num_l - sum_l;
      res += sum_r - 1ll * v * num_r;
      num_t.Add(v, 1);
      sum_t.Add(v, v);
      num++;
      sum += u;
      changed.push_back(v);
    }
    for (auto v : changed) {
      num_t.Add(v, -1);
      sum_t.Add(v, -v);
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;

  tc = 1;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}