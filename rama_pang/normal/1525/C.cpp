#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, char>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  vector<int> ans(n, -1);

  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return a[i] < a[j];
  });
  vector<int> posord(n);
  for (int i = 0; i < n; i++) posord[ord[i]] = i;

  sort(begin(a), end(a));

  for (int rep = 0; rep < 2; rep++) {
    vector<int> ids;
    for (int i = 0; i < n; i++) {
      if (a[i].first % 2 == rep) {
        ids.emplace_back(i);
      }
    }
    const auto GetTime = [&](int i, int j) {
      assert(i < j);
      int x = a[i].first, y = a[j].first;
      char dx = a[i].second, dy = a[j].second;
      int t = 0;
      while (dx != 'R' || dy != 'L') {
        int nxtTime = 1e9;
        if (dx == 'L') nxtTime = min(nxtTime, x);
        if (dy == 'R') nxtTime = min(nxtTime, m - y);
        if (dx == 'L') {
          x -= nxtTime;
        } else {
          x += nxtTime;
        }
        if (dy == 'L') {
          y -= nxtTime;
        } else {
          y += nxtTime;
        }
        t += nxtTime;
        if (x == 0) dx = 'R';
        if (y == m) dy = 'L';
      }
      return t + abs(x - y) / 2;
    };
    priority_queue<array<int, 3>> pq;
    set<int> active;
    for (auto i : ids) active.emplace(i);
    vector<int> done(n);
    for (int i = 1; i < int(ids.size()); i++) {
      int u = ids[i - 1];
      int v = ids[i];
      pq.push({-GetTime(u, v), u, v});
    }
    while (!pq.empty()) {
      auto [t, u, v] = pq.top(); pq.pop(); t *= -1;
      if (done[u] || done[v]) continue;
      done[u] = 1;
      done[v] = 1;
      ans[u] = t;
      ans[v] = t;
      auto prv = active.find(u);
      auto nxt = active.find(v);
      if (prv != begin(active) && next(nxt) != end(active)) {
        int x = *prev(prv);
        int y = *next(nxt);
        pq.push({-GetTime(x, y), x, y});
      }
      active.erase(u);
      active.erase(v);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[posord[i]] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}