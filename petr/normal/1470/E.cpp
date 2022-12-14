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

struct Op {
  int left;
  int right;
  int oldValue;
  int value;
};

struct Fenwick {
  vector<int64> a;

  Fenwick(int n) : a(n) {
  }

  void upd(int at, int64 by) {
    while (at < a.size()) {
      a[at] += by;
      at |= at + 1;
    }
  }

  int64 get(int upto) const {
    int64 res = 0;
    while (upto >= 0) {
      res += a[upto];
      upto = (upto & (upto + 1)) - 1;
    }
    return res;
  }

  int findLastLess(int64 val) const {
    int shift = 1;
    int pos = -1;
    while (pos + shift * 2 < a.size()) shift *= 2;
    while (shift > 0) {
      if (pos + shift < a.size() && a[pos + shift] <= val) {
        val -= a[pos + shift];
        pos += shift;
      }
      shift /= 2;
    }
    return pos;
  }
};

class EStrannayaPerestanovka {
 public:
  void solveOne(istream &in, ostream &out) {
    int n, c, q;
    in >> n >> c >> q;
    vector<int> p(n);
    for (auto& x : p) {
      in >> x;
      --x;
    }
    vector<Op> ops;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n && j <= i + c; ++j) {
        Op op;
        op.left = i;
        op.right = j;
        op.oldValue = p[i];
        op.value = p[j];
        ops.push_back(op);
      }
    }
    Op sentinel;
    sentinel.left = n;
    sentinel.right = n;
    sentinel.oldValue = 1;
    sentinel.value = 0;
    ops.push_back(sentinel);
    sort(all(ops), [](const Op& a, const Op& b) {
      int kinda = a.value < a.oldValue ? 0 : 1;
      int kindb = b.value < b.oldValue ? 0 : 1;
      if (kinda != kindb) return kinda < kindb;
      if (kinda == 0) {
        if (a.left != b.left) {
          return a.left < b.left;
        }
        return a.value < b.value;
      } else {
        if (a.left != b.left) {
          return a.left > b.left;
        }
        return a.value < b.value;
      }
    });

    vector<vector<int>> toDelete(n + 2);
    for (int i = 0; i < ops.size(); ++i) {
      toDelete[ops[i].left].push_back(i);
    }

    vector<vector<int64>> choices(c + 1, vector<int64>(n + 2));
    for (int rem = 0; rem <= c; ++rem) {
      choices[rem][n] = choices[rem][n + 1] = 1;
      for (int start = n - 1; start >= 0; --start) {
        choices[rem][start] = choices[rem][start + 1];
        for (int finish = start + 1; finish < n && finish <= start + rem; ++finish) {
          choices[rem][start] += choices[rem - (finish - start)][finish + 1];
          if (choices[rem][start] >= 4e18) assert(false);
        }
      }
    }

    vector<Fenwick> fenwick(c + 1, Fenwick(ops.size()));
    for (int i = 0; i < ops.size(); ++i) {
      auto op = ops[i];
      for (int j = op.right - op.left; j <= c; ++j) {
        fenwick[j].upd(i, choices[j - (op.right - op.left)][op.right + 1]);
      }
    }

    vector<int64> need(q);
    vector<int> needAt(q);
    vector<int> avail(q);
    vector<int> answer(q, -1);
    for (int i = 0; i < q; ++i) {
      in >> needAt[i] >> need[i];
      --needAt[i];
      --need[i];
      answer[i] = p[needAt[i]];
      avail[i] = c;
    }

    vector<vector<int>> queue(n + 2);
    for (int i = 0; i < q; ++i) {
      queue[0].push_back(i);
    }

    for (int pos = 0; pos < n; ++pos) {
      for (int qi : queue[pos]) {
        int at = fenwick[avail[qi]].findLastLess(need[qi]);
        need[qi] -= fenwick[avail[qi]].get(at);
        assert(need[qi] >= 0);
        if (at + 1 >= ops.size()) {
          need[qi] = 0;
          answer[qi] = -2;
          continue;
        }
        auto op = ops[at + 1];
        if (op.left <= needAt[qi] && op.right >= needAt[qi]) {
          answer[qi] = p[op.left + op.right - needAt[qi]];
        }
        avail[qi] -= op.right - op.left;
        queue[op.right + 1].push_back(qi);
      }
      queue[pos].clear();
      for (int i : toDelete[pos]) {
        auto op = ops[i];
        for (int j = op.right - op.left; j <= c; ++j) {
          fenwick[j].upd(i, -choices[j - (op.right - op.left)][op.right + 1]);
        }
      }
    }

    for (int i = 0; i < q; ++i) {
      assert(need[i] == 0);
      out << answer[i] + 1 << "\n";
    }
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
  EStrannayaPerestanovka solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}