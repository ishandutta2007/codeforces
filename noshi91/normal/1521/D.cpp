//#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

namespace n91 {

using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

struct rep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { ++i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr rep(const usize f, const usize l) noexcept
      : f(std::min(f, l)), l(l) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
struct revrep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { --i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr revrep(const usize f, const usize l) noexcept
      : f(l - 1), l(std::min(f, l) - 1) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
template <class T> auto md_vec(const usize n, const T &value) {
  return std::vector<T>(n, value);
}
template <class... Args> auto md_vec(const usize n, Args... args) {
  return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> constexpr T difference(const T &a, const T &b) noexcept {
  return a < b ? b - a : a - b;
}
template <class T> void chmin(T &a, const T &b) noexcept {
  if (b < a)
    a = b;
}
template <class T> void chmax(T &a, const T &b) noexcept {
  if (a < b)
    a = b;
}
template <class F> class rec_lambda {
  F f;

public:
  rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}
  template <class... Args> auto operator()(Args &&... args) const {
    return f(*this, std::forward<Args>(args)...);
  }
};
template <class T> T scan() {
  T ret;
  std::cin >> ret;
  return ret;
}
constexpr char eoln = '\n';
template <class T> T ceildiv(const T &l, const T &r) {
  return l / r + (l % r != 0 ? 1 : 0);
}

} // namespace n91

namespace n91 {

void make_arb(std::vector<std::vector<usize>> &g, usize root = 0) {
  const usize n = g.size();
  rec_lambda([&](const auto &rem, const usize v, const usize p) -> void {
    auto &l = g[v];
    for (usize i = 0; i != l.size();) {
      if (l[i] == p) {
        l.erase(l.begin() + i);
      } else {
        rem(l[i], v);
        i += 1;
      }
    }
  })(root, -1);
}

void solve() {
  const usize n = scan<usize>();
  std::vector g(n, std::vector<usize>());
  for (const usize i : rep(0, n - 1)) {
    const usize a = scan<usize>() - 1;
    const usize b = scan<usize>() - 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  make_arb(g);
  static constexpr usize inf = std::numeric_limits<usize>::max() / 2;
  struct node0 {
    usize v;
    usize ch;
  };
  struct node1 {
    usize v;
    usize c0;
    usize c1;
  };
  std::vector<node0> dp0(n);
  std::vector<node1> dp1(n);
  rec_lambda([&](const auto &calc, const usize v) -> void {
    usize dsum = 0;
    std::vector<std::pair<usize, usize>> diff;
    for (const usize u : g[v]) {
      calc(u);
      dsum += std::min(dp0[u].v, dp1[u].v);
      diff.emplace_back(dp0[u].v - std::min(dp0[u].v, dp1[u].v), u);
    }
    if (diff.size() == 0) {
      dp0[v].v = 0;
      dp1[v].v = inf;
      return;
    }
    if (diff.size() == 1) {
      dp0[v].v = dsum + diff[0].first;
      dp0[v].ch = diff[0].second;
      dp1[v].v = inf;
      return;
    }
    std::sort(diff.begin(), diff.end());
    dp0[v].v = dsum + diff[0].first + diff.size() - 1;
    dp0[v].ch = diff[0].second;
    dp1[v].v = dsum + diff[0].first + diff[1].first + diff.size() - 2;
    dp1[v].c0 = diff[0].second;
    dp1[v].c1 = diff[1].second;
  })(0);
  std::vector<std::pair<usize, usize>> paths, edges;
  rec_lambda(
      [&](const auto &solve, const bool rep_path, const usize v) -> usize {
        if (rep_path) {
          if (g[v].size() == 0) {
            return v;
          }
          for (const usize u : g[v]) {
            if (u == dp0[v].ch) {
              continue;
            }
            edges.emplace_back(v, u);
            solve(false, u);
          }
          return solve(true, dp0[v].ch);
        } else {
          if (dp0[v].v < dp1[v].v) {
            paths.emplace_back(v, solve(true, v));
          } else {
            for (const usize u : g[v]) {
              if (u == dp1[v].c0 || u == dp1[v].c1) {
                continue;
              }
              edges.emplace_back(v, u);
              solve(false, u);
            }
            paths.emplace_back(solve(true, dp1[v].c0), solve(true, dp1[v].c1));
          }
          return n;
        }
      })(false, 0);
  const usize k = edges.size();
  assert(k + 1 == paths.size());
  std::cout << k << eoln;
  for (const usize i : rep(0, k)) {
    std::cout << edges[i].first + 1 << " " << edges[i].second + 1 << " "
              << paths[i].second + 1 << " " << paths[i + 1].first + 1 << eoln;
  }
}

void main_() {
  //*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  const usize t = scan<usize>();
  for (const usize i : rep(0, t)) {
    solve();
  }
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}