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

#include <bitset>

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

#include <algorithm>
#include <utility>
#include <vector>

namespace n91 {

template <class T> std::vector<T> divisors(const T &n) {
  std::vector<T> ret;
  T i = static_cast<T>(1);
  while (i * i < n) {
    if (n % i == static_cast<T>(0)) {
      ret.push_back(i);
      ret.push_back(n / i);
    }
    ++i;
  }
  if (i * i == n) {
    ret.push_back(i);
  }
  std::sort(ret.begin(), ret.end());
  ret.shrink_to_fit();
  return std::move(ret);
}

} // namespace n91

#include <utility>
#include <vector>

namespace n91 {

template <class T> std::vector<T> factorize(T n) noexcept {
  std::vector<T> ret;
  for (T p = static_cast<T>(2); p * p <= n; ++p) {
    while (n % p == static_cast<T>(0)) {
      n /= p;
      ret.push_back(p);
    }
  }
  if (n != static_cast<T>(1)) {
    ret.push_back(std::move(n));
  }
  ret.shrink_to_fit();
  return std::move(ret);
}

} // namespace n91

#include <numeric>

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  std::vector<u64> a(n);
  for (auto &e : a) {
    std::cin >> e;
  }
  const auto solve = [&](const u64 d) -> u64 {
    const auto div = divisors(d);
    const usize m = div.size();
    auto fs = factorize(d);
    fs.erase(std::unique(fs.begin(), fs.end()), fs.end());
    const auto idx = [&](const u64 x) -> usize {
      return std::lower_bound(div.begin(), div.end(), x) - div.begin();
    };
    std::vector<usize> count(m, 0);
    for (const u64 e : a) {
      count[idx(std::gcd(d, e))] += 1;
    }
    for (const u64 f : fs) {
      usize r = m - 1;
      for (const usize i : revrep(0, idx(d / f) + 1)) {
        while (div[r] > div[i] * f) {
          r -= 1;
        }
        if (div[r] == div[i] * f) {
          count[i] += count[r];
        }
      }
    }
    for (const usize i : revrep(0, m)) {
      if (count[i] * 2 >= n) {
        return div[i];
      }
    }
    return 0;
  };

  const usize iteration = 10;
  u64 ans = 0;
  for (const usize i : rep(0, iteration)) {
    chmax(ans, solve(a[nextLong(0, n - 1)]));
  }
  std::cout << ans << eoln;
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