#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n;
int to[N];
int in_a[N];
int a[N], b[N];
set<int> s;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    to[u] = v;
    to[v] = u;
    in_a[u] = 1;
    s.insert(u);
    s.insert(v);
  }
  int l = 1, r = n;
  int res = 0;
  while (!s.empty()) {
    int cur_swap = 0;
    int tot = 0;
    auto u = *s.begin();
    int v = to[u];

    // cout << "start " << endl;

    auto AddPair = [&](int u, int v, int pos) {
      // cout << "add edge " << u << ' ' << v << ' ' << pos << endl;
      a[pos] = u;
      b[pos] = v;
      s.erase(u);
      s.erase(v);
      cur_swap += in_a[v];
      tot++;
    };

    AddPair(u, v, l++);
    int low = 0, high = v;
    while (1) {
      bool f = false;
      while (!s.empty() && *s.rbegin() > high) {
        int u = *s.rbegin();
        int v = to[u];
        AddPair(u, v, r--);
        low = max(low, v);
        f = true;
      }
      while (!s.empty() && *s.begin() < low) {
        int u = *s.begin();
        int v = to[u];
        AddPair(u, v, l++);
        high = min(high, v);
        f = true;
      }
      if (!f) break;
    }
    res += min(cur_swap, tot - cur_swap);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << ' ';
  // }
  // cout << endl;
  // for (int i = 1; i <= n; i++) {
  //   cout << b[i] << ' ';
  // }
  // cout << endl;

  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
    if (b[i] <= b[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << res << endl;
  return 0;
}