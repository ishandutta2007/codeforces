#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    set<pair<pair<int, int>, pair<int, int>>> used;
    int x = 0, y = 0;
    int ans = 0;

    for (auto i : s) {
      int nx = x, ny = y;
      if (i == 'S') ny--;
      if (i == 'N') ny++;
      if (i == 'W') nx--;
      if (i == 'E') nx++;

      if (used.count({{x, y}, {nx, ny}})) {
        ans += 1;
      } else {
        ans += 5;
      }

      used.insert({{x, y}, {nx, ny}});
      used.insert({{nx, ny}, {x, y}});

      x = nx;
      y = ny;
    }

    cout << ans << "\n";
  }
}