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

class CFishingprincePlaysWithArray {
 public:
  void solveOne() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int k;
    cin >> k;
    vector<int> b(k);
    for (auto& x : b) cin >> x;
    auto canonicalize = [&m](vector<int> a) {
      vector<pair<int, int64>> res;
      for (int x : a) {
        int pw = 1;
        while (x % m == 0) {
          x /= m;
          pw *= m;
        }
        if (!res.empty() && res.back().first == x) {
          res.back().second += pw;
        } else {
          res.emplace_back(x, pw);
        }
      }
      return res;
    };
    if (canonicalize(a) == canonicalize(b)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
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
    CFishingprincePlaysWithArray solver;


    solver.solve();
    return 0;
}