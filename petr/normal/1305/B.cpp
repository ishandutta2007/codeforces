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

class TaskB {
 public:
  void solveOne(istream &in, ostream &out) {
    string s;
    in >> s;
    int left = 0;
    int right = s.size() - 1;
    vector<int> leftRemove;
    vector<int> rightRemove;
    while (true) {
      while (left <= right && s[left] != '(') ++left;
      while (left <= right && s[right] != ')') --right;
      if (left < right) {
        leftRemove.push_back(left);
        rightRemove.push_back(right);
        ++left;
        --right;
      } else break;
    }
    reverse(rightRemove.begin(), rightRemove.end());
    if (leftRemove.empty()) {
      out << 0 << "\n";
    } else {
      out << 1 << "\n";
      out << leftRemove.size() + rightRemove.size() << "\n";
      for (int x : leftRemove) {
        out << x + 1 << " ";
      }
      for (int x : rightRemove) {
        out << x + 1 << " ";
      }
      out << "\n";
    }
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt;
    nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskB solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}