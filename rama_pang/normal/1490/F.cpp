#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    vector<int> freq;
    vector<int> can(n + 1);
    for (auto i : mp) can[i.second] = 1, freq.emplace_back(i.second);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      if (!can[i]) {
        continue;
      }
      int cost = 0;
      for (auto j : freq) {
        if (j < i) {
          cost += j;
        } else {
          cost += j - i;
        }
      }
      ans = min(ans, cost);
    }
    cout << ans << '\n';
  }
  return 0;
}