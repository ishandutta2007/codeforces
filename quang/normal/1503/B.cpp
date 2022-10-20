#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> odd, even;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) % 2) odd.push_back({i, j});
      else even.push_back({i, j});
    }
  }
  for (int i = 1; i <= n * n; i++) {
    int u;
    cin >> u;
    if (u == 1) {
      if (even.empty()) {
        cout << 3 << ' ' << odd.back().first << ' ' << odd.back().second << '\n';
        odd.pop_back();
      } else {
        cout << 2 << ' ' << even.back().first << ' ' << even.back().second << '\n';
        even.pop_back();
      }
    } else if (u == 2) {
      if (odd.empty()) {
        cout << 3 << ' ' << even.back().first << ' ' << even.back().second << '\n';
        even.pop_back();
      } else {
        cout << 1 << ' ' << odd.back().first << ' ' << odd.back().second << '\n';
        odd.pop_back();
      }
    } else {
      if (odd.empty()) {
        cout << 2 << ' ' << even.back().first << ' ' << even.back().second << '\n';
        even.pop_back();
      } else {
        cout << 1 << ' ' << odd.back().first << ' ' << odd.back().second << '\n';
        odd.pop_back();
      }
    }
  }
  return 0;
}