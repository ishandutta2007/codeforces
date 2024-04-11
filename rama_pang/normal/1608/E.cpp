#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<int> coordX, coordY;
  vector<vector<pair<int, int>>> A(3);
  for (int i = 0; i < N; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    coordX.emplace_back(x);
    coordY.emplace_back(y);
    A[--c].emplace_back(x, y);
  }
  sort(begin(coordX), end(coordX));
  coordX.resize(unique(begin(coordX), end(coordX)) - begin(coordX));
  sort(begin(coordY), end(coordY));
  coordY.resize(unique(begin(coordY), end(coordY)) - begin(coordY));
  for (int i = 0; i < 3; i++) {
    for (auto &j : A[i]) {
      j.first = lower_bound(begin(coordX), end(coordX), j.first) - begin(coordX);
      j.second = lower_bound(begin(coordY), end(coordY), j.second) - begin(coordY);
    }
  }
  int sz = 1;
  while (sz < N) sz *= 2;
  vector<array<int, 2>> tree(2 * sz);
  vector<vector<array<int, 3>>> event(N);
  const auto Update = [&](int p, int t) {
    for (p += sz; p > 0; p /= 2) {
      tree[p][t] += 1;
    }
  };
  const auto Query = [&]() {
    int n = 1;
    int lft = 0, rgt = 0;
    while (n < sz) {
      if (lft + tree[n * 2][0] <= rgt + tree[n * 2 + 1][1]) {
        lft += tree[n * 2][0];
        n = n * 2 + 1;
      } else {
        rgt += tree[n * 2 + 1][1];
        n = n * 2;
      }
    }
    assert(sz <= n && n < sz + sz);
    return max(min(lft, rgt + tree[n][1]), min(lft + tree[n][0], rgt));
  };
  const auto Solve = [&]() -> int {
    for (int i = 0; i < N; i++) event[i].clear();
    for (int i = 0; i < 2 * sz; i++) tree[i] = {0, 0};
    for (int i = 0; i < 3; i++) {
      for (auto [x, y] : A[i]) {
        event[x].push_back({i, x, y});
      }
    }
    int res = 0;
    int cnt = N / 3;
    for (int xid = N - 1; xid >= 0; xid--) {
      for (auto [i, x, y] : event[xid]) {
        if (i == 1 || i == 2) {
          Update(y, i - 1);
        } else {
          cnt--;
        }
      }
      res = max(res, min(cnt, Query()));
    }
    cnt = N / 3;
    for (int i = 0; i < 2 * sz; i++) tree[i] = {0, 0};
    for (int xid = N - 1; xid >= 0; xid--) {
      for (auto [i, x, y] : event[xid]) {
        if (i == 1 || i == 2) {
          Update(x, i - 1);
        } else {
          cnt--;
        }
      }
      res = max(res, min(cnt, Query()));
    }
    return res;
  };
  int ans = 0;
  for (int r = 0; r < 4; r++) {
    auto orig = A;
    A = {orig[0], orig[1], orig[2]};
    ans = max(ans, Solve());
    A = {orig[0], orig[2], orig[1]};
    ans = max(ans, Solve());
    A = {orig[1], orig[0], orig[2]};
    ans = max(ans, Solve());
    A = {orig[1], orig[2], orig[0]};
    ans = max(ans, Solve());
    A = {orig[2], orig[0], orig[1]};
    ans = max(ans, Solve());
    A = {orig[2], orig[1], orig[0]};
    ans = max(ans, Solve());
    A = orig;
    for (int i = 0; i < 3; i++) {
      for (auto &j : A[i]) {
        swap(j.first, j.second);
        j.first = N - 1 - j.first;
      }
    }
  }
  cout << ans * 3 << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}