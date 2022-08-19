/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#undef NDEBUG

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
// AtCoder library from https://github.com/atcoder/ac-library
#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1





#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
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

#endif  // ATCODER_INTERNAL_BITOP_HPP



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

#endif  // ATCODER_SEGTREE_HPP



#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

ii op(ii a, ii b) {
  return max(a, b);
}

ii unit() {
  return {0, 0};
}

using segtree = atcoder::segtree<ii, op, unit>;

class DPerestanovkaDlyaBuryonki {
 public:
  void solveOne() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    segtree tree(n);
    for (int i = 0; i < n; ++i) {
      tree.set(i, {p[i], i});
    }
    vector<vector<int>> children(n);
    auto process = [&](auto self, int left, int right) -> int {
      if (left >= right) return -1;
      auto [v, p] = tree.prod(left, right);
      int child = self(self, left, p);
      if (child >= 0) children[p].push_back(child);
      child = self(self, p + 1, right);
      if (child >= 0) children[p].push_back(child);
      return p;
    };
    int root = process(process, 0, n);
    int k = 0;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      if (x == 0) {
        ++k;
        x = -k;
      }
    }
    vector<int> s(k - 1);
    for (auto& x : s) cin >> x;
    sort(all(s));

    vector<ii> bound(k);
    bool all_bad = false;
    auto dfs = [&](auto self, int root, int above) -> int {
      int below = 0;
      if (a[root] < 0) {
        bound[-a[root] - 1].second = above;
      } else {
        above = min(above, a[root]);
        below = max(below, a[root]);
      }
      for (int child : children[root]) {
        below = max(below, self(self, child, above));
      }
      if (below > above) {
        all_bad = true;
      }
      if (a[root] < 0) {
        bound[-a[root] - 1].first = below;
      }
      return below;
    };
    dfs(dfs, root, (int) 1.1e6);

    vector<ii> good_segments;
    if (!all_bad) {
      sort(all(bound), [](const ii &u, const ii &v) {
        return u.second < v.second;
      });

      set<ii> avail;
      for (int i = 0; i < s.size(); ++i) {
        avail.emplace(s[i], i);
      }
      vector<int> match(s.size(), -1);
      int skipped = -1;
      for (int i = 0; i < bound.size(); ++i) {
        const auto &u = bound[i];
        auto it = avail.lower_bound(ii(u.first, -1));
        if (it != avail.end() && it->first < u.second) {
          match[it->second] = i;
          avail.erase(it);
        } else {
          skipped = i;
        }
      }

      if (!avail.empty()) {
        all_bad = true;
      } else {
        for (int i = 0; i < s.size(); ++i) {
          avail.emplace(s[i], i);
        }
        auto dfs2 = [&](auto self, int i) -> void {
          const auto &u = bound[i];
          auto it = avail.lower_bound(ii(u.first, -1));
          vector<int> to_process;
          while (it != avail.end() && it->first < u.second) {
            to_process.push_back(it->second);
            auto sit = it;
            ++it;
            avail.erase(sit);
          }
          for (int x : to_process) {
            self(self, match[x]);
          }
        };
        dfs2(dfs2, skipped);

        vector<bool> good(bound.size(), true);
        for (const auto& v : avail) {
          good[match[v.second]] = false;
        }

        vector<ii> changes;
        for (int i = 0; i < bound.size(); ++i) {
          if (good[i]) {
            changes.emplace_back(bound[i].first, 1);
            changes.emplace_back(bound[i].second, -1);
          }
        }
        sort(all(changes));

        int balance = 0;
        int start = -1;
        for (const auto& u : changes) {
          if (balance == 0) {
            assert(u.second == 1);
            start = u.first;
          }
          balance += u.second;
          if (balance == 0) {
            good_segments.emplace_back(start, u.first);
            start = -1;
          }
        }
        assert(balance == 0);
      }
    }

    for (int qi = 0; qi < q; ++qi) {
      int d;
      cin >> d;
      auto it = lower_bound(all(good_segments), ii(d, -1));
      if (it != good_segments.begin()) {
        --it;
        if (it->first < d && it->second > d) {
          cout << "YES\n";
          continue;
        }
      }
      cout << "NO\n";
    }
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      // cout << "Case #" << (it + 1) << ": ";
      solveOne();
    }
  }
};

// #define st_mtimespec st_mtim

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    DPerestanovkaDlyaBuryonki solver;


    solver.solve();
    return 0;
}