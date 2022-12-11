#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

set<int> e[N];
int idx[N];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    e[a].insert(b);
    e[b].insert(a);
  }

  int u = 1;
  for (int i = 2; i <= n; ++i) {
    if (e[i].size() < e[u].size()) {
      u = i;
    }
  }

  set<int> x, y;
  for (int i = 1; i <= n; ++i) {
    if (i != u) {
      (e[u].count(i) ? x : y).insert(i);
    }
  }

  int ans = 0;
  vector<int> p;
  while (!x.empty() || !y.empty()) {
    ans += y.empty();
    auto& s = (y.empty() ? x : y);
    const int v = *s.begin();
    s.erase(s.begin());
    p.clear();
    for (int w : x) {
      if (!e[v].count(w)) {
        p.push_back(w);
      }
    }
    for (int w : p) {
      x.erase(w);
      y.insert(w);
    }
  }

  cout << ans << endl;

  return 0;
}