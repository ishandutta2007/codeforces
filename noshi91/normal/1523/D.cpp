//#define NDEBUG
#pragma warning(disable : 4146 2397)

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

#ifdef ONLINE_JUDGE
template <class T> constexpr T OJ_LOCAL(T oj, T) { return oj; }
#else
template <class T> constexpr T OJ_LOCAL(T, T local) { return local; }
#endif

} // namespace n91

#include <chrono>
#include <cstdint>
#include <random>

namespace random_ {
using i64 = std::int64_t;

std::mt19937_64 rnd(std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch())
                        .count());

i64 nextLong(const i64 min, const i64 max) {
  return std::uniform_int_distribution<i64>(min, max)(rnd);
}

} // namespace random_

using random_::nextLong;

#include <array>
#include <cstddef>
#include <cstdint>

std::size_t bsf32(const std::uint32_t c) noexcept {
#ifdef __GNUC__
  return __builtin_ctz(c);
#else
  static constexpr std::array<std::uint8_t, 32> table = {
      0,  1, 2,  6,  3,  11, 7,  16, 4,  14, 12, 21, 8,  23, 17, 26,
      31, 5, 10, 15, 13, 20, 22, 25, 30, 9,  19, 24, 29, 18, 28, 27};
  return table[(c & ~c + 1) * 0x4653ADF >> 27 & 0x1F];
#endif
}

std::size_t bsf64(const std::uint64_t c) noexcept {
#ifdef __GNUC__
  return __builtin_ctzll(c);
#else
  static constexpr std::array<std::uint8_t, 64> table = {
      0,  1,  2,  7,  3,  13, 8,  27, 4,  33, 14, 36, 9,  49, 28, 19,
      5,  25, 34, 17, 15, 53, 37, 55, 10, 46, 50, 39, 29, 42, 20, 57,
      63, 6,  12, 26, 32, 35, 48, 18, 24, 16, 52, 54, 45, 38, 41, 56,
      62, 11, 31, 47, 23, 51, 44, 40, 61, 30, 22, 43, 60, 21, 59, 58};
  return table[(c & ~c + 1) * 0x218A7A392DD9ABFULL >> 58 & 0x3F];
#endif
}

std::size_t bsr32(std::uint32_t c) noexcept {
#ifdef __GNUC__
  return 31 - __builtin_clz(c);
#else
  static constexpr std::array<std::uint8_t, 32> table = {
      0,  1, 2,  6,  3,  11, 7,  16, 4,  14, 12, 21, 8,  23, 17, 26,
      31, 5, 10, 15, 13, 20, 22, 25, 30, 9,  19, 24, 29, 18, 28, 27};
  c |= c >> 1;
  c |= c >> 2;
  c |= c >> 4;
  c |= c >> 8;
  c |= c >> 16;
  return table[((c >> 1) + 1) * 0x4653ADF >> 27 & 0x1F];
#endif
}

std::size_t bsr64(std::uint64_t c) noexcept {
#ifdef __GNUC__
  return 63 - __builtin_clzll(c);
#else
  static constexpr std::array<std::uint8_t, 64> table = {
      0,  1,  2,  7,  3,  13, 8,  27, 4,  33, 14, 36, 9,  49, 28, 19,
      5,  25, 34, 17, 15, 53, 37, 55, 10, 46, 50, 39, 29, 42, 20, 57,
      63, 6,  12, 26, 32, 35, 48, 18, 24, 16, 52, 54, 45, 38, 41, 56,
      62, 11, 31, 47, 23, 51, 44, 40, 61, 30, 22, 43, 60, 21, 59, 58};
  c |= c >> 1;
  c |= c >> 2;
  c |= c >> 4;
  c |= c >> 8;
  c |= c >> 16;
  c |= c >> 32;
  return table[((c >> 1) + 1) * 0x218A7A392DD9ABFULL >> 58 & 0x3F];
#endif
}

constexpr std::size_t popcount32(std::uint32_t c) noexcept {
#ifdef __GNUC__
  return __builtin_popcount(c);
#else
  c -= c >> 1 & 0x55555555;
  c = (c & 0x33333333) + (c >> 2 & 0x33333333);
  c = (c + (c >> 4)) & 0x0F0F0F0F;
  return c * 0x01010101 >> 24 & 0x3F;
#endif
}

constexpr std::size_t popcount64(std::uint64_t c) noexcept {
#ifdef __GNUC__
  return __builtin_popcountll(c);
#else
  c -= c >> 1 & 0x5555555555555555;
  c = (c & 0x3333333333333333) + (c >> 2 & 0x3333333333333333);
  c = (c + (c >> 4)) & 0x0F0F0F0F0F0F0F0F;
  return c * 0x0101010101010101 >> 56 & 0x7f;
#endif
}

constexpr bool parity32(std::uint32_t c) noexcept {
#ifdef __GNUC__
  return __builtin_parity(c);
#else
  c ^= c >> 1;
  c ^= c >> 2;
  return ((c & 0x11111111) * 0x11111111 >> 28 & 0x1) != 0;
#endif
}

constexpr bool parity64(std::uint64_t c) noexcept {
#ifdef __GNUC__
  return __builtin_parityll(c);
#else
  c ^= c >> 1;
  c ^= c >> 2;
  return ((c & 0x1111111111111111) * 0x1111111111111111 >> 60 & 0x1) != 0;
#endif
}

namespace n91 {

template <class F, class T> void kronecker(const F f, std::vector<T> &a) {
  const usize n = a.size();
  for (usize w = 1; w != n; w *= 2) {
    for (usize k = 0; k != n; k += w * 2) {
      for (usize i = 0; i != w; ++i) {
        f(a[k + i], a[k + w + i]);
      }
    }
  }
}

void solve() {
  const usize n = scan<usize>();
  const usize m = scan<usize>();
  const usize p = scan<usize>();
  std::vector<std::string> a(n);
  for (auto &e : a) {
    std::cin >> e;
  }
  usize best = 0;
  std::vector<u32> ans(m, 0);
  for (const usize iteration : rep(0, 10)) {
    const usize r = nextLong(0, n - 1);
    std::vector<usize> idx;
    for (const usize i : rep(0, m)) {
      if (a[r][i] == '1') {
        idx.push_back(i);
      }
    }
    std::vector<usize> count(1 << idx.size(), 0);
    for (const auto &v : a) {
      usize s = 0;
      for (const usize i : rep(0, idx.size())) {
        if (v[idx[i]] == '1') {
          s |= 1 << i;
        }
      }
      count[s] += 1;
    }
    kronecker([](auto &l, auto &r) { l += r; }, count);
    for (const usize s : rep(0, count.size())) {
      if (count[s] >= (n + 1) / 2) {
        if (popcount32(s) > best) {
          best = popcount32(s);
          ans.assign(m, 0);
          for (const usize i : rep(0, idx.size())) {
            if (s >> i & 1) {
              ans[idx[i]] = 1;
            }
          }
        }
      }
    }
  }

  for (const auto e : ans) {
    std::cout << e;
  }
  std::cout << eoln;
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