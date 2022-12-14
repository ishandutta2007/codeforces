/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

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
//#include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

class CTreesOfTranquillity {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n, -1), b(n, -1);
    for (int i = 1; i < n; ++i) {
      cin >> a[i]; --a[i];
    }
    for (int i = 1; i < n; ++i) {
      cin >> b[i]; --b[i];
    }
    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) {
      children[b[i]].push_back(i);
    }
    vector<int> enter(n), exit(n);
    int time = 0;
    auto dfs = [&](auto self, int root) {
      if (root < 0) return;
      enter[root] = time++;
      for (int child : children[root]) {
        self(self, child);
      }
      exit[root] = time++;
    };
    dfs(dfs, 0);
    children.assign(n, vector<int>());
    for (int i = 1; i < n; ++i) {
      children[a[i]].push_back(i);
    }
    set<int> inters;
    vector<int> stack;
    int lls = 0;

    auto add = [&](int root) {
      auto it = inters.lower_bound(2 * enter[root] + 1);
      bool lRight = false;
      if (it != inters.end() && *it % 2 != 0) lRight = true;
      bool lLeft = false;
      if (it != inters.begin() && *--it % 2 != 0) lLeft = true;
      if (lLeft || lRight) ++lls;
      inters.insert(2 * enter[root] + 1);
      it = inters.lower_bound(2 * exit[root]);
      lRight = false;
      if (it != inters.end() && *it % 2 != 0) lRight = true;
      lLeft = false;
      if (it != inters.begin() && *--it % 2 != 0) lLeft = true;
      if (lLeft && lRight) --lls;
      inters.insert(2 * exit[root]);
    };

    auto remove = [&](int root) {
      assert(inters.erase(2 * enter[root] + 1));
      auto it = inters.lower_bound(2 * enter[root] + 1);
      bool lRight = false;
      if (it != inters.end() && *it % 2 != 0) lRight = true;
      bool lLeft = false;
      if (it != inters.begin() && *--it % 2 != 0) lLeft = true;
      if (lLeft || lRight) --lls;
      assert(inters.erase(2 * exit[root]));
      it = inters.lower_bound(2 * exit[root]);
      lRight = false;
      if (it != inters.end() && *it % 2 != 0) lRight = true;
      lLeft = false;
      if (it != inters.begin() && *--it % 2 != 0) lLeft = true;
      if (lLeft && lRight) ++lls;
    };

    int res = 1;

    auto dfs2 = [&](auto self, int root) {
      if (root < 0) return;
      stack.push_back(root);
      add(root);
      res = max(res, (int) stack.size() - lls);
      for (int child : children[root]) {
        self(self, child);
      }
      stack.pop_back();
      remove(root);
    };

    dfs2(dfs2, 0);
    cout << res << "\n";
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    CTreesOfTranquillity solver;


    solver.solve();
    return 0;
}