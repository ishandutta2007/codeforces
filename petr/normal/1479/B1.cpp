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

class B1PaintingTheArrayI {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      --x;
    }
    vector<vector<int>> occs(n);
    for (int i = 0; i < n; ++i) {
      occs[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) occs[i].push_back(n);
    int x = -1;
    int y = -1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int z = a[i];
      if (z == x) {
        if (z == y) {

        } else {
          y = z;
          ++res;
        }
      } else if (z == y) {
        x = z;
        ++res;
      } else {
        int px = x < 0 ? n : *lower_bound(all(occs[x]), i);
        int py = y < 0 ? n : *lower_bound(all(occs[y]), i);
        if (px < py) {
          x = z;
        } else {
          y = z;
        }
        ++res;
      }
    }
    cout << res << "\n";
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
    B1PaintingTheArrayI solver;


    solver.solve();
    return 0;
}