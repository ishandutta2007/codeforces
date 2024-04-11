#include <bits/stdc++.h>

using namespace std;

const int N = 200010;


void Solve(int test) {
  int a, b;
  cin >> a >> b;

  set<pair<int, int>> s;  
  queue<pair<int, int>> q;
  set<int> res;
  q.push({(a + 1) / 2, (a + b + 1) / 2 - (a + 1) / 2});
  s.insert({(a + 1) / 2, (a + b + 1) / 2 - (a + 1) / 2});
  q.push({a / 2, (a + b) / 2 - a / 2});
  s.insert({a / 2, (a + b) / 2 - a / 2});

  while (!q.empty()) {
    auto [u, v] = q.front();
    res.insert(a - u + v);
    q.pop();
    // 0 1
    if (u > 0 && v < b && !s.count({u - 1, v + 1})) {
      s.insert({u - 1, v + 1});
      q.push({u - 1, v + 1});
    }
    // 1 0
    if (u < a && v > 0 && !s.count({u + 1, v - 1})) {
      s.insert({u + 1, v - 1});
      q.push({u + 1, v - 1});
    }
  }

  cout << res.size() << '\n';
  for (auto u : res) {
    cout << u << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}