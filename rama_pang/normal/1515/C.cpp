#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(begin(a), end(a));
  reverse(begin(a), end(a));

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < m; i++) pq.emplace(a[i]);

  vector<int> par(n);
  iota(begin(par), end(par), 0);
  function<int(int)> Find = [&](int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
  };

  for (int i = m; i < n; i++) {
    auto s2 = pq.top(); pq.pop();
    auto s1 = a[i];
    assert(Find(s1.second) != Find(s2.second));
    par[Find(s1.second)] = Find(s2.second);
    s2.first += s1.first;
    pq.emplace(s2);  
  }

  lint sml = 1e18;
  lint big = -1e18;
  while (!pq.empty()) {
    sml = min(sml, 1ll * pq.top().first);
    big = max(big, 1ll * pq.top().first);
    pq.pop();
  }

  assert(big - sml <= x);

  vector<int> ok;
  for (int i = 0; i < n; i++) if (Find(i) == i) ok.emplace_back(i);

  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(begin(ok), end(ok), Find(i)) - begin(ok);
    cout << it + 1 << ' ';
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