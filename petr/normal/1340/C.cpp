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

class TaskC {
 public:
  void solveOne(istream &in, ostream &out) {
    int n, m;
    in >> n >> m;
    vector<int> d(m);
    for (int& x : d) in >> x;
    sort(all(d));
    int green, red;
    in >> green >> red;
    vector<vector<bool>> reach(m, vector<bool>(green + 1));
    vector<int> qat;
    vector<int> qtime;
    int qt = 0;
    reach[0][0] = true;
    qat.push_back(0);
    qtime.push_back(0);
    int cycle = 0;
    int res = -1;
    while (!qat.empty() && res < 0) {
      vector<int> nqat;
      vector<int> nqtime;
      while (qt < qat.size()) {
        int at = qat[qt];
        int time = qtime[qt];
        ++qt;
        if (at == m - 1) {
          int cres = cycle * (green + red) + time;
          if (res < 0 || cres < res) {
            res = cres;
          }
          continue;
        }
        if (time == green && !reach[at][0]) {
          reach[at][0] = true;
          nqat.push_back(at);
          nqtime.push_back(0);
        }
        if (at > 0) {
          int nat = at - 1;
          int ntime = time + d[at] - d[at - 1];
          if (ntime <= green && !reach[nat][ntime]) {
            reach[nat][ntime] = true;
            qat.push_back(nat);
            qtime.push_back(ntime);
          }
        }
        if (at + 1 < m) {
          int nat = at + 1;
          int ntime = time - d[at] + d[at + 1];
          if (ntime <= green && !reach[nat][ntime]) {
            reach[nat][ntime] = true;
            qat.push_back(nat);
            qtime.push_back(ntime);
          }
        }
      }
      qat = nqat;
      qtime = nqtime;
      qt = 0;
      ++cycle;
    }
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