/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#undef NDEBUG

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
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
// AtCoder library from https://github.com/atcoder/ac-library
// #include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

class GDenRozhdeniya {
 public:
  void solveOne() {
    /*for (int n = 3;; ++n) {
      set<vector<int>> reach;
      map<vector<int>, vector<int>> via;
      int bound = n;
      bool found = false;
      vector<int> start(n);
      iota(all(start), 1);
      reach.insert(start);
      while (!found) {
        ++bound;
        cerr << bound << endl;
        while (!found) {
          bool upd = false;
          vector<vector<int>> from(all(reach));
          for (vector<int> a : from) {
            if (found) break;
            for (int i = 0; i < a.size() && !found; ++i) {
              for (int j = i + 1; j < a.size() && !found; ++j) {
                if (a[i] + a[j] > bound) break;
                vector<int> b = a;
                int s = a[i] + a[j];
                int d = abs(a[i] - a[j]);
                b[i] = s;
                b[j] = d;
                sort(all(b));
                bool all_same = true;
                for (int x : b) if (x != bound) all_same = false;
                if (all_same) {
                  found = true;
                }
                if (reach.insert(b).second) {
                  upd = true;
                  via[b] = a;
                }
              }
            }
          }
          if (!upd) break;
        }
      }
      cerr << n << " " << bound << endl;
      vector<int> cur(n, bound);
      for (int x : cur) cerr << x << " ";
      cerr << endl;
      while (via.find(cur) != via.end()) {
        cur = via[cur];
        for (int x : cur) cerr << x << " ";
        cerr << endl;
      }
    }*/
    int n;
    cin >> n;
    if (n == 2) {
      cout << -1 << "\n";
      return;
    }
    int t = n;
    while (t & (t - 1)) ++t;
    vector<ii> sol;
    vector<int> got;
    auto doit = [&](auto self, int mult, int n) {
      if (n <= 2) {
        for (int i = 1; i <= n; ++i) got.push_back(i * mult);
        return;
      }
      int mid = t;
      while (mid > n) mid >>= 1;
      int cnt = 0;
      for (int i = mid + 1; i <= n; ++i) {
        ++cnt;
        sol.emplace_back(i * mult, (2 * mid - i) * mult);
        got.push_back(mid * 2 * mult);
      }
      self(self, mult * 2, cnt);
      self(self, mult, 2 * mid - (n + 1));
      got.push_back(mult * mid);
    };
    doit(doit, 1, n);
    assert(got.size() == n);
    sort(all(got));
    int found = -1;
    for (int i = 0; i + 1 < got.size(); ++i) if (got[i] == got[i + 1] && got[i] < t) {
      found = i;
      break;
    }
    assert(found >= 0);
    sol.emplace_back(got[found], got[found]);
    got[found] = 0;
    got[found + 1] *= 2;
    for (int i = 0; i < n; ++i) if (i != found) {
      while (got[i] < t) {
        sol.emplace_back(got[i], 0);
        sol.emplace_back(got[i], got[i]);
        got[i] *= 2;
      }
    }
    sol.emplace_back(0, t);
    got[found] = t;
    for (int x : got) assert(x == t);
    /*multiset<int> have;
    for (int i = 1; i <= n; ++i) have.insert(i);
    for (auto p : sol) {
      int a = p.first;
      int b = p.second;
      auto it = have.find(p.first);
      assert(it != have.end());
      have.erase(it);
      it = have.find(p.second);
      assert(it != have.end());
      have.erase(it);
      have.insert(a + b);
      have.insert(abs(a - b));
    }
    assert(*have.begin() == t);
    assert(*have.rbegin() == t);*/
    assert(sol.size() <= 20 * n);
    cout << sol.size() << "\n";
    for (auto p : sol) {
      cout << p.first << " " << p.second << "\n";
    }
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      // cout << "Case #" << (it + 1) << ": ";
      solveOne();
    }
  }
};

// #define st_mtimespec st_mtim

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    GDenRozhdeniya solver;


    solver.solve();
    return 0;
}