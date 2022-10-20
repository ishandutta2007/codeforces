#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(n, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '1') {
        a[i] |= (1ll << j);
      }
    }
  }
  vector<int> order(n, 0);
  long long res = 0;
  iota(order.begin(), order.end(), 0);
  shuffle(order.begin(), order.end(), rng);
  for (int it = 0; it < min((int)order.size(), 30); ++it) {
    int id = order[it];
    vector<int> pos;
    for (int i = 0; i < m; ++i) {
      if (a[id] >> i & 1) pos.push_back(i);
    }
    if (pos.empty()) continue;
    vector<int> dp(1 << pos.size(), 0);
    for (int i = 0; i < n; ++i) {
      int cur_mask = 0;
      for (int j = 0; j < pos.size(); ++j) {
        if (a[i] >> pos[j] & 1) cur_mask |= (1 << j);
      }
      dp[cur_mask]++;
    }
    for (int i = 0; i < pos.size(); i++) {
      for (int mask = 0; mask < (1 << pos.size()); mask++) {
        if (mask >> i & 1) {
          int sub_mask = mask ^ (1 << i);
          dp[sub_mask] += dp[mask];
        }
      }
    }
    for (int mask = 0; mask < (1 << pos.size()); mask++) {
      if (dp[mask] * 2 >= n) {
        if (__builtin_popcount(mask) > __builtin_popcountll(res)) {
          res = 0;
          for (int i = 0; i < pos.size(); i++) {
            if (mask >> i & 1) {
              res |= (1ll << pos[i]);
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < m; i++) cout << (res >> i & 1);
  cout << '\n';
  return 0;
}