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

class CContinuousCity {
 public:
  void solveOne() {
    int l, r;
    cin >> l >> r;
    cout << "YES\n";
    vector<tuple<int, int, int>> edges;
    int n = 23;
    int need = r - l + 1;
    int next = l;
    for (int i = n; i >= n - 21; --i) {
      int p2 = 1 << max(0, n - i - 1);
      for (int j = i - 1; j >= n - 21; --j) {
        edges.emplace_back(j, i, p2);
      }
      if (i < n && (need & p2)) {
        if (next == 1) {
          int ne = edges.size();
          for (int j = 0; j < ne; ++j) {
            if (get<0>(edges[j]) == i) {
              edges.emplace_back(1, get<1>(edges[j]), get<2>(edges[j]));
            }
          }
        } else {
          edges.emplace_back(1, i, next - 1);
        }
        next += p2;
        need -= p2;
      }
    }
    assert(need == 0);
    cout << n << "\n";
    cout << edges.size() << "\n";
    for (auto e : edges) {
      cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << "\n";
    }
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
    CContinuousCity solver;


    solver.solve();
    return 0;
}