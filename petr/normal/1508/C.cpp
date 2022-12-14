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
#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1





namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#endif  // ATCODER_DSU_HPP



#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

struct Edge {
  int u;
  int v;
  int w;
};

class CCompleteTheMST {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<Edge> e(2 * m);
    int globalXor = 0;
    for (int i = 0; i < m; ++i) {
      cin >> e[i * 2].u >> e[i * 2].v >> e[i * 2].w;
      --e[i * 2].u; --e[i * 2].v;
      globalXor ^= e[i * 2].w;
      e[i * 2 + 1] = e[i * 2];
      swap(e[i * 2 + 1].u, e[i * 2 + 1].v);
    }
    sort(all(e), [](const Edge& a, const Edge& b) {
      if (a.u != b.u) return a.u < b.u;
      return a.v < b.v;
    });
    atcoder::dsu zeros(n);
    int first = 0;
    set<int> pending;
    for (int i = 0; i + 1 < n; ++i) pending.insert(i);
    int64 totalZeros = n * (int64) (n - 1) / 2 - m;
    for (int i = 0; i < n; ++i) {
      int last = first;
      while (last < e.size() && e[last].u == i) ++last;

      auto processSegment = [&](int l, int r) {
        if (l > r) return;
        zeros.merge(l, i);
        while (true) {
          auto it = pending.lower_bound(l);
          if (it == pending.end() || *it >= r) return;
          int v = *it;
          pending.erase(it);
          zeros.merge(v, v + 1);
        }
      };

      int next = 0;
      for (int j = first; j < last; ++j) {
        processSegment(next, e[j].v - 1);
        next = e[j].v + 1;
      }
      processSegment(next, n - 1);

      first = last;
    }
    sort(all(e), [](const Edge& a, const Edge& b) {
      return a.w < b.w;
    });
    int count = 0;
    for (int i = 0; i < n; ++i) if (zeros.leader(i) == i) ++count;
    int64 res = 0;
    int64 bonus = 0;
    if (count + totalZeros == n) {
      bonus = globalXor;
    }
    atcoder::dsu positives(n);
    for (const auto& edge : e) {
      if (edge.u > edge.v) continue;
      if (zeros.leader(edge.u) != zeros.leader(edge.v)) {
        zeros.merge(edge.u, edge.v);
        res += edge.w;
      } else {
        if (positives.leader(edge.u) != positives.leader(edge.v)) {
          bonus = min(bonus, (int64) edge.w);
        }
      }
      positives.merge(edge.u, edge.v);
    }
    res += bonus;
    cout << res << "\n";
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    CCompleteTheMST solver;


    solver.solve();
    return 0;
}