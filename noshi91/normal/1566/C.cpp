//#define NDEBUG
#pragma warning(disable : 4146)

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iomanip>
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
using f64 = double;

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

i64 floor_div(const i64 n, const i64 d) {
  assert(d != 0);
  return n / d - static_cast<i64>((n ^ d) < 0 && n % d != 0);
}

i64 ceil_div(const i64 n, const i64 d) {
  assert(d != 0);
  return n / d + static_cast<i64>((n ^ d) >= 0 && n % d != 0);
}

#ifdef N91_LOCAL
#define OJ_LOCAL(a, b) b
#else
#define OJ_LOCAL(a, b) a
#endif

} // namespace n91

#include <array>

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  std::array<std::string, 2> s;
  std::cin >> s[0] >> s[1];

  std::vector<std::array<isize, 4>> dp(n + 1);
  dp[0][0] = 0;
  dp[0][1] = dp[0][2] = dp[0][3] = -1e9;
  for (const usize i : rep(0, n)) {
    for (const usize t : rep(0, 4)) {
      dp[i + 1][t] = -1e9;
    }
    for (const usize tt : rep(0, 4)) {
      usize t = tt;
      t |= 1 << (s[0][i] - '0');
      t |= 1 << (s[1][i] - '0');
      chmax(dp[i + 1][t], dp[i][tt]);
    }
    chmax(dp[i + 1][0], dp[i + 1][1] + 1);
    chmax(dp[i + 1][0], dp[i + 1][2] + 0);
    chmax(dp[i + 1][0], dp[i + 1][3] + 2);
  }

  std::cout << dp[n][0] << eoln;
}

void main_() {
  const usize t = scan<usize>();
  for (const usize i : rep(0, t)) {
    solve();
  }
}

} // namespace n91

int main() {
  //*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  std::cout << std::setprecision(20);
  n91::main_();
  return 0;
}