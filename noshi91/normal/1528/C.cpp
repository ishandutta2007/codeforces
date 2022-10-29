//#define NDEBUG
#pragma warning(disable : 4146)

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

namespace beet {
using namespace std;
// BEGIN CUT HERE
class HLD {
private:
  void dfs_sz(int v) {
    auto &es = G[v];
    if (~par[v])
      es.erase(find(es.begin(), es.end(), par[v]));

    for (int &u : es) {
      par[u] = v;
      dfs_sz(u);
      sub[v] += sub[u];
      if (sub[u] > sub[es[0]])
        swap(u, es[0]);
    }
  }

  void dfs_hld(int v, int &pos) {
    vid[v] = pos++;
    inv[vid[v]] = v;
    for (int u : G[v]) {
      if (u == par[v])
        continue;
      nxt[u] = (u == G[v][0] ? nxt[v] : u);
      dfs_hld(u, pos);
    }
    out[v] = pos;
  }

public:
  vector<vector<int>> G;

  // vid: vertex -> idx
  // inv: idx -> vertex
  vector<int> vid, nxt, sub, par, inv, out;

  HLD(int n)
      : G(n), vid(n, -1), nxt(n), sub(n, 1), par(n, -1), inv(n), out(n) {}

  void add_edge(int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r = 0) {
    int pos = 0;
    dfs_sz(r);
    nxt[r] = r;
    dfs_hld(r, pos);
  }

  int lca(int u, int v) {
    while (1) {
      if (vid[u] > vid[v])
        swap(u, v);
      if (nxt[u] == nxt[v])
        return u;
      v = par[nxt[v]];
    }
  }

  template <typename F> void for_each(int u, int v, const F &f) {
    while (1) {
      if (vid[u] > vid[v])
        swap(u, v);
      f(max(vid[nxt[v]], vid[u]), vid[v] + 1);
      if (nxt[u] != nxt[v])
        v = par[nxt[v]];
      else
        break;
    }
  }

  template <typename F> void for_each_edge(int u, int v, const F &f) {
    while (1) {
      if (vid[u] > vid[v])
        swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(vid[nxt[v]], vid[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v)
          f(vid[u] + 1, vid[v] + 1);
        break;
      }
    }
  }
};
// END CUT HERE
} // namespace beet


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

usize op(usize l, usize r) { return l + r; }
usize id() { return 0; }

void solve() {
  const usize n = scan<usize>();
  auto g = md_vec(n, 0, usize());
  for (const usize i : rep(1, n)) {
    g[scan<usize>() - 1].push_back(i);
  }
  beet::HLD hld(n);
  for (const usize i : rep(1, n)) {
    hld.add_edge(i, scan<usize>() - 1);
  }
  hld.build();
  atcoder::segtree<usize, op, id> seg(n);
  const auto add = [&](const usize i, const usize x) -> void {
    seg.set(i, seg.get(i) + x);
  };
  usize ans = 0;
  rec_lambda([&](const auto &dfs, const usize v) -> void {
    bool added = (seg.prod(hld.vid[v], hld.out[v]) == 0);
    usize rem = n;
    if (added) {
      hld.for_each(0, v, [&](const usize l, const usize r) -> void {
        if (seg.prod(l, r) != 0) {
          assert(rem == n);
          rem = seg.max_right(l, [](const usize x) { return x == 0; });
        }
      });
      assert(seg.get(hld.vid[v]) == 0);
      add(hld.vid[v], 1);
      if (rem != n) {
        assert(seg.get(rem) == 1);
        add(rem, -1);
      }
    }

    chmax(ans, seg.prod(0, n));

    for (const usize c : g[v]) {
      dfs(c);
    }

    if (added) {
      assert(seg.get(hld.vid[v]) == 1);
      add(hld.vid[v], -1);
      if (rem != n) {
        assert(seg.get(rem) == 0);
        add(rem, 1);
      }
    }
  })(0);

  std::cout << ans << eoln;
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