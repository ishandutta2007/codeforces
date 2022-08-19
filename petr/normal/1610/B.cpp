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

class BKalindromeArray {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
      if (a[i] == a[j]) {
        ++i;
        --j;
      } else {
        break;
      }
    }
    if (i > j) {
      cout << "YES\n";
      return;
    }
    int v1 = a[i];
    int v2 = a[j];
    for (int skip: vector<int>{v1, v2}) {
      i = 0;
      j = n - 1;
      bool ok = true;
      while (i <= j) {
        if (a[i] == a[j]) {
          ++i;
          --j;
        } else if (a[i] == skip) {
          ++i;
        } else if (a[j] == skip) {
          --j;
        } else {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    BKalindromeArray solver;


    solver.solve();
    return 0;
}