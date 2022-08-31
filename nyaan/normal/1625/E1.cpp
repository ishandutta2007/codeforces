/**
 *  date : 2022-01-13 00:20:43
 */

#define NDEBUG
using namespace std;

// intrinstic
#include <immintrin.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// utility
namespace Nyaan {
using ll = long long;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
using vi = vector<int>;
using vl = vector<long long>;
using vd = V<double>;
using vs = V<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

template <typename T, typename U>
struct P : pair<T, U> {
  template <typename... Args>
  P(Args... args) : pair<T, U>(args...) {}

  using pair<T, U>::first;
  using pair<T, U>::second;

  T &x() { return first; }
  const T &x() const { return first; }
  U &y() { return second; }
  const U &y() const { return second; }

  P &operator+=(const P &r) {
    first += r.first;
    second += r.second;
    return *this;
  }
  P &operator-=(const P &r) {
    first -= r.first;
    second -= r.second;
    return *this;
  }
  P &operator*=(const P &r) {
    first *= r.first;
    second *= r.second;
    return *this;
  }
  P operator+(const P &r) const { return P(*this) += r; }
  P operator-(const P &r) const { return P(*this) -= r; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(int r) const { return {first * r, second * r}; }

  P operator-() const { return P{-first, -second}; }
};

using pl = P<ll, ll>;
using pi = P<int, int>;
using vp = V<pl>;

constexpr int inf = 1001001001;
constexpr long long infLL = 4004004004004004004LL;

template <typename T>
int sz(const T &t) {
  return t.size();
}

template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}

template <typename T>
inline T Max(const vector<T> &v) {
  return *max_element(begin(v), end(v));
}
template <typename T>
inline T Min(const vector<T> &v) {
  return *min_element(begin(v), end(v));
}
template <typename T>
inline long long Sum(const vector<T> &v) {
  return accumulate(begin(v), end(v), 0LL);
}

template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}

constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);
  return ret;
}

template <typename T, typename U>
pair<T, U> mkp(const T &t, const U &u) {
  return make_pair(t, u);
}

template <typename T>
vector<T> mkrui(const vector<T> &v, bool rev = false) {
  vector<T> ret(v.size() + 1);
  if (rev) {
    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];
  } else {
    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  }
  return ret;
};

template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

template <typename F>
vector<int> mkord(int N, F f) {
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}

template <typename T>
vector<int> mkinv(vector<T> &v) {
  int max_val = *max_element(begin(v), end(v));
  vector<int> inv(max_val + 1, -1);
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

template <typename T>
bool nxp(vector<T> &v) {
  return next_permutation(begin(v), end(v));
}

}  // namespace Nyaan

// bit operation
namespace Nyaan {
__attribute__((target("popcnt"))) inline int popcnt(const u64 &a) {
  return _mm_popcnt_u64(a);
}
inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }
inline int ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }
inline int msb(const u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }
template <typename T>
inline int gbit(const T &a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void sbit(T &a, int i, bool b) {
  if (gbit(a, i) != b) a ^= T(1) << i;
}
constexpr long long PW(int n) { return 1LL << n; }
constexpr long long MSK(int n) { return (1LL << n) - 1; }
}  // namespace Nyaan

// inout
namespace Nyaan {

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  int s = (int)v.size();
  for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

ostream &operator<<(ostream &os, __int128_t x) {
  if (x == 0) return os << 0;
  if (x < 0) os << '-', x = -x;
  string S;
  while (x) S.push_back('0' + x % 10), x /= 10;
  reverse(begin(S), end(S));
  return os << S;
}
ostream &operator<<(ostream &os, __uint128_t x) {
  if (x == 0) return os << 0;
  string S;
  while (x) S.push_back('0' + x % 10), x /= 10;
  reverse(begin(S), end(S));
  return os << S;
}

void in() {}
template <typename T, class... U>
void in(T &t, U &...u) {
  cin >> t;
  in(u...);
}

void out() { cout << "\n"; }
template <typename T, class... U, char sep = ' '>
void out(const T &t, const U &...u) {
  cout << t;
  if (sizeof...(u)) cout << sep;
  out(u...);
}

void outr() {}
template <typename T, class... U, char sep = ' '>
void outr(const T &t, const U &...u) {
  cout << t;
  outr(u...);
}

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

}  // namespace Nyaan

