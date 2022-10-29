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

#include <numeric>

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  std::vector<u32> a(n);
  for (auto &e : a) {
    std::cin >> e;
  }
  std::vector<isize> idx;
  idx.push_back(-1);
  for (const usize i : rep(0, n)) {
    const bool left = i != 0 && a[i - 1] <= a[i];
    const bool right = i + 1 == n || a[i] <= a[i + 1];
    if (left != right) {
      idx.push_back(i);
    }
  }
  idx.push_back(n);
  auto b = a;
  for (const usize i : rep(0, idx.size() - 1)) {
    if (i % 2 == 0) {
      for (isize j = idx[i + 1]; j != idx[i] + 1; j -= 1) {
        chmax(b[j - 1], b[j]);
        while (std::gcd(b[j - 1], b[j]) != 1) {
          b[j - 1] += 1;
        }
      }
      const usize t = idx[i];
      if (t != -1) {
        chmax(b[t], std::max(b[t - 1], b[t + 1]));
        while (std::gcd(b[t], b[t - 1]) != 1 || std::gcd(b[t], b[t + 1]) != 1) {
          b[t] += 1;
        }
      }
    } else {
      for (isize j = idx[i]; j != idx[i + 1] - 1; j += 1) {
        chmax(b[j + 1], b[j]);
        while (std::gcd(b[j], b[j + 1]) != 1) {
          b[j + 1] += 1;
        }
      }
    }
  }

  std::vector<std::tuple<usize, usize, u32, u32>> ans;

  for (const usize i : rep(0, idx.size() - 1)) {
    if (i % 2 == 1) {
      for (isize j = idx[i + 1]; j != idx[i]; j -= 1) {
        if (j != n) {
          ans.emplace_back(j - 1, j, a[j - 1], b[j]);
        }
      }
    } else {
      for (isize j = idx[i] + 1; j != idx[i + 1]; j += 1) {
        ans.emplace_back(j, j + 1, b[j], a[j + 1]);
      }
    }
  }

  std::cout << ans.size() << eoln;
  for (auto [i, j, x, y] : ans) {
    std::cout << i + 1 << " " << j + 1 << " " << x << " " << y << eoln;
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