#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  d = n - d;
  vector<int> vis(n);
  for (int s = 0; s < n; s++) {
    if (vis[s] == 1) {
      continue;
    }
    int cur = s;
    vector<int> cyc;
    while (vis[cur] == 0) {
      vis[cur] = 1;
      cyc.emplace_back(cur);
      cur = (cur + d) % n;
    }
    int bit = 1;
    for (auto i : cyc) {
      bit &= a[i];
    }
    if (bit == 1) {
      ans = -1;
      break;
    }
    int len = cyc.size();
    for (int i = 0; i < len; i++) {
      cyc.emplace_back(cyc[i]);
    }
    int last = 4 * n;
    vector<int> best(len, 1e9);
    for (int i = 2 * len - 1; i >= 0; i--) {
      if (a[cyc[i]] == 0) {
        last = i;
      }
      best[i % len] = min(best[i % len], last - i);
    }
    for (int i = 0; i < len; i++) {
      ans = max(ans, best[i]);
    }
  }
  cout << ans << '\n';
  return;
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