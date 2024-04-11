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
#include <cassert>
#include <cstddef>
#include <functional>
#include <vector>

namespace n91 {

template <class T, class Operate = std::plus<T>, class Invert = std::negate<T>>
class cumulative_sum {
public:
  using value_type = T;

private:
  using size_t = std::size_t;

  Operate oper;
  Invert inve;
  std::vector<T> prefix;

public:
  cumulative_sum() = default;
  explicit cumulative_sum(const std::vector<T> &c,
                          const Operate &oper = Operate(), const T &iden = T(),
                          const Invert &inve = Invert())
      : oper(oper), inve(inve), prefix() {
    prefix.reserve(c.size() + 1);
    prefix.push_back(iden);
    for (const T &e : c) {
      prefix.push_back(oper(prefix.back(), e));
    }
  }

  T fold(const size_t first, const size_t last) const {
    assert(first <= last);
    assert(last < prefix.size());
    return oper(inve(prefix[first]), prefix[last]);
  }
  T operator[](const size_t index) const { return fold(index, index + 1); }
};

} // namespace n91

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  std::vector<u64> a(n), b(n);
  for (auto &e : a) {
    std::cin >> e;
  }
  for (auto &e : b) {
    std::cin >> e;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  const cumulative_sum ac(a);
  const cumulative_sum bc(b);

  const auto ak = [&](const usize k) -> u64 {
    const usize take = k - k / 4;
    const usize add = k - n;
    if (take <= add) {
      return u64(100) * take;
    }
    const usize rem = take - add;
    return ac.fold(n - rem, n) + u64(100) * add;
  };
  const auto bk = [&](const usize k) -> u64 {
    const usize take = k - k / 4;
    if (take <= n) {
      return bc.fold(n - take, n);
    }
    return bc.fold(0, n);
  };

  for (const usize k : rep(n, 5 * n + 100)) {
    if (ak(k) >= bk(k)) {
      std::cout << k - n << eoln;
      return;
    }
  }
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