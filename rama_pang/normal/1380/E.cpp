#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<set<int>> towers(m);
  vector<int> tid(m);
  iota(begin(tid), end(tid), 0);
  function<int(int)> Find = [&](int x) {
    return tid[x] == x ? x : tid[x] = Find(tid[x]);
  };
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    towers[a].emplace(i);
  }
  int ans = n;
  for (auto &i : towers) {
    for (auto j : i) {
      if (i.count(j + 1) == 1) {
        ans--;
      }
    }
  }

  cout << ans - 1 << "\n";
  for (int qi = 1; qi < m; qi++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    x = Find(x), y = Find(y);
    assert(x != y);
    tid[y] = x;
    if (towers[x].size() < towers[y].size()) {
      swap(towers[x], towers[y]);
    }
    auto &t = towers[x];
    for (auto i : towers[y]) {
      int prv = i - 1;
      int nxt = i + 1;
      if (t.count(prv) == 1) {
        ans--;
      }
      if (t.count(nxt) == 1) {
        ans--;
      }
    }
    for (auto i : towers[y]) {
      t.emplace(i);
    }
    towers[y].clear();
    cout << ans - 1 << "\n";
  }
  return 0;
}