//#define NDEBUG
#pragma warning(disable : 4146)

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

#include <array>

namespace n91 {

void solve() {
  static constexpr usize N = 600;
  static constexpr u32 INF = 2e9;
  const usize n = scan<usize>();
  const usize m = scan<usize>();
  std::array<std::array<u32, N>, N> g;
  for (const usize i : rep(0, n)) {
    for (const usize j : rep(0, n)) {
      g[i][j] = INF;
    }
  }
  for (const usize i : rep(0, m)) {
    const usize a = scan<usize>();
    const usize b = scan<usize>();
    const u32 c = scan<u32>();
    g[a][b] = c;
  }

  for (const usize s : rep(0, n)) {
    std::vector<u32> d(2 * n, INF);
    std::vector<u32> visited(2 * n, 0);
    d[s] = 0;
    for (const usize loop : rep(0, 2 * n)) {
      usize v = 2 * n;
      for (const usize u : rep(0, 2 * n)) {
        if (!visited[u] && (v == 2 * n || d[u] < d[v])) {
          v = u;
        }
      }
      visited[v] = 1;
      if (v >= n) {
        chmin(d[v - n], d[v]);
        chmin(d[(v - n + 1) % n + n], d[v] + 1);
      } else {
        for (const usize b : rep(0, n)) {
          chmin(d[(b + d[v]) % n + n], d[v] + g[v][b]);
        }
      }
    }
    for (const usize t : rep(0, n)) {
      std::cout << d[t] << " \n"[t + 1 == n];
    }
  }
}

void main_() {
  //*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  const usize t = 1;
  for (const usize i : rep(0, t)) {
    solve();
  }
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}