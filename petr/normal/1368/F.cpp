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
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    int bestk = -1;
    int bestscore = -100;
    for (int k = 1; k <= n; ++k) {
      int score = n - (n + k - 1) / k - (k - 1);
      if (score > bestscore) {
        bestscore = score;
        bestk = k;
      }
    }
    int k = bestk;
    vector<bool> need(n);
    for (int i =0 ; i < n; ++i) need[i] = i % k > 0;
    vector<bool> have(n);
    int haveCnt = 0;
    while (haveCnt < bestscore) {
      out << k;
      int togo = k;
      for (int i = 0; i < n && togo > 0; ++i) if (!have[i] && need[i]) {
        out << " " << (i + 1);
        have[i] = true;
        --togo;
        ++haveCnt;
      }
      assert(togo == 0);
      out << "\n";
      out.flush();
      int x;
      in >> x;
      --x;
      for (int i = 0; i < k; ++i) {
        if (have[x]) {
          have[x] = false;
          --haveCnt;
        }
        ++x;
        if (x >= n) x -= n;
      }
      assert(haveCnt <= bestscore);
    }
    out << 0 << "\n";
    out.flush();
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