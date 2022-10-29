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
#include <numeric>

namespace n91 {

void main_() {
  //*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/

  static constexpr usize NMAX = 2500;
  std::array<std::array<u32, NMAX + 1>, NMAX + 1> a = {};

  const usize n = scan<usize>();
  const usize m = scan<usize>();
  const usize k = scan<usize>();
  for (const usize i : rep(0, n)) {
    for (const usize j : rep(0, m)) {
      a[i + 1][j + 1] =
          -a[i][j] + a[i][j + 1] + a[i + 1][j] + (scan<char>() == '1');
    }
  }

  const auto sum = [&](const usize x0, const usize x1, const usize y0,
                       const usize y1) -> u32 {
    return a[x0][y0] - a[x0][y1] - a[x1][y0] + a[x1][y1];
  };

  u64 ans = 0;

  std::array<usize, 8> t0, t1;

  rec_lambda([&](const auto &solve, const usize x0, const usize x1,
                 const usize y0, const usize y1) -> void {
    if (x1 - x0 == 1 && y1 - y0 == 1) {
      if (sum(x0, x1, y0, y1) == k) {
        ans += 1;
      }
      return;
    }
    if (x1 - x0 >= y1 - y0) {
      // split up down
      const usize m = (x0 + x1) / 2;
      for (const usize l : rep(y0, y1)) {
        t0[0] = m;
        t1[0] = m;
        for (const usize i : rep(1, 8)) {
          t0[i] = x0;
          t1[i] = x1;
        }
        for (const usize r : rep(l + 1, y1 + 1)) {
          for (const usize i : rep(1, 8)) {
            while (sum(t0[i], m, l, r) >= i) {
              t0[i] += 1;
            }
          }
          for (const usize i : rep(1, 8)) {
            while (sum(m, t1[i], l, r) >= i) {
              t1[i] -= 1;
            }
          }
          for (const usize i : rep(0, k + 1)) {
            ans += u64(t0[i] - t0[i + 1]) * (t1[k - i + 1] - t1[k - i]);
          }
        }
      }
      solve(x0, m, y0, y1);
      solve(m, x1, y0, y1);
    } else {

      const usize m = (y0 + y1) / 2;
      for (const usize l : rep(x0, x1)) {
        t0[0] = m;
        t1[0] = m;
        for (const usize i : rep(1, 8)) {
          t0[i] = y0;
          t1[i] = y1;
        }
        for (const usize r : rep(l + 1, x1 + 1)) {
          for (const usize i : rep(1, 8)) {
            while (sum(l, r, t0[i], m) >= i) {
              t0[i] += 1;
            }
          }
          for (const usize i : rep(1, 8)) {
            while (sum(l, r, m, t1[i]) >= i) {
              t1[i] -= 1;
            }
          }
          for (const usize i : rep(0, k + 1)) {
            ans += u64(t0[i] - t0[i + 1]) * (t1[k - i + 1] - t1[k - i]);
          }
        }
      }
      solve(x0, x1, y0, m);
      solve(x0, x1, m, y1);
    }
  })(0, n, 0, m);

  std::cout << ans << eoln;
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}