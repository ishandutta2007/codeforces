/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
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

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = (int) 1e9;

class TaskC {
 public:
  void solveOne(istream &in, ostream &out) {
    int r, n;
    in >> r >> n;
    vector<int> t(n + 1), x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i) {
      in >> t[i] >> x[i] >> y[i];
      --x[i];
      --y[i];
    }
    vector<int> best(n + 1);
    int bestBefore = -INF;
    int maxDist = 2 * r;
    for (int i = 1; i <= n; ++i) {
      int from;
      if (i - maxDist >= 0) {
        bestBefore = max(bestBefore, best[i - maxDist]);
        from = i - maxDist + 1;
      } else {
        from = 0;
      }
      int cur = bestBefore;
      for (int j = from; j < i; ++j) {
        if (abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[i] - t[j]) {
          cur = max(cur, best[j]);
        }
      }
      best[i] = cur + 1;
    }
    int res = 0;
    for (int val : best) res = max(res, val);
    out << res << "\n";
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskC solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}