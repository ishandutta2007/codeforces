#include <bits/stdc++.h>
using namespace std;

void Main() {

  int n;
  cin >> n;

  const auto Solve = [&](const auto &self, int n) -> vector<pair<int, int>> {
    if (n == 0) return {};
    if (n % 3 == 0 || n % 3 == 1) {
      vector<pair<int, int>> ret = self(self, n - 1);
      ret.emplace_back(n - 1, n - 1);
      return ret;
    }
    vector<pair<int, int>> ret;
    ret.emplace_back(0, 0);
    int H = n / 3;
    for (int i = 1; i <= H; i++) {
      ret.emplace_back(i, 2 * i);
    }
    for (int i = 1; i <= H; i++) {
      ret.emplace_back(H + i, i * 2 - 1);
    }
    return ret;
  };
  auto ret = Solve(Solve, n);
  const auto Check = [&](vector<pair<int, int>> ls) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        int ok = 0;
        for (auto [i, j] : ls) {
          if (x == i || y == j || x - y == i - j) {
            ok = 1;
            break;
          }
        }
        if (!ok) {
          return false;
        }
      }
    }
    return true;
  };
  // assert(Check(ret));
  cout << ret.size() << '\n';
  for (auto [x, y] : ret) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
  return;
  // for (int k = 1; k <= n; k++) {
  //   vector<pair<int, int>> ls;
  //   const auto Dfs = [&](const auto &self, int pos, int tiles) {
  //     if (tiles < 0) return false;
  //     if (pos == n * n) {
  //       if (tiles != 0) return false;
  //       for (int x = 0; x < n; x++) {
  //         for (int y = 0; y < n; y++) {
  //           int ok = 0;
  //           for (auto [i, j] : ls) {
  //             if (x == i || y == j || x - y == i - j) {
  //               ok = 1;
  //               break;
  //             }
  //           }
  //           if (!ok) {
  //             return false;
  //           }
  //         }
  //       }
  //       for (auto [i, j] : ls) {
  //         cout << i << ' ' << j << '\n';
  //       }
  //       return true;
  //     }
  //     int x = pos / n;
  //     int y = pos % n;
  //     ls.emplace_back(x, y);
  //     bool b = self(self, pos + 1, tiles - 1);
  //     ls.pop_back();
  //     if (b) return true;
  //     if (self(self, pos + 1, tiles)) return true;
  //     return b;
  //   }; 
  //   if (Dfs(Dfs, 0, k)) {
  //     cout << k << '\n';
  //     break;
  //   }
  // }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    Main();
  }
  return 0;
}
/*
1 1
2 1
3 2

4 3
5 3
6 4

7 5
8 5
9 6

10 7
11 7
12 8

2/3

*/