// debug
namespace DebugImpl {

template <typename U, typename = void>
struct is_specialize : false_type {};
template <typename U>
struct is_specialize<
    U, typename conditional<false, typename U::iterator, void>::type>
    : true_type {};
template <typename U>
struct is_specialize<
    U, typename conditional<false, decltype(U::first), void>::type>
    : true_type {};
template <typename U>
struct is_specialize<U, enable_if_t<is_integral<U>::value, void>> : true_type {
};

void dump(const char& t) { cerr << t; }

void dump(const string& t) { cerr << t; }

void dump(const bool& t) { cerr << (t ? "true" : "false"); }

void dump(__int128_t t) {
  if (t == 0) cerr << 0;
  if (t < 0) cerr << '-', t = -t;
  string S;
  while (t) S.push_back('0' + t % 10), t /= 10;
  reverse(begin(S), end(S));
  cerr << S;
}

void dump(__uint128_t t) {
  if (t == 0) cerr << 0;
  string S;
  while (t) S.push_back('0' + t % 10), t /= 10;
  reverse(begin(S), end(S));
  cerr << S;
}

template <typename U,
          enable_if_t<!is_specialize<U>::value, nullptr_t> = nullptr>
void dump(const U& t) {
  cerr << t;
}

template <typename T>
void dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr) {
  string res;
  if (t == Nyaan::inf) res = "inf";
  if constexpr (is_signed<T>::value) {
    if (t == -Nyaan::inf) res = "-inf";
  }
  if constexpr (sizeof(T) == 8) {
    if (t == Nyaan::infLL) res = "inf";
    if constexpr (is_signed<T>::value) {
      if (t == -Nyaan::infLL) res = "-inf";
    }
  }
  if (res.empty()) res = to_string(t);
  cerr << res;
}

template <typename T, typename U>
void dump(const pair<T, U>&);
template <typename T>
void dump(const pair<T*, int>&);

template <typename T>
void dump(const T& t,
          enable_if_t<!is_void<typename T::iterator>::value>* = nullptr) {
  cerr << "[ ";
  for (auto it = t.begin(); it != t.end();) {
    dump(*it);
    cerr << (++it == t.end() ? "" : ", ");
  }
  cerr << " ]";
}

template <typename T, typename U>
void dump(const pair<T, U>& t) {
  cerr << "( ";
  dump(t.first);
  cerr << ", ";
  dump(t.second);
  cerr << " )";
}

template <typename T>
void dump(const pair<T*, int>& t) {
  cerr << "[ ";
  for (int i = 0; i < t.second; i++) {
    dump(t.first[i]);
    cerr << (i == t.second - 1 ? "" : ", ");
  }
  cerr << " ]";
}

void trace() { cerr << endl; }
template <typename Head, typename... Tail>
void trace(Head&& head, Tail&&... tail) {
  cerr << " ";
  dump(head);
  if (sizeof...(tail) != 0) cerr << ",";
  trace(forward<Tail>(tail)...);
}

}  // namespace DebugImpl

#ifdef NyaanDebug
#define trc(...)                            \
  do {                                      \
    cerr << "## " << #__VA_ARGS__ << " = "; \
    DebugImpl::trace(__VA_ARGS__);          \
  } while (0)
#else
#define trc(...) (void(0))
#endif

// macro
#define each(x, v) for (auto&& x : v)
#define each2(x, y, v) for (auto&& [x, y] : v)
#define all(v) (v).begin(), (v).end()
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)
#define fi first
#define se second
#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define inl(...)         \
  long long __VA_ARGS__; \
  in(__VA_ARGS__)
#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define in2(s, t)                           \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i]);                         \
  }
#define in3(s, t, u)                        \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i]);                   \
  }
#define in4(s, t, u, v)                     \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i], v[i]);             \
  }
#define die(...)             \
  do {                       \
    Nyaan::out(__VA_ARGS__); \
    return;                  \
  } while (0)

namespace Nyaan {
void solve();
}
int main() { Nyaan::solve(); }

//

template <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),
          E (*h)(E, E), T (*ti)(), E (*ei)()>
