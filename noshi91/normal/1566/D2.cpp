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

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

template <class T, class Compare = std::less<T>>
long long inversion(const std::vector<T> &a, const Compare &comp = Compare()) {
  const int n = a.size();
  long long ret = 0;
  std::vector<int> idx(n);
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(),
            [&](const int x, const int y) { return comp(a[y], a[x]); });

  std::vector<int> ft(n + 1, 0);
  for (const int i_ : idx) {
    int i = i_ + 1;
    while (i <= n) {
      ft[i] += 1;
      i += i & (~i + 1);
    }
    i = i_;
    while (i != 0) {
      ret += ft[i];
      i -= i & (~i + 1);
    }
  }

  return ret;
}

#include <map>

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  const usize m = scan<usize>();
  std::map<u32, std::vector<usize>> a;
  for (const usize i : rep(0, n * m)) {
    const u32 t = scan<u32>();
    a[t].push_back(i);
  }

  for (auto &[key, b] : a) {
    std::reverse(b.begin(), b.end());
  }

  u64 ans = 0;
  for (const usize h : rep(0, n)) {
    std::vector<usize> row;
    while (row.size() < m) {
      const usize rem = m - row.size();
      auto &[key, b] = *a.begin();
      const usize take = std::min(rem, b.size());
      row.insert(row.end(), b.end() - take, b.end());
      b.erase(b.end() - take, b.end());
      if (b.empty()) {
        a.erase(a.begin());
      }
    }
    ans += inversion(row, std::greater<>());
  }

  std::cout << ans << eoln;
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