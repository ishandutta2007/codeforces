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

using bs = bitset<10001>;

class DOcherednayaZadachaNaMinimizatsiyu {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int s = 0;
    int64 s2 = 0;
    for (int x : a) {
      s += x;
      s2 += x * x;
    }
    for (int x : b) {
      s += x;
      s2 += x * x;
    }
    bs can;
    can.set(0);
    for (int i = 0; i < n; ++i) {
      can = (can << a[i]) | (can << b[i]);
    }
    int64 best = numeric_limits<int64>::max();
    for (int i = 0; i < can.size(); ++i) if (can.test(i)) {
      int64 sa = i;
      int64 sb = s - i;
      int64 cur = sa * sa + sb * sb + (n - 2) * s2;
      best = min(best, cur);
    }
    cout << best << "\n";
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
    DOcherednayaZadachaNaMinimizatsiyu solver;


    solver.solve();
    return 0;
}