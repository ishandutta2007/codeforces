/*

Reference

[1]     Belghiti, I., & Habib, M. (2013).
        A general method for common intervals.
        arXiv preprint arXiv:1309.7141.

*/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <utility>
#include <vector>

namespace common_interval_decomposition_tree {

namespace common_interval_decomposition_tree_impl {

using u32 = std::uint32_t;
static_assert(std::numeric_limits<u32>::max() <=
                  std::numeric_limits<std::size_t>::max(),
              "std::size_t is too small");

enum struct node_label {
  increasing,
  decreasing,
  prime,
  leaf,
};

class node_type {
public:
  node_label label;
  std::vector<int> children;
};

// P[i]  i
std::pair<std::vector<node_type>, int> construct(const std::vector<int> &p_) {
  assert(p_.size() < std::numeric_limits<u32>::max() / 2);
  const u32 n = static_cast<u32>(p_.size());
  assert(n >= 1);
  std::vector<u32> p(n);
  for (u32 i = 0; i != n; i += 1) {
    assert(0 <= p_[i] && static_cast<unsigned int>(p_[i]) < n);
    p[i] = static_cast<u32>(p_[i]);
  }

  std::vector<u32> left_pred(n); // i -> max {p[j] | j < i, p[j] < p[i]}
  std::vector<u32> left_succ(n); // i -> min {p[j] | j < i, p[j] > p[i]}
  {
    std::vector<u32> inv(n, n); // p^-1
    for (u32 i = 0; i != n; i += 1) {
      assert(inv[p[i]] == n);
      inv[p[i]] = i;
    }
    std::vector<u32> stack;
    for (const u32 &i : inv) {
      while (!stack.empty() && i < stack.back()) {
        left_succ[stack.back()] = p[i];
        stack.pop_back();
      }
      stack.push_back(i);
    }
    while (!stack.empty()) {
      left_succ[stack.back()] = n - 1;
      stack.pop_back();
    }
    for (const u32 &i : inv) {
      while (!stack.empty() && i < stack.back()) {
        stack.pop_back();
      }
      if (stack.empty()) {
        left_pred[i] = 0;
      } else {
        left_pred[i] = p[stack.back()];
      }
      stack.push_back(i);
    }
  }

  std::vector<node_type> tree(n, {node_label::leaf, {}});
  class interval {
  public:
    u32 index;
    u32 root;
    u32 min;
    u32 max;
  };
  std::vector<interval> pot_beg;
  std::vector<u32> forest;
  const auto pop = [&]() {
    interval &x = *(pot_beg.rbegin() + 1);
    const interval &y = pot_beg.back();
    x.min = std::min(x.min, y.min);
    x.max = std::max(x.max, y.max);
    pot_beg.pop_back();
  };
  for (u32 i = 0; i != n; i += 1) {
    while (!pot_beg.empty()) {
      const interval &x = pot_beg.back();
      if (left_pred[x.index] > p[i] || left_succ[x.index] < p[i]) {
        pop();
      } else {
        break;
      }
    }

    pot_beg.push_back({i, i, p[i], p[i]});
    forest.push_back(i);
    while (pot_beg.size() >= 2) {
      interval &x = *(pot_beg.end() - 2);
      const interval &y = *(pot_beg.end() - 1);
      if (std::max(x.max, y.max) - std::min(x.min, y.min) == i - x.index) {
        const auto itr =
            std::find(forest.rbegin(), forest.rend(), x.root).base() - 1;
        node_label label = node_label::prime;
        bool make = true;
        if (forest.end() - itr == 2) {
          if (p[x.index] < p[y.index]) {
            label = node_label::increasing;
          } else {
            label = node_label::decreasing;
          }
          if (tree[x.root].label == label) {
            tree[x.root].children.push_back(y.root);
            forest.pop_back();
            make = false;
          }
        }
        if (make) {
          tree.push_back({label, {itr, forest.end()}});
          forest.erase(itr, forest.end());
          forest.push_back(static_cast<u32>(tree.size()) - 1);
          x.root = static_cast<u32>(tree.size()) - 1;
        }
        pop();
      } else {
        break;
      }
    }
  }

  return {std::move(tree), static_cast<int>(forest[0])};
}

} // namespace common_interval_decomposition_tree_impl

using common_interval_decomposition_tree_impl::construct;
using common_interval_decomposition_tree_impl::node_label;
using common_interval_decomposition_tree_impl::node_type;

} // namespace common_interval_decomposition_tree