struct RBSTLazySegmentTree {
  struct Node {
    Node *l, *r;
    I index;
    T key, sum;
    E lazy;
    int cnt;
    Node(const I &i, const T &t = ti())
        : l(), r(), index(i), key(t), sum(t), lazy(ei()), cnt(1) {}
  };

 protected:
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return new Node(args...);
  }
  inline void my_del(Ptr t) { delete t; }

  inline int count(const Ptr t) const { return t ? t->cnt : 0; }

  static uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
  }

  Ptr merge(Ptr l, Ptr r) {
    if (!l || !r) return l ? l : r;
    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
      push(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      push(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  Ptr build(int l, int r, const vector<pair<I, T>> &dat) {
    if (l == r) return nullptr;
    if (l + 1 == r) return my_new(dat[l].first, dat[l].second);
    int m = (l + r) / 2;
    return merge(build(l, m, dat), build(m, r, dat));
  };

  void push(Ptr t) {
    if (!t) return;
    if (t->lazy != ei()) {
      if (t->l) propagate(t->l, t->lazy);
      if (t->r) propagate(t->r, t->lazy);
      t->lazy = ei();
    }
  }

  Ptr update(Ptr t) {
    if (!t) return t;
    push(t);
    t->cnt = 1;
    t->sum = t->key;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  void propagate(Ptr t, const E &x) {
    if (!t) return;
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }

  // [k , k ]
  pair<Ptr, Ptr> split_left(Ptr t, I k) {
    if (!t) return {nullptr, nullptr};
    push(t);
    if (k == t->index) {
      Ptr tl = t->l;
      t->l = nullptr;
      return {tl, update(t)};
    } else if (k < t->index) {
      auto s = split_left(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split_left(t->r, k);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  // [k , k, k ]
  array<Ptr, 3> split_by_index(Ptr t, I k) {
    if (!t) return {{nullptr, nullptr, nullptr}};
    push(t);
    if (k == t->index) {
      Ptr tl = t->l, tr = t->r;
      t->l = t->r = nullptr;
      return {{tl, update(t), tr}};
    } else if (k < t->index) {
      auto s = split_by_index(t->l, k);
      t->l = s[2];
      return {{s[0], s[1], update(t)}};
    } else {
      auto s = split_by_index(t->r, k);
      t->r = s[0];
      return {{update(t), s[1], s[2]}};
    }
  }

  // t  index  (t  failed)
  I _min_index(Ptr t, const I &failed) {
    if (t == nullptr) return failed;
    while (t->l) t = t->l;
    return t->index;
  }

  // t  index  (t  failed)
  I _max_index(Ptr t, const I &failed) {
    if (t == nullptr) return failed;
    while (t->r) t = t->r;
    return t->index;
  }

  // t [0, i  fold  true  i 
  // exclusive  ( [0,])  failed(inf)
  // inclusive  ( [0,0] )  failed
  template <typename C, bool exclusive>
  I _max_right(Ptr t, C check, const I &failed) {
    if (t == nullptr) return failed;
    push(t);
    Ptr now = t;
    T prod_now = ti();
    [[maybe_unused]] I prev = failed;
    while (true) {
      if (now->l != nullptr) {
        push(now->l);
        auto pl = f(prod_now, now->l->sum);
        if (check(pl)) {
          prod_now = pl;
        } else {
          now = now->l;
          continue;
        }
      }
      auto pl = f(prod_now, now->key);
      if (!check(pl)) {
        if constexpr (exclusive) {
          return now->index;
        } else {
          return now->l ? _max_index(now->l, failed) : prev;
        }
      }
      prod_now = pl;
      if (now->r == nullptr) {
        if constexpr (exclusive) {
          return failed;
        } else {
          return now->index;
        }
      }
      push(now->r);
      if constexpr (!exclusive) prev = now->index;
      now = now->r;
    }
  }

  // t i, inf)  fold  true  i 
  // inclusive  (  )  failed
  // exlucisve  (  [, inf) )  failed
  template <typename C, bool inclusive>
  I _min_left(Ptr t, C check, const I &failed) {
    if (t == nullptr) return failed;
    push(t);
    Ptr now = t;
    T prod_now = ti();
    [[maybe_unused]] I prev = failed;
    while (true) {
      if (now->r != nullptr) {
        push(now->r);
        auto pr = f(now->r->sum, prod_now);
        if (check(pr)) {
          prod_now = pr;
        } else {
          now = now->r;
          continue;
        }
      }
      auto pr = f(now->key, prod_now);
      if (!check(pr)) {
        if constexpr (inclusive) {
          return now->r ? _min_index(now->r, failed) : prev;
        } else {
          return now->index;
        }
      }
      prod_now = pr;
      if (now->l == nullptr) {
        if constexpr (inclusive) {
          return now->index;
        } else {
          return failed;
        }
      }
      push(now->l);
      if constexpr (inclusive) prev = now->index;
      now = now->l;
    }
  }

  void inner_dump(Ptr t) {
    push(t);
    if (t->l) inner_dump(t->l);
    cerr << "## i = " << t->index << ", ";
    cerr << "\tkey = " << t->key << ", ";
    cerr << "\tsum = " << t->sum << ", ";
    cerr << "\tchild = ";
    cerr << "( " << (t->l ? to_string(t->l->index) : "nil");
    cerr << ", ";
    cerr << (t->r ? to_string(t->r->index) : "nil");
    cerr << " )" << endl;
    if (t->r) inner_dump(t->r);
  }

 public:
  Ptr root;

  RBSTLazySegmentTree() : root(nullptr) {}
  RBSTLazySegmentTree(const vector<T> xs, const vector<I> &is = {}) {
    if (!is.empty()) assert(xs.size() == is.size());
    int n = xs.size();
    vector<pair<I, T>> dat(n);
    for (int i = 0; i < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};
    root = build(0, n, dat);
  }

  // 1  
  void set_val(I i, T x) {
    auto s = split_by_index(root, i);
    if (s[1] == nullptr) {
      s[1] = my_new(i, x);
    } else {
      s[1]->key = x;
    }
    root = merge(merge(s[0], update(s[1])), s[2]);
  }

  // 1 
  T get_val(I i) {
    auto s = split_by_index(root, i);
    T res = s[1] ? s[1]->key : ti();
    root = merge(merge(s[0], s[1]), s[2]);
    return res;
  }

  // 
  void erase(I i) {
    auto s = split_by_index(root, i);
    if (s[1]) my_del(s[1]);
    root = merge(s[0], s[2]);
  }

  // 
  void apply(I l, I r, const E &e) {
    auto [x, aux] = split_left(root, l);
    auto [y, z] = split_left(aux, r);
    propagate(y, e);
    root = merge(merge(x, y), z);
  }

  // 
  T fold(I l, I r) {
    auto [x, aux] = split_left(root, l);
    auto [y, z] = split_left(aux, r);
    T res = y ? y->sum : ti();
    root = merge(merge(x, y), z);
    return res;
  }

  // n  i [i, n)  fold  true  i 
  // ( failed )
  template <typename C>
  I min_left(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _min_left<C, true>(x, check, failed);
    root = merge(x, y);
    return res;
  }

  // n  i (i, n)  fold  true  i 
  // ( (, n)   minus_infty )
  template <typename C>
  I min_left_exclusive(I n, C check, I minus_infty) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _min_left<C, false>(x, check, minus_infty);
    root = merge(x, y);
    return res;
  }

  // n  i [n, i)  fold  true  i 
  // ( [n, ]  true  infty )
  template <typename C>
  I max_right(I n, C check, I infty) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _max_right<C, true>(y, check, infty);
    root = merge(x, y);
    return res;
  }

  // n  i [n, i]  fold  true  i 
  // ( failed )
  template <typename C>
  I max_right_inclusive(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _max_right<C, false>(y, check, failed);
    root = merge(x, y);
    return res;
  }

  void dump() { inner_dump(root); }
};

namespace RBSTSegmentTreeImpl {

template <typename T>
T g(T l, bool) {
  return l;
}
bool h(bool, bool) { return false; }
bool ei() { return false; }

template <typename I, typename T, T (*f)(T, T), T (*ti)()>
using RBSTSegmentTree = RBSTLazySegmentTree<I, T, bool, f, g, h, ti, ei>;
}  // namespace RBSTSegmentTreeImpl

using RBSTSegmentTreeImpl::RBSTSegmentTree;

/**
 * @brief RBST-based Dynamic Lazy Segment Tree
 */


template <typename T, typename F>
struct SegmentTree {
  int N;
  int size;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree(F _f, const T &I_) : N(0), size(0), f(_f), I(I_) {}

  SegmentTree(int _N, F _f, const T &I_) : f(_f), I(I_) { init(_N); }

  SegmentTree(const vector<T> &v, F _f, T I_) : f(_f), I(I_) {
    init(v.size());
    for (int i = 0; i < (int)v.size(); i++) {
      seg[i + size] = v[i];
    }
    build();
  }

  void init(int _N) {
    N = _N;
    size = 1;
    while (size < N) size <<= 1;
    seg.assign(2 * size, I);
  }

  void set(int k, T x) { seg[k + size] = x; }

  void build() {
    for (int k = size - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void update(int k, T x) {
    k += size;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void add(int k, T x) {
    k += size;
    seg[k] += x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k], seg[2 * k + 1]);
    }
  }

  // query to [a, b)
  T query(int a, int b) {
    T L = I, R = I;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  T &operator[](const int &k) { return seg[k + size]; }

  // check(a[l] * ...  * a[r-1])  true  r
  // ( true  N )
  template <class C>
  int max_right(int l, C check) {
    assert(0 <= l && l <= N);
    assert(check(I) == true);
    if (l == N) return N;
    l += size;
    T sm = I;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(f(sm, seg[l]))) {
        while (l < size) {
          l = (2 * l);
          if (check(f(sm, seg[l]))) {
            sm = f(sm, seg[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = f(sm, seg[l]);
      l++;
    } while ((l & -l) != l);
    return N;
  }

  // check(a[l] * ... * a[r-1])  true  l
  // ( true  0 )
  template <typename C>
  int min_left(int r, C check) {
    assert(0 <= r && r <= N);
    assert(check(I) == true);
    if (r == 0) return 0;
    r += size;
    T sm = I;
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(f(seg[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (check(f(seg[r], sm))) {
            sm = f(seg[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = f(seg[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};


template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}
  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnweightedGraph = vector<vector<int>>;

// Input of (Unweighted) Graph
UnweightedGraph graph(int N, int M = -1, bool is_directed = false,
                      bool is_1origin = true) {
  UnweightedGraph g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    if (is_1origin) x--, y--;
    g[x].push_back(y);
    if (!is_directed) g[y].push_back(x);
  }
  return g;
}

// Input of Weighted Graph
template <typename T>
WeightedGraph<T> wgraph(int N, int M = -1, bool is_directed = false,
                        bool is_1origin = true) {
  WeightedGraph<T> g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    cin >> c;
    if (is_1origin) x--, y--;
    g[x].emplace_back(x, y, c);
    if (!is_directed) g[y].emplace_back(y, x, c);
  }
  return g;
}

// Input of Edges
template <typename T>
Edges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {
  Edges<T> es;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    es.emplace_back(x, y, c);
  }
  return es;
}

// Input of Adjacency Matrix
template <typename T>
vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,
                           bool is_directed = false, bool is_1origin = true) {
  vector<vector<T>> d(N, vector<T>(N, INF));
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    d[x][y] = c;
    if (!is_directed) d[y][x] = c;
  }
  return d;
}

/**
 * @brief 
 * @docs docs/graph/graph-template.md
 */

template <typename G>
struct HeavyLightDecomposition {
 private:
  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    down[cur] = id++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    up[cur] = id;
  }

  // [u, v)
  vector<pair<int, int>> ascend(int u, int v) const {
    vector<pair<int, int>> res;
    while (nxt[u] != nxt[v]) {
      res.emplace_back(down[u], down[nxt[u]]);
      u = par[nxt[u]];
    }
    if (u != v) res.emplace_back(down[u], down[v] + 1);
    return res;
  }

  // (u, v]
  vector<pair<int, int>> descend(int u, int v) const {
    if (u == v) return {};
    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
    auto res = descend(u, par[nxt[v]]);
    res.emplace_back(down[nxt[v]], down[v]);
    return res;
  }

 public:
  G& g;
  int id;
  vector<int> size, depth, down, up, nxt, par;
  HeavyLightDecomposition(G& _g, int root = 0)
      : g(_g),
        id(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        down(g.size(), -1),
        up(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void build(int root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }

  template <typename F>
  void path_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) {
      int s = a + 1, t = b;
      s > t ? f(t, s) : f(s, t);
    }
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) {
      int s = a, t = b + 1;
      s > t ? f(t, s) : f(s, t);
    }
  }

  template <typename F>
  void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
  }

  template <typename F>
  void subtree_query(int u, bool vertex, const F& f) {
    f(down[u] + int(!vertex), up[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (down[a] < down[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }

  int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};

/**
 * @brief Heavy Light Decomposition()
 * @docs docs/tree/heavy-light-decomposition.md
 */

using namespace Nyaan;

int f(int a, int b) { return a + b; };
int ti() { return 0; }
using rbst = RBSTSegmentTree<pl, int, f, ti>;

// [0, N) 
// 
// AB[0] 
vvi hougan(vp& AB, int N) {
  ll M = sz(AB);
  // 
  AB.emplace_back(-1, N + 1);
  // 
  sort(begin(AB), end(AB), [](auto l, auto r) {
    return l.first == r.first ? l.second > r.second : l.first < r.first;
  });
  // 
  vector<vector<int>> g(M + 1);
  vector<int> par(M * 2 + 1, -1);
  for (int i = 1; i <= M; i++) {
    auto [a, b] = AB[i];
    int p = i - 1;
    while (p <= M) {
      trc(i, p);
      auto [v, pb] = AB[p];
      assert(v <= a);
      if (b <= pb) break;
      assert(!(a < pb && pb < b));
      p = par[p];
    }
    g[p].push_back(i);
    par[i] = p;
  }
  return g;
}

void Nyaan::solve() {
  inl(N, Q);
  ins(S);
  vp v;
  {
    vi st;
    rep(i, N) {
      if (S[i] == ')') {
        if (sz(st)) {
          int j = st.back();
          st.pop_back();
          v.emplace_back(j, i + 1);
        }
      } else {
        st.emplace_back(i);
      }
    }
  }
  auto g = hougan(v, N);
  vl init(N);
  vi parent(sz(v));
  V<rbst> segcnt(sz(v));

  rep(i, sz(g)) {
    if (i) {
      ll score = 1LL * sz(g[i]) * (sz(g[i]) + 1) / 2;
      int u = v[i].fi;
      init[u] += score;
    }
    each(j, g[i]) {
      parent[j] = i;
      segcnt[i].set_val(v[j], 1);
    }
  }
  SegmentTree seg(
      init, [](ll s, ll b) { return s + b; }, 0LL);

  trc(v);

  while (Q--) {
    inl(cmd, L, R);
    --L;
    // [L, R) 
    auto cmp = [](pl l, pl r) {
      return l.first == r.first ? l.second > r.second : l.first < r.first;
    };

    int i;
    {
      int ng = 0, ok = sz(v);
      while (ng + 1 < ok) {
        int med = (ok + ng) / 2;
        bool f = cmp(v[med], {L, R});
        (f ? ng : ok) = med;
      }
      i = ok;
    }
    trc(L, R);
    i = parent[i];
    trc(i);

    if (cmd == 2) {
      ll ans = seg.query(L, R);
      if (v[i].fi == L) {
        ll x = segcnt[i].fold({-inf, -inf}, {inf, inf});
        ans -= x * (x + 1) / 2;
      }
      ll x = segcnt[i].fold(pl{L, -inf}, pl{R, -inf});
      ans += x * (x + 1) / 2;
      out(ans);
    }

    if (cmd == 1) {
      // 
      if (i) {
        ll x = segcnt[i].fold({-inf, -inf}, {inf, inf});
        ll le = v[i].fi;
        ll segle = seg[le];
        segle -= x * (x + 1) / 2;
        seg.update(le, segle);
        trc(x);
      }
      segcnt[i].set_val(pl{L, R}, 0);
      if (i) {
        ll x = segcnt[i].fold({-inf, -inf}, {inf, inf});
        ll le = v[i].fi;
        ll segle = seg[le];
        segle += x * (x + 1) / 2;
        seg.update(le, segle);
        trc(x);
      }
    }
  }
}