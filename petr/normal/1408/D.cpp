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

class TaskD {
 public:
  void solveOne(istream &in, ostream &out) {
    int n, m; in >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) {
      in >> a[i] >> b[i];
    }
    for (int i = 0; i < m; ++i) {
      in >> c[i] >> d[i];
    }
    vector<ii> v(n * m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        v[i * m + j] = {c[j] - a[i], d[j] - b[i]};
      }
    }
    sort(all(v));

    int must = 0;
    int res = (int) 1e9;
    for (int i = int(v.size()) - 1; i >= 0; --i) {
      res = min(res, max(0, v[i].first + 1) + must);
      must = max(must, v[i].second + 1);
    }
    res = min(res, must);
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
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}