using namespace common_interval_decomposition_tree;

#include <cstdio>

void fast_scan(int &r) {
  r = 0;
  int c;
  while ((c = getchar()) >= 48) {
    r = r * 10 + c - 48;
  }
}

#include <utility>
template <class F> class rec_lambda {
  F f;

public:
  rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}
  template <class... Args> auto operator()(Args &&... args) const {
    return f(*this, std::forward<Args>(args)...);
  }
};

#include <vector>

void CF526F() {
  using i64 = long long;

  int n;
  fast_scan(n);
  std::vector<int> p(n);
  for (int i = 0; i != n; i += 1) {
    int r, c;
    fast_scan(r);
    fast_scan(c);
    p[r - 1] = c - 1;
  }

  const auto [tree, root] = construct(p);
  i64 ans = 0;
  for (const auto &[label, children] : tree) {
    if (label == node_label::increasing || label == node_label::decreasing) {
      const i64 c = children.size();
      ans += c * (c - 1) / 2;
    } else {
      ans += 1;
    }
  }

  printf("%lld\n", ans);
}

void CERC17I() {
  int n;
  fast_scan(n);
  std::vector<int> p(n);
  for (int &e : p) {
    fast_scan(e);
    e -= 1;
  }

  std::vector<node_type> tree;
  int root;
  std::tie(tree, root) = construct(p);
  std::vector<std::pair<int, int>> lr(tree.size());
  rec_lambda([&](const auto &dfs, const int v) -> void {
    if (tree[v].label == node_label::leaf) {
      lr[v] = {v, v};
    } else {
      for (const int c : tree[v].children) {
        dfs(c);
      }
      lr[v] = {lr[tree[v].children.front()].first,
               lr[tree[v].children.back()].second};
    }
  })(root);

  int m;
  fast_scan(m);

  std::vector<std::pair<int, int>> ans(m);
  std::vector<std::vector<std::pair<int, int>>> qs(n);
  for (int j = 0; j != m; j += 1) {
    int x, y;
    fast_scan(x);
    fast_scan(y);
    x -= 1;
    y -= 1;
    qs[y].push_back({j, x});
  }

  struct UF {
    std::vector<int> c;
    UF(int n) : c(n, -1) {}
    int find(int x) { return c[x] < 0 ? x : c[x] = find(c[x]); }
    void unite(int x, int y) { c[find(y)] = find(x); }
  };
  UF uf(tree.size());
  rec_lambda([&](const auto &dfs, const int v) -> void {
    for (const int c : tree[v].children) {
      dfs(c);
      uf.unite(v, c);
    }
    if (v < n) {
      for (const auto &[j, x] : qs[v]) {
        const int lca = uf.find(x);
        const node_label label = tree[lca].label;
        if (label == node_label::prime || label == node_label::leaf) {
          ans[j] = lr[lca];
        } else {
          const int x_ = x;
          const auto &c = tree[lca].children;
          ans[j] = {lr[*std::partition_point(
                           c.begin(), c.end(),
                           [&](const int t) { return lr[t].second < x_; })]
                        .first,
                    lr[*std::partition_point(
                           c.begin(), c.end(),
                           [&](const int t) { return lr[t].second < v; })]
                        .second};
        }
      }
    }
  })(root);

  for (const auto &[l, r] : ans) {
    printf("%d %d\n", l + 1, r + 1);
  }
}

int main() {
  CF526F();
  return 0;
}