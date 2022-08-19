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

class CMaksimiziruitePeresecheniya {
 public:
  void solveOne() {
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    vector<int> y(k);
    for (int i = 0; i < k; ++i) {
      cin >> x[i] >> y[i];
      --x[i];
      --y[i];
    }
    vector<bool> taken(2 * n);
    for (int i = 0; i < k; ++i) {
      taken[x[i]] = true;
      taken[y[i]] = true;
    }
    vector<int> a;
    for (int i = 0; i < taken.size(); ++i) if (!taken[i]) a.push_back(i);
    for (int i = 0; i < n - k; ++i) {
      x.push_back(a[i]);
      y.push_back(a[i + n - k]);
    }
    for (int i = 0; i < n; ++i) {
      if (x[i] > y[i]) swap(x[i], y[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (y[i] < x[j] || y[j] < x[i] || (x[i] > x[j] && y[i] < y[j]) || (x[j] > x[i] && y[j] < y[i])) {

        } else {
          ++res;
        }
      }
    }
    cout << res << "\n";
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
    CMaksimiziruitePeresecheniya solver;


    solver.solve();
    return 0;
}