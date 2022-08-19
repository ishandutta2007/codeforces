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

class DXOROzhdestvenskoeDerevo {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      adj[a].emplace_back(b, c);
      adj[b].emplace_back(a, c);
    }
    vector<vector<ii>> padj(n);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      padj[a].emplace_back(b, c);
      padj[b].emplace_back(a, c);
    }
    vector<int> p(n, -1);
    auto dfs = [&](auto self, int root, int parity) {
      if (p[root] >= 0) {
        if (p[root] != parity) return false;
        return true;
      }
      p[root] = parity;
      for (ii x : adj[root]) {
        if (x.second >= 0) {
          if (!self(self, x.first, parity ^ (__builtin_popcount(x.second) & 1))) {
            return false;
          }
        }
      }
      for (ii x : padj[root]) {
        if (!self(self, x.first, parity ^ (__builtin_popcount(x.second) & 1))) {
          return false;
        }
      }
      return true;
    };
    for (int i = 0; i < n; ++i) if (p[i] < 0) {
      if (!dfs(dfs, i, 0)) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (ii x : adj[i]) {
        if (i > x.first) continue;
        cout << (i + 1) << " " << (x.first + 1) << " ";
        if (x.second >= 0) cout << x.second; else cout << (p[i] ^ p[x.first]);
        cout << "\n";
      }
    }
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
    DXOROzhdestvenskoeDerevo solver;


    solver.solve();
    return 0;
}