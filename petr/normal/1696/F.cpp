/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#undef NDEBUG

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
// AtCoder library from https://github.com/atcoder/ac-library
// #include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

class FTreeRecovery {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<vector<string>> d(n);
    for (int i = 0; i < n; ++i) {
      d[i].resize(n - 1 - i);
      for (auto& x : d[i]) cin >> x;
    }

    vector<vector<int>> adj(n);
    vector<bool> mark(n);

    auto build = [&](auto self, int at, int neigh) -> void {
      assert(!mark[at]);
      mark[at] = true;
      for (int i = 0; i < n; ++i) if (!mark[i]) {
        if (i == neigh || d[min(neigh, i)][max(neigh, i) - min(neigh, i) - 1][at] == '1') {
          adj[at].push_back(i);
          adj[i].push_back(at);
          self(self, i, at);
        }
      }
    };

    vector<int> dist(n);
    auto dfs = [&](auto self, int at, int skip, int cd) -> void {
      dist[at] = cd;
      for (int i : adj[at]) {
        if (i == skip) continue;
        self(self, i, at, cd + 1);
      }
    };

    for (int b = 1; b < n; ++b) {
      adj.assign(n, vector<int>());
      mark.assign(n, false);
      build(build, 0, b);
      bool ok = true;
      for (bool x : mark) if (!x) ok = false;
      for (int root = 0; root < n && ok; ++root) {
        dist.assign(n, -1);
        dfs(dfs, root, -1, 0);
        for (int i = 0; i < n && ok; ++i) {
          for (int j = i + 1; j < n && ok; ++j) {
            bool expected = d[i][j - i - 1][root] == '1';
            bool actual = dist[i] == dist[j];
            if (expected != actual) {
              ok = false;
            }
          }
        }
      }
      if (ok) {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) {
          for (int j : adj[i]) {
            if (i < j) cout << (i + 1) << " " << (j + 1) << "\n";
          }
        }
        return;
      }
    }
    cout << "No\n";
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      // cout << "Case #" << (it + 1) << ": ";
      solveOne();
    }
  }
};

// #define st_mtimespec st_mtim

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    FTreeRecovery solver;


    solver.solve();
    return 0;
}