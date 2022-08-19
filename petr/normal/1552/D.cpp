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

class DMassivKakRaznost {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int p3 = 1;
    for (int i = 0; i < n; ++i) p3 *= 3;
    for (int mask = 1; mask < p3; ++mask) {
      int rem = mask;
      int s = 0;
      for (int i = 0; i < n; ++i) {
        int cur = rem % 3;
        if (cur == 1) s += a[i]; else if (cur == 2) s -= a[i];
        rem /= 3;
      }
      if (s == 0) {
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
    DMassivKakRaznost solver;


    solver.solve();
    return 0;
}