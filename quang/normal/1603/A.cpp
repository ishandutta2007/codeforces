#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> nxt(n);
  for (int i = 0; i < n; i++) {
    nxt[i] = i - 1;
  }
  vector<bool> del(n, false);
  vector<int> id(n);
  iota(id.begin(), id.end(), 1);

  function<int(int)> GetNxt = [&](int u) {
    if (u == -1) return -1;
    return del[u] ? nxt[u] = GetNxt(nxt[u]) : u;
  };

  vector<int> st;
  for (int it = 0; it < n; it++) {
    auto cur = GetNxt(n - 1);
    while (cur >= 0 && a[cur] % (id[cur] + 1) == 0) cur = GetNxt(nxt[cur]);
    if (cur == -1) {
      cout << "NO\n";
      return;
    }
    del[cur] = 1;
    auto x = GetNxt(n - 1);
    while (x > cur) {
      id[x]--;
      x = GetNxt(nxt[x]);
    }
  }
  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}