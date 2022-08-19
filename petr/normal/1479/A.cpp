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

class ASearchingLocalMinimum {
 public:
  void solveOne() {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "! 1\n";
      cout.flush();
      return;
    }
    cout << "? 1\n";
    cout.flush();
    int a0;
    cin >> a0;
    cout << "? 2\n";
    cout.flush();
    int a1;
    cin >> a1;
    if (a0 < a1) {
      cout << "! 1\n";
      cout.flush();
      return;
    }
    cout << "? " << (n - 1) << "\n";
    cout.flush();
    int a2;
    cin >> a2;
    cout << "? " << n << "\n";
    cout.flush();
    int a3;
    cin >> a3;
    if (a2 > a3) {
      cout << "! " << n << "\n";
      cout.flush();
      return;
    }
    int left = 1;
    int right = n - 2;
    while (true) {
      if (left == right) {
        cout << "! " << (left + 1) << "\n";
        cout.flush();
        return;
      }
      int m1 = (left + right) / 2;
      int m2 = m1 + 1;
      cout << "? " << (m1 + 1) << "\n";
      cout.flush();
      int b0;
      cin >> b0;
      cout << "? " << (m2 + 1) << "\n";
      cout.flush();
      int b1;
      cin >> b1;
      if (b0 < b1) {
        right = m1;
      } else {
        left = m2;
      }
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
    ASearchingLocalMinimum solver;


    solver.solve();
    return 0;
}