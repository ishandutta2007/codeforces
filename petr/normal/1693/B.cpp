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

constexpr int INF = (int) 1.01e9;

class BFakePlasticTrees {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> p(n, -1);
    for (int i = 1; i < n; ++i) {
      cin >> p[i];
      --p[i];
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
    }
    vector<int64> up(n, 0);
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (l[i] > up[i]) {
        ++res;
        up[i] = r[i];
      } else {
        up[i] = min(up[i], (int64) r[i]);
      }
      if (i > 0) {
        up[p[i]] += up[i];
      }
    }
    cout << res << "\n";
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
    BFakePlasticTrees solver;


    solver.solve();
    return 0;
}