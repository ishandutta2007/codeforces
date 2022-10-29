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

namespace n91 {

void solve() {
  usize n = scan<usize>();
  usize m = scan<usize>();
  std::vector<i64> a(n);
  struct seg_t {
    i64 l, r;
  };
  for (auto &e : a) {
    std::cin >> e;
  }
  std::vector<seg_t> segs(m);
  for (auto &[l, r] : segs) {
    std::cin >> l >> r;
  }

  std::sort(segs.begin(), segs.end(), [](const auto &x, const auto &y) {
    if (x.l != y.l) {
      return x.l < y.l;
    } else {
      return x.r > y.r;
    }
  });

  {
    std::vector<seg_t> s;
    for (const auto &[l, r] : segs) {
      while (!s.empty() && s.back().l <= l && r <= s.back().r) {
        s.pop_back();
      }
      s.push_back({l, r});
    }
    segs = std::move(s);
  }

  a.push_back(-1e13);
  a.push_back(1e13);
  std::sort(a.begin(), a.end());
  n = a.size();

  std::vector<std::vector<seg_t>> itv(n);

  {
    std::vector<seg_t> s;
    usize i = 0, j = 0;
    while (j != segs.size()) {
      if (i == a.size() || segs[j].r < a[i]) {
        s.push_back(segs[j]);
        itv[i].push_back(segs[j]);
        j += 1;
      } else if (segs[j].l <= a[i]) {
        j += 1;
      } else {
        i += 1;
      }
    }
    segs = std::move(s);
  }

  m = segs.size();

  std::vector<i64> dp1(n, 1e13), dp2(n, 1e13);
  dp1[0] = dp2[0] = 0;
  for (const usize i : rep(1, n)) {
    // a[i-1], a[i]
    // itv[i]
    const usize mm = itv[i].size();
    for (const usize j : rep(0, mm + 1)) {
      const i64 l = (j == 0 ? a[i - 1] : itv[i][j - 1].l) - a[i - 1];
      const i64 r = a[i] - (j == mm ? a[i] : itv[i][j].r);
      chmin(dp1[i], std::min(dp1[i - 1] + 2 * l, dp2[i - 1] + l) + r);
      chmin(dp2[i], std::min(dp1[i - 1] + 2 * l, dp2[i - 1] + l) + 2 * r);
    }
  }

  std::cout << dp1.back() << eoln;
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