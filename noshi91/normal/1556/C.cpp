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

#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

template <class T> class compress {
  std::vector<T> v;

public:
  compress(const std::size_t n = 0) : v() { v.reserve(n); }
  void add(T x) { v.push_back(std::move(x)); }
  void build() {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
  }
  std::size_t operator()(const T &x) const {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin();
  }
  const T &operator[](const std::size_t i) const { return v[i]; }
  std::size_t size() const { return v.size(); }
};

namespace n91 {

void main_() {
  const usize n = scan<usize>();
  std::vector<i64> c(n);
  for (auto &e : c) {
    std::cin >> e;
  }

  compress<i64> comp;
  {
    i64 h = 0;
    comp.add(0);
    for (const usize i : rep(0, n)) {
      if (i % 2 == 0) {
        h += c[i];
      } else {
        h -= c[i];
      }
      comp.add(h);
    }
    comp.build();
  }

  u64 ans = 0;
  std::vector<u64> st(comp.size(), 0);
  st[comp(0)] = 1;
  usize h = 0;
  for (const usize i : rep(0, n)) {
    if (i % 2 == 0) {
      usize id = comp(h);
      h += c[i];
      do {
        id += 1;
        st[id] = 1;
      } while (comp[id] != h);
    } else {
      usize id = comp(h);
      h -= c[i];
      do {
        id -= 1;
        if (st[id] != 0) {
          ans += (comp[id + 1] - comp[id] - 1);
        }
        ans += st[id];
      } while (comp[id] != h);
      st[id] += 1;
    }
  }

  std::cout << ans << eoln;
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