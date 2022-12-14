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

class TaskA {
 public:
  void solveOne(istream &in, ostream &out) {
    string s;
    in >> s;
    vector<int> cnt(10);
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
      int d = s[i] - '0';
      sum += d;
      ++cnt[d];
    }
    if (cnt[0] == 0 || sum % 3 != 0) {
      out << "cyan\n";
      return;
    }
    --cnt[0];
    for (int i = 0; i < 10; i += 2) if (cnt[i] > 0) {
        out << "red\n";
        return;
    }
    out << "cyan\n";
    return;
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