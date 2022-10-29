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

#pragma GCC target("popcnt")

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

void main_() {
  const usize n = scan<usize>();
  std::vector<i64> b(n);
  for (auto &e : b) {
    std::cin >> e;
  }

  if (n == 2) {
    if (b[0] == b[1]) {
      std::cout << "YES" << eoln;
      std::cout << b[0] << " " << 0 << eoln;
    } else {
      std::cout << "NO" << eoln;
    }
    return;
  }
  if (n == 3) {
    i64 s = b[0] + b[1] + b[2];
    if (s % 2 == 0) {
      std::cout << "YES" << eoln;
      s /= 2;
      std::cout << s - b[0] << " " << s - b[1] << " " << s - b[2] << eoln;
    } else {
      std::cout << "NO" << eoln;
    }
    return;
  }

  for (const usize i : rep(0, n)) {
    if (b[i] % 2 == 0) {
      std::swap(b[0], b[i]);
    }
  }
  if (b[0] % 2 == 0) {
    usize x = -1, y = -1;
    for (const usize i : rep(1, n)) {
      for (const usize j : rep(1, i)) {
        if ((b[i] + b[j]) % 2 == 0) {
          x = j;
          y = i;
        }
      }
    }
    std::swap(b[1], b[x]);
    std::swap(b[2], b[y]);
    std::vector<i64> a(n);
    {
      i64 s = b[0] + b[1] + b[2];
      s /= 2;
      a[0] = s - b[0];
      a[1] = s - b[1];
      a[2] = s - b[2];
    }
    for (const usize i : rep(3, n)) {
      a[i] = b[i] - a[0];
    }
    std::cout << "YES" << eoln;
    for (const usize i : rep(0, n)) {
      std::cout << a[i] << " \n"[i + 1 == n];
    }
    return;
  }

  usize t_count = std::min<usize>(n / 2, 13);
  std::vector<u32> bucket(1 + t_count * OJ_LOCAL(1000000, 100), -1);
  std::vector<usize> xv, yv;
  {
    const usize limit = std::min<usize>(n, 27);
    rec_lambda([&](const auto &en, const usize i, const u32 idx,
                   const usize id_cnt, const i64 sum) -> void {
      if (id_cnt + (limit - i) < t_count) {
        return;
      }
      if (id_cnt == t_count) {
        if (bucket[sum] == -1) {
          bucket[sum] = idx;
        } else {
          for (const usize j : rep(0, n)) {
            if (bucket[sum] >> j & 1) {
              xv.push_back(j);
            }
            if (idx >> j & 1) {
              yv.push_back(j);
            }
          }
        }
        return;
      }
      if (i == limit) {
        return;
      }
      en(i + 1, idx | u32(1) << i, id_cnt + 1, sum + b[i]);
      if (!xv.empty()) {
        return;
      }
      en(i + 1, idx, id_cnt, sum);
    })(0, 0, 0, 0);
  }
  if (xv.empty()) {
    std::cout << "NO" << eoln;
    return;
  }

  std::vector<usize> count(n, 0);
  {
    for (const usize i : rep(0, t_count)) {
      count[xv[i]] += 1;
      count[yv[i]] += 1;
    }
    std::vector<usize> nxv, nyv;
    for (const usize i : rep(0, t_count)) {
      if (count[xv[i]] == 1) {
        nxv.push_back(xv[i]);
      }
      if (count[yv[i]] == 1) {
        nyv.push_back(yv[i]);
      }
    }
    xv = nxv;
    yv = nyv;
    t_count = nxv.size();
  }

  //*
  assert(xv.size() == t_count && yv.size() == t_count);
  /*/
  xv.resize(t_count);
  yv.resize(t_count);
  //*/

  std::vector<i64> a;
  a.push_back(0);
  for (const usize i : rep(0, t_count)) {
    a.push_back(b[xv[i]] - a.back());
    if (i + 1 != t_count) {
      a.push_back(b[yv[i]] - a.back());
    }
  }

  // assert(a[2 * t_count - 1] == b[yv[t_count - 1]]);

  for (const usize i : rep(0, n)) {
    if (count[i] != 1) {
      a.push_back(b[i]);
    }
  }

  /*
  assert(a.size() == n);
  /*/
  a.resize(n);
  //*/

  std::cout << "YES" << eoln;
  for (const usize i : rep(0, n)) {
    std::cout << a[i] << " \n"[i + 1 == n];
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