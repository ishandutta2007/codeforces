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


#include <ext/rope>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

using rope = __gnu_cxx::rope<char>;

const int INF = (int) 1e9;

int my_min(int a, int b) {
  return min(a, b);
}

int my_max(int a, int b) {
  return max(a, b);
}

int pos_inf() {
  return INF;
}

int neg_inf() {
  return -INF;
}

class GAmShZWinsABet {
 public:
  string phase1(string s) {
    vector<int> balances;
    int balance = 0;
    balances.push_back(0);
    for (char c : s) {
      if (c == '(') ++balance; else --balance;
      balances.push_back(balance);
    }
    atcoder::segtree<int, my_min, pos_inf> min_tree(balances);
    atcoder::segtree<int, my_max, neg_inf> max_tree(balances);

    auto handleBalanced = [&](auto self, int left, int right, bool closingAfter) {
      assert(left <= right);
      if (left == right) return rope();
      vector<rope> children;
      int at = left;
      bool canClear = true;
      while (at < right) {
        assert(balances[at] == balances[left]);
        int firstDown = min_tree.max_right(at + 1, [&](int x) { return x > balances[at]; });
        rope child;
        if (firstDown > right) {
          child = rope('(') + self(self, at + 1, right, false);
          canClear = false;
        } else {
          child = rope('(') + self(self, at + 1, firstDown - 1, true) + ')';
        }
        while (!children.empty() && children.back() > child) {
          children.pop_back();
        }
        children.push_back(child);
        /*for (auto x : children) cerr << x << ",";
        cerr << endl;*/
        at = firstDown;
      }
      if (!closingAfter && canClear) return rope();
      //assert(at == right);
      rope res;
      for (auto child : children) {
        res += child;
      }
      return res;
    };

    rope t;
    int at = 0;
    while (at < s.size()) {
      int firstDown = min_tree.max_right(at, [&](int x) { return x >= balances[at]; });
      if (firstDown > s.size()) {
        t += handleBalanced(handleBalanced, at, s.size(), false);
        break;
      }
      t += handleBalanced(handleBalanced, at, firstDown - 1, true);
      at = firstDown;
      t += ')';
      /*int to = max_tree.prod(at, firstDown);
      assert(to > balances[at]);
      int toWhere = max_tree.max_right(at, [&](int x) { return x < to; });
      for (int i = balances[at]; i < to; ++i) {
        t += '(';
      }
      at = toWhere;*/
    }
    return string(all(t));
  }

  string phase2(string s) {
    return s;
  }

  void solveOne() {
    string s;
    cin >> s;
    s = phase1(s);
    s = phase2(s);
    cout << s << endl;
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    GAmShZWinsABet solver;


    solver.solve();
    return 0;
}