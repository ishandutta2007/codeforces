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
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


namespace n91 {

usize op_max(usize x, usize y) { return std::max(x, y); }
usize id_max() { return 0; }

usize op_min(usize x, usize y) { return std::min(x, y); }
usize id_min() { return 20000; }

void solve() {
  const usize n = scan<usize>();
  std::vector<usize> a(n);
  for (auto &e : a) {
    std::cin >> e;
  }
  std::reverse(a.begin(), a.end());

  const auto solve2 = [&](std::vector<usize> ra, std::vector<usize> la,
                          const usize addi) -> usize {
    usize ans_k = 0;
    for (const usize k : rep(2, n + 2)) {
      std::vector<usize> nra(n, 0), nla(n, n + 1);

      {
        // r->r
        atcoder::segtree<usize, op_max, id_max> seg(n + 2);
        for (const usize i : rep(0, n)) {
          chmax(nra[i], seg.prod(0, a[i]));
          seg.set(a[i], ra[i]);
        }
      }
      {
        // l->r
        atcoder::segtree<usize, op_max, id_max> seg(n + 2);
        for (const usize i : rep(0, n)) {
          if (i >= k + addi - 1) {
            const usize j = i - (k + addi - 1);
            seg.set(la[j], std::max(a[j], seg.get(la[j])));
          }
          chmax(nra[i], seg.prod(0, a[i]));
        }
      }
      {
        // l->l
        atcoder::segtree<usize, op_min, id_min> seg(n + 2);
        for (const usize i : rep(0, n)) {
          chmin(nla[i], seg.prod(a[i] + 1, n + 2));
          seg.set(a[i], la[i]);
        }
      }
      {
        // l->r
        atcoder::segtree<usize, op_min, id_min> seg(n + 2);
        for (const usize i : rep(0, n)) {
          if (i >= k + addi - 1) {
            const usize j = i - (k + addi - 1);
            seg.set(ra[j], std::min(a[j], seg.get(ra[j])));
          }
          chmin(nla[i], seg.prod(a[i] + 1, n + 2));
        }
      }

      {
        bool valid = false;
        for (const usize i : rep(0, n)) {
          if (nra[i] != 0 || nla[i] != n + 1) {
            valid = true;
          }
        }
        if (!valid) {
          ans_k = k - 1;
          break;
        }
      }
      ra = nra;
      la = nla;
    }
    return ans_k;
  };

  usize ans = 0;
  {
    std::vector<usize> ra(n, 0), la(n, n + 1);
    // use a[0]
    ra[0] = a[0];
    la[0] = a[0];
    chmax(ans, solve2(ra, la, 0));
  }
  {
    std::vector<usize> ra(n), la(n);
    // not use a[0]
    for (const usize i : rep(0, n)) {
      ra[i] = a[i];
      la[i] = a[i];
    }
    chmax(ans, solve2(ra, la, 1));
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