//#define NDEBUG

#pragma region cp_template

#include <algorithm>
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
  rec_lambda(F &&f) : f(std::move(f)) {}
  template <class... Args> auto operator()(Args &&... args) const {
    return f(*this, std::forward<Args>(args)...);
  }
};
template <class F> auto make_rec(F &&f) { return rec_lambda<F>(std::move(f)); }
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

#pragma endregion cp_template

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

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  const u32 x = scan<u32>();
  const u32 y = scan<u32>();
  u32 ans = std::numeric_limits<u32>::max();
  std::vector<u32> ans_v;
  for (const u32 d : divisors(y - x)) {
    if ((y - x) / d + 1 > n) {
      continue;
    }
    std::vector<u32> v;
    v.push_back(x);
    while (v.back() > d) {
      v.push_back(v.back() - d);
    }
    std::reverse(v.begin(), v.end());
    while (v.back() < y || v.size() < n) {
      v.push_back(v.back() + d);
    }
    std::reverse(v.begin(), v.end());
    v.resize(n);
    std::reverse(v.begin(), v.end());
    if (ans > v.back()) {
      ans = v.back();
      ans_v = std::move(v);
    }
  }
  for (const usize i : rep(0, n)) {
    std::cout << ans_v[i] << " \n"[i + 1 == n];
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