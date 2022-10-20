#include <bits/stdc++.h>

using namespace std;

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
  assert(n == 1);
  vector<int> a(m);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int u, int v) {
    if (a[u] != a[v]) return a[u] < a[v];
    return u > v;
  });
  vector<int> pos(m);
  for (int i = 0; i < m; i++) {
    pos[order[i]] = i;
  }
  vector<int> has(m, 0);
  int res = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < pos[i]; j++) {
      res += has[j];
    }
    has[pos[i]]++;
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}