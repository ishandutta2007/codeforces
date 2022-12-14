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

class TaskA2 {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    string a, b;
    in >> a >> b;
    vector<int> res;

    int left = 0;
    int right = n - 1;
    bool reversed = false;

    for (int i = n - 1; i >= 0; --i) {
      int lasta = reversed ? left : right;
      int va = a[lasta] - '0';
      if (reversed) va = 1 - va;
      int vb = b[i] - '0';
      if (va != vb) {
        int firsta = reversed ? right : left;
        va = a[firsta] - '0';
        if (reversed) va = 1 - va;
        if (va == vb) {
          res.push_back(1);
        }
        res.push_back(i + 1);
        reversed = !reversed;
      }
      if (reversed) ++left; else --right;
    }

    out << res.size();
    for (int x : res) out << " " << x;
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
  TaskA2 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}