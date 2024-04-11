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
template <class T> T ceildiv(const T &l, const T &r) {
  return l / r + (l % r != 0 ? 1 : 0);
}

#ifdef N91_LOCAL
#define OJ_LOCAL(a, b) b
#else
#define OJ_LOCAL(a, b) a
#endif

} // namespace n91

namespace n91 {

void main_() {
  const usize n = scan<usize>();
  const usize k = scan<usize>();

  const auto get_or = [&](const usize i, const usize j) -> u32 {
    std::cout << "or " << i + 1 << " " << j + 1 << "\n" << std::flush;
    u32 a;
    std::cin >> a;
    return a;
  };

  const auto get_and = [&](const usize i, const usize j) -> u32 {
    std::cout << "and " << i + 1 << " " << j + 1 << "\n" << std::flush;
    u32 a;
    std::cin >> a;
    return a;
  };

  const auto finish = [&](const u32 a) {
    std::cout << "finish " << a << "\n" << std::flush;
  };

  std::vector<u32> a(n);
  {
    const std::vector<std::pair<usize, usize>> qs{{0, 1}, {1, 2}, {0, 2}};
    std::vector<u32> res(6);
    for (const usize i : rep(0, 3)) {
      auto [s, t] = qs[i];
      res[i * 2] = get_or(s, t);
      res[i * 2 + 1] = get_and(s, t);
    }
    for (const usize p : rep(0, 30)) {
      std::vector<u32> res_bit(6);
      for (const usize i : rep(0, 6)) {
        res_bit[i] = res[i] >> p & 1;
      }
      for (const usize set : rep(0, 8)) {
        std::vector<u32> res_exp(6);
        for (const usize i : rep(0, 3)) {
          auto [s, t] = qs[i];
          res_exp[i * 2] = (set >> s & 1) | (set >> t & 1);
          res_exp[i * 2 + 1] = (set >> s & 1) & (set >> t & 1);
        }
        if (res_bit == res_exp) {
          for (const usize i : rep(0, 3)) {
            a[i] |= (set >> i & 1) << p;
          }
        }
      }
    }
  }

  for (const usize i : rep(3, n)) {
    u32 s = get_or(0, i);
    u32 t = get_and(0, i);
    a[i] = a[0];
    for (const usize p : rep(0, 30)) {
      if (!(a[0] >> p & 1) && (s >> p & 1)) {
        a[i] |= u32(1) << p;
      }
      if ((a[0] >> p & 1) && !(t >> p & 1)) {
        a[i] &= ~(u32(1) << p);
      }
    }
  }

  std::sort(a.begin(), a.end());
  finish(a[k - 1]);
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