/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

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

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

class ETreeCalendar {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      --x;
    }
    vector<int> p(n, -1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      assert(p[v] < 0);
      p[v] = u;
    }
    assert(p[0] == -1);
    int lead = -1;
    for (int i = 1; i < n; ++i) if (a[i] < a[p[i]]) {
      lead = max(lead, a[i]);
    }
    vector<int> where(n, -1);
    for (int i = 0; i < n; ++i) where[a[i]] = i;
    if (a[0] != lead + 1) {
      cout << "NO\n";
      return;
    }
    int64 time = 0;
    while (lead >= 0) {
      int next = a[p[where[lead]]];
      while (where[lead] > 0) {
        int i = where[lead];
        int j = p[i];
        if (a[j] != next) {
          cout << "NO\n";
          return;
        }
        swap(a[j], a[i]);
        where[a[i]] = i;
        where[a[j]] = j;
        --next;
        ++time;
      }
      --lead;
      break;
    }

    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) children[p[i]].push_back(i);
    for (int i = 0; i < n; ++i) {
      sort(all(children[i]), [&](int u, int v) {
        return a[u] < a[v];
      });
    }
    int pos = 0;
    int pos2 = 0;
    vector<int> b(n, -1);
    vector<int> c(n, -1);
    vector<int> depth(n, 0);
    auto dfs = [&](const auto& self, int at) {
      if (at < 0) return;
      b[at] = pos;
      ++pos;
      for (int x : children[at]) {
        depth[x] = depth[at] + 1;
        self(self, x);
      }
      c[at] = pos2;
      ++pos2;
    };
    dfs(dfs, 0);
    assert(pos == n);

    for (int i = 0; i <= lead; ++i) {
      if (c[where[i]] != i) {
        cout << "NO\n";
        return;
      }
      time += depth[where[i]];
    }
    for (int i = lead + 2; i < n; ++i) {
      if (b[where[i - 1]] > b[where[i]]) {
        cout << "NO\n";
      }
    }

    cout << "YES\n";
    cout << time << "\n";
    for (int i = 0; i < n; ++i) cout << (b[i] + 1) << " ";
    cout << "\n";
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ETreeCalendar solver;


    solver.solve();
    return 0;
}