#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  lint k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  if (x > y) {
    r -= l;
    k -= l;
    if (k + y > r) {
      lint dd = (k + y - r) / y;
      dd -= 3;
      dd = max(dd, 0ll);
      dd = min(dd, k / x);
      k -= dd * x;
      t -= dd;
    }
    while (k + y > r && k - x >= 0) {
      k -= x;
      t -= 1;
    }
    if (k + y <= r) {
      t -= k / (x - y);
    }
    if (t <= 0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }    
    return;
  }
  vector<lint> dp(x, -1);
  bool all = true;
  queue<int> q;
  vector<pair<lint, lint>> to(x);
  vector<vector<pair<lint, lint>>> adj(x);
  for (lint i = 0; i < x; i++) {
    if (l + i + y > r) {
      all = false;
      dp[i] = 0;
      to[i] = {-1, -1};
      q.emplace(i);
    } else {
      lint cur = l + i + y;
      lint num = (i + y) / x;
      cur -= num * x;
      while (cur - x >= l) {
        cur -= x;
        num += 1;
      }
      to[i] = {cur - l, num};
      adj[cur - l].emplace_back(i, num);
    }
  }
  if (all) {
    cout << "Yes\n";
    return;
  }
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (auto [nxt, num] : adj[i]) {
      if (dp[nxt] == -1) {
        dp[nxt] = dp[i] + num;
        q.emplace(nxt);
      }
    }
  }

  lint dd = (k - l) / x;
  t -= dd;
  k -= dd * x;
  while (k - x >= l) {
    k -= x;
    t -= 1;
  }
  if (t <= 0 || dp[k - l] == -1 || dp[k - l] >= t) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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