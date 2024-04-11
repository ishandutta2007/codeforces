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

void main_() {
  //*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/

  static constexpr usize NL = 501;
  // mid, zero, diff, not reversed
  std::array<std::array<std::array<std::array<isize, 2>, NL>, NL>, 2> dp;
  for (const usize m : rep(0, 2)) {
    for (const usize z : rep(0, NL)) {
      for (const usize d : rep(0, NL)) {
        for (const usize r : rep(0, 2)) {
          isize &t = dp[m][z][d][r];
          t = 2000;
          // base
          if (m == 0 && z == 0 && d == 0) {
            t = 0;
          }
          // reverse
          if (r == 1 && d != 0) {
            chmin(t, -dp[m][z][d][0]);
          }
          // take mid
          if (m == 1) {
            chmin(t, -dp[0][z][d][1] + 1);
          }
          // take zero
          if (z != 0 && d + 1 < NL) {
            chmin(t, -dp[m][z - 1][d + 1][1] + 1);
          }
          // take diff
          if (d != 0) {
            chmin(t, -dp[m][z][d - 1][1] + 1);
          }
        }
      }
    }
  }

  const usize t = scan<usize>();
  for (const usize i : rep(0, t)) {
    const usize n = scan<usize>();
    const std::string s = scan<std::string>();
    usize m = 0, z = 0, d = 0;
    if (n % 2 == 1 && s[n / 2] == '0') {
      m = 1;
    }
    for (const usize i : rep(0, n / 2)) {
      if (s[i] != s[n + ~i]) {
        d += 1;
      } else if (s[i] == '0') {
        z += 1;
      }
    }
    const isize ans = dp[m][z][d][1];
    if (ans < 0) {
      std::cout << "ALICE";
    } else if (ans > 0) {
      std::cout << "BOB";
    } else {
      std::cout << "DRAW";
    }
    std::cout << eoln;
  }
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}