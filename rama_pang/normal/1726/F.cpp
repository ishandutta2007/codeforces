#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint n, t;
  cin >> n >> t;
  vector<lint> g(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i] >> c[i];
  }
  vector<lint> d(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> d[i];
    if (i) d[i] += d[i - 1];
    c[i + 1] += d[i];
    c[i + 1] %= t;
  }    


  lint ans = 1e18;
  set<array<lint, 3>> intervals;
  set<array<lint, 3>> start_pos;
  intervals.insert({0, t - 1, n});
  const auto IntervalInsert = [&](lint a, lint b, lint c) {
    intervals.insert({a, b, c});
    if (c == -1) start_pos.insert({a, b, c});
  };
  const auto IntervalErase = [&](lint a, lint b, lint c) {
    intervals.erase({a, b, c});
    if (c == -1) start_pos.erase({a, b, c});
  };
  
  const auto Split = [&](lint a) {
    if (a == t) return;
    auto it = prev(intervals.lower_bound({a + 1, -1, -1}));
    auto x = *it;
    assert(x[0] <= a && a <= x[1]);
    IntervalErase(x[0], x[1], x[2]);
    if (x[0] <= a - 1) {
      IntervalInsert(x[0], a - 1, x[2]);
    }
    IntervalInsert(a, x[1], x[2]);
  };
  const auto Insert = [&](lint a, lint b, lint c) {
    Split(a);
    Split(b + 1);
    while (true) {
      auto it = intervals.lower_bound({a, -1, -1});
      if (it == end(intervals) || (*it)[0] > b) {
        break;
      }
      assert(a <= (*it)[0] && (*it)[1] <= b);
      IntervalErase((*it)[0], (*it)[1], (*it)[2]);
    }
    IntervalInsert(a, b, c);
  };
  vector<int> nxt(n, -1);
  for (int i = n - 1; i >= 0; i--) {
    lint lo = g[i] - c[i];
    lint hi = t - 1 - c[i];
    lo %= t; lo += t; lo %= t;
    hi %= t; hi += t; hi %= t;
    if (lo <= hi) {
      Insert(lo, hi, i);
    } else {
      Insert(lo, t - 1, i);
      Insert(0, hi, i);
    }
    lint p = (t - c[i]) % t;
    Split(p);
    nxt[i] = (*intervals.lower_bound({p, -1, -1}))[2];
  }

  vector<vector<pair<lint, lint>>> adj(n + 1);
  for (int i = 0; i < n; i++) {
    if (nxt[i] == n) {
      adj[nxt[i]].emplace_back(i, 0);
    } else {
      adj[nxt[i]].emplace_back(i, ((t - c[nxt[i]]) % t - (t - c[i]) % t + t) % t);
    }
  }
  vector<lint> dist(n + 1, -1);
  priority_queue<pair<lint, lint>> pq;
  const auto Relax = [&](lint u, lint dt) {
    if (dist[u] == -1 || dist[u] > dt) {
      dist[u] = dt;
      pq.emplace(-dt, u);
    }
  };
  Relax(n, 0);
  while (!pq.empty()) {
    auto [dt, u] = pq.top();
    dt *= -1;
    pq.pop();
    if (dist[u] != dt) {
      continue;
    }
    for (auto [v, w] : adj[u]) {
      Relax(v, dt + w);
    }
  }

  intervals.clear();
  IntervalInsert(0, t - 1, -1);
  for (int i = 0; i < n; i++) {
    if (!start_pos.empty()) {
      lint p = (t - c[i]) % t;
      Split(p + 1);
      auto it = start_pos.lower_bound({p + 1, -1, -1});
      if (it == begin(start_pos)) {
        it = prev(end(start_pos));
      } else {
        it--;
      }
      lint tm = (*it)[1];
      ans = min(ans, (p + t - tm) % t + dist[i]);    
      // for (auto [x, y, z] : start_pos) cout << x << ' ' << y << ' ' << z << " pos\n";
      // cout << p << '\n';
      // cout << i << ' ' << (p + t - tm) % t + dist[i] << '\n';
    }
    lint lo = g[i] - c[i];
    lint hi = t - 1 - c[i];
    lo %= t; lo += t; lo %= t;
    hi %= t; hi += t; hi %= t;
    if (lo <= hi) {
      Insert(lo, hi, i);
    } else {
      Insert(lo, t - 1, i);
      Insert(0, hi, i);
    }
  }
  if (!start_pos.empty()) ans = 0;

  // for (int i = 0; i < n - 1; i++) {
  //   // c[i] + cur >= g[i]
  //   // wait until c[i] + cur = 0
  //   // cur = -c[i]
  //   lint cur = (t - c[i]) % t;
  //   for (int j = i; j < n; j++) {
  //     if ((cur + c[i]) % t >= g[i]) {
  //       // g[i] <= cur + c[i] <= t - 1
  //       // g[i] <= cur + c[i] - t <= t - 1
  //     }
  //   }
  // }


  cout << d[n - 2] + ans << '\n';
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