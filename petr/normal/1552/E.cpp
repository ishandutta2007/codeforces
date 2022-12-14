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
//#include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

class ETsvetaIOtrezki {
 public:
  void solveOne() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n * k);
    for (auto& x : c) {
      cin >> x;
      --x;
    }
    int maxCover = (n + k - 2) / (k - 1);
    vector<int> cover(n * k);
    int first = 0;
    vector<int> last(n, -1);
    vector<bool> done(n);
    vector<int> a(n, -1);
    vector<int> b(n, -1);
    for (int i = 0; i < n * k; ++i) {
      if (!done[c[i]] && last[c[i]] >= first) {
        done[c[i]] = true;
        a[c[i]] = last[c[i]];
        b[c[i]] = i;
        for (int j = last[c[i]]; j <= i; ++j) {
          ++cover[j];
          if (cover[j] == maxCover) {
            first = j + 1;
          }
        }
      } else {
        last[c[i]] = i;
      }
    }
    for (int i = 0; i < n; ++i) {
      assert(done[i]);
      cout << a[i] + 1 << " " << b[i] + 1 << "\n";
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
    ETsvetaIOtrezki solver;


    solver.solve();
    return 0;
}