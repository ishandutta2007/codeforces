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

class TaskA {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<int> a(n), b(n), c(n);
    for (int& x : a) in >> x;
    for (int& x : b) in >> x;
    for (int& x : c) in >> x;
    int first = a[0];
    out << first;
    int prev = first;
    for (int i = 1; i < n; ++i) {
      out << " ";
      if (a[i] != prev && a[i] != first) {
        prev = a[i];
      } else if (b[i] != prev && b[i] != first) {
        prev = b[i];
      } else {
        prev = c[i];
      }
      out << prev;
    }
    out << "\n";
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt;
    in >> nt;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskA solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}