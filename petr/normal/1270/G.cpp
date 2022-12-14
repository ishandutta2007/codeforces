/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

class TaskG {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      int v;
      in >> v;
      a[i] = i - v;
    }
    int u = 0;
    vector<bool> mark(n);
    while (!mark[u]) {
      mark[u] = true;
      u = a[u];
    }
    vector<int> res;
    mark = vector<bool>(n);
    while (!mark[u]) {
      res.push_back(u);
      mark[u] = true;
      u = a[u];
    }
    out << res.size() << "\n";
    for (int x : res) {
      out << x + 1 << " ";
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
  TaskG solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}