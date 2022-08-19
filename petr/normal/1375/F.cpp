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

class TaskF {
 public:
  int64 gcd(int64 a, int64 b) {
    while (b > 0) {
      int64 t = a % b;
      a = b;
      b = t;
    }
    return a;
  }

  void solveOne(istream &in, ostream &out) {
    vector<int64> val(3);
    for (int i = 0; i < 3; ++i) {
      in >> val[i];
    }
    out << "First\n";
    out.flush();
    int last = -1;
    bool found = false;
    while (true) {
      vector<pair<int64, int>> p;
      for (int i =0 ; i < 3; ++i) p.emplace_back(val[i], i);
      sort(all(p));
      int64 a = p[0].first;
      int64 b = p[1].first;
      int64 c = p[2].first;
      b -= a;
      c -= a;
      int64 g = gcd(b, c);
      b /= g;
      c /= g;
      int64 move = 1;

      if (last == p[2].second) {
        if (b == 1 && c == 3) {
          move = 3;
          found = true;
        } else {
          if (c - b > 2 || found) {
            move = c - b;
          } else {
            move = c;
          }
        }
      }
      out << move * g << "\n";
      out.flush();
      int which;
      in >> which;
      if (which <= 0) break;
      --which;
      last = which;
      val[which] += move * g;
    }
    /*vector<int64> a(3);
    mt19937 rng;
    uniform_int_distribution<int> distrib(1, (int) 1e6);
    int maxsteps = 0;
    while (true) {
      for (int i =0 ; i < 3; ++i) {
        while (true) {
          a[i] = distrib(rng);
          bool ok = true;
          for (int j = 0; j < i; ++j) if (a[j] == a[i]) ok = false;
          if (ok) break;
        }
      }
      sort(all(a));
      auto sa = a;
      int last = -1;
      int steps = 0;
      while (true) {
        sort(all(a));
        //cerr << a[0] << " " << a[1] << " " << a[2] << "\n";
        if (a[2] - a[1] == a[1] - a[0]) break;
        int64 x = gcd(a[2] - a[1], a[1] - a[0]);
        if (last == 2) {
          if (a[2] - a[1] > 2 * x) {
            x = a[2] - a[1];
          } else {
            x = a[2] - a[0];
          }
        }
        bool ok = false;
        for (int i = 0; i < 3; ++i)
          if (i != last) {
            if (i == 2 || a[i] + x != a[i + 1]) {
              a[i] += x;
              last = i;
              ok = true;
              break;
            }
          }
        if (!ok) break;
        ++steps;
        assert(steps <= 1000);
        assert(a[2] <= 1e12);
      }
      if (steps > maxsteps) {
        maxsteps = steps;
        cerr << maxsteps << "\n";
        for (int64 x : sa) cerr << x << " ";
        cerr << "\n";
        for (int64 x : a) cerr << x << " ";
        cerr << "\n";
      }
    }*/
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
  TaskF solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}