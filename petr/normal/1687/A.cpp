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

class ATheEnchantedForest {
 public:
  void solveOne() {
    int n;
    int64 k;
    cin >> n >> k;
    vector<int64> a(n);
    for (auto& x : a) cin >> x;
    int64 res = 0;
    if (k >= n) {
      for (auto x : a) {
        res += x;
      }
      res += n * (k - 1);
      res -= n * (int64) (n - 1) / 2;
    } else {
      int64 sum = 0;
      for (int i = 0; i < k - 1; ++i) {
        sum += a[i];
      }
      for (int i = k - 1; i < n; ++i) {
        sum += a[i];
        res = max(res, sum);
        sum -= a[i - k + 1];
      }
      res += k * (k - 1);
      res -= k * (k - 1) / 2;
    }
    cout << res << endl;
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
    ATheEnchantedForest solver;


    solver.solve();
    return 0;
}