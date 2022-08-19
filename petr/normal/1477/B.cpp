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

class BNezzarAndBinaryString {
 public:
  vector<int> val;
  vector<int> n0;
  vector<int> n1;

  void initTree(int root, int rl, int rr, const string& t) {
    if (rl == rr) {
      val[root] = t[rl] - '0';
      if (val[root]) ++n1[root]; else ++n0[root];
    } else {
      val[root] = -1;
      int rm = (rl + rr) >> 1;
      initTree(root * 2 + 1, rl, rm, t);
      initTree(root * 2 + 2, rm + 1, rr, t);
      n0[root] = n0[root * 2 + 1] + n0[root * 2 + 2];
      n1[root] = n1[root * 2 + 1] + n1[root * 2 + 2];
    }
  }

  ii treeCount(int root, int rl, int rr, int left, int right) {
    if (left > right) return {0, 0};
    if (rl == left && rr == right) {
      return {n0[root], n1[root]};
    }
    int rm = (rl + rr) >> 1;
    if (val[root] >= 0) {
      val[root * 2 + 1] = val[root];
      val[root * 2 + 2] = val[root];
      if (val[root]) {
        n0[root * 2 + 1] = 0;
        n0[root * 2 + 2] = 0;
        n1[root * 2 + 1] = rm - rl + 1;
        n1[root * 2 + 2] = rr - rm;
      } else {
        n1[root * 2 + 1] = 0;
        n1[root * 2 + 2] = 0;
        n0[root * 2 + 1] = rm - rl + 1;
        n0[root * 2 + 2] = rr - rm;
      }
      val[root] = -1;
    }
    ii a = treeCount(root * 2 + 1, rl, rm, left, min(rm, right));
    ii b = treeCount(root * 2 + 2, rm + 1, rr, max(rm + 1, left), right);
    return {a.first + b.first, a.second + b.second};
  }

  void treeSet(int root, int rl, int rr, int left, int right, int v) {
    if (left > right) return;
    if (rl == left && rr == right) {
      val[root] = v;
      if (v) {
        n1[root] = rr - rl + 1;
        n0[root] = 0;
      } else {
        n0[root] = rr - rl + 1;
        n1[root] = 0;
      }
      return;
    }
    int rm = (rl + rr) >> 1;
    if (val[root] >= 0) {
      val[root * 2 + 1] = val[root];
      val[root * 2 + 2] = val[root];
      if (val[root]) {
        n0[root * 2 + 1] = 0;
        n0[root * 2 + 2] = 0;
        n1[root * 2 + 1] = rm - rl + 1;
        n1[root * 2 + 2] = rr - rm;
      } else {
        n1[root * 2 + 1] = 0;
        n1[root * 2 + 2] = 0;
        n0[root * 2 + 1] = rm - rl + 1;
        n0[root * 2 + 2] = rr - rm;
      }
      val[root] = -1;
    }
    treeSet(root * 2 + 1, rl, rm, left, min(rm, right), v);
    treeSet(root * 2 + 2, rm + 1, rr, max(rm + 1, left), right, v);
    n0[root] = n0[root * 2 + 1] + n0[root * 2 + 2];
    n1[root] = n1[root * 2 + 1] + n1[root * 2 + 2];
  }

  void solveOne(istream &in, ostream &out) {
    int n, q;
    in >> n >> q;
    string s, t;
    in >> s >> t;
    vector<int> l(q);
    vector<int> r(q);
    for (int qi = 0; qi < q; ++qi) {
      in >> l[qi] >> r[qi];
      --l[qi]; --r[qi];
    }
    val = vector<int>(4 * n + 10);
    n0 = vector<int>(4 * n + 10);
    n1 = vector<int>(4 * n + 10);
    initTree(0, 0, n - 1, t);
    for (int qi = q - 1; qi >= 0; --qi) {
      int left = l[qi];
      int right = r[qi];
      ii counts = treeCount(0, 0, n - 1, left, right);
      assert(counts.first + counts.second == right - left + 1);
      if (counts.first == counts.second) {
        out << "NO\n";
        return;
      }
      if (counts.first < counts.second) {
        treeSet(0, 0, n - 1, left, right, 1);
      } else {
        treeSet(0, 0, n - 1, left, right, 0);
      }
    }
    for (int i = 0; i < n; ++i) {
      ii counts = treeCount(0, 0, n - 1, i, i);
      if (s[i] - '0' != counts.second) {
        out << "NO\n";
        return;
      }
    }
    out << "YES\n";
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
  BNezzarAndBinaryString solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}