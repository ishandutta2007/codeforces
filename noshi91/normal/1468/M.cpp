#include <cmath>
#include <iostream>
#include <map>
#include <vector>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> s(n);
  int m = 0;
  int c = 0;
  {
    std::map<int, int> comp;
    for (auto &v : s) {
      int k;
      std::cin >> k;
      m += k;
      v.resize(k);
      for (auto &e : v) {
        std::cin >> e;
        comp[e];
      }
    }
    for (auto &e : comp) {
      e.second = c++;
    }
    for (auto &v : s) {
      for (auto &e : v) {
        e = comp[e];
      }
    }
  }

  int th = std::sqrt(m);

  std::vector<int> used(c, 0);

  std::vector<std::vector<int>> occ(c);

  for (int i = 0; i != n; ++i) {
    if (s[i].size() < th) {
      for (auto e : s[i]) {
        occ[e].push_back(i);
      }
    } else {
      for (auto e : s[i]) {
        used[e] = 1;
      }
      for (int j = 0; j != n; ++j) {
        if (j == i) {
          continue;
        }
        int conf = 0;
        for (auto e : s[j]) {
          if (used[e]) {
            conf += 1;
          }
        }
        if (conf >= 2) {
          std::cout << i + 1 << " " << j + 1 << "\n";
          return;
        }
      }
      for (auto e : s[i]) {
        used[e] = 0;
      }
    }
  }

  std::fill(used.begin(), used.end(), -1);

  for (int x = 0; x != c; ++x) {
    for (auto i : occ[x]) {
      for (auto e : s[i]) {
        if (e == x) {
          continue;
        }
        if (used[e] != -1) {
          std::cout << used[e] + 1 << " " << i + 1 << "\n";
          return;
        }
        used[e] = i;
      }
    }
    for (auto i : occ[x]) {
      for (auto e : s[i]) {
        used[e] = -1;
      }
    }
  }

  std::cout << "-1\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int i = 0; i != t; ++i) {
    solve();
  }
  return 0;
}