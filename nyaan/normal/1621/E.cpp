/**
 *  date : 2022-01-04 00:23:13
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

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ti)(), E (*ei)()>
struct LazySegmentTree {
  int n, log;
  vector<T> val;
  vector<E> laz;

  explicit LazySegmentTree() {}
  explicit LazySegmentTree(const vector<T>& vc) { init(vc); }

  void init(const vector<T>& vc) {
    n = 1, log = 0;
    while (n < (int)vc.size()) n <<= 1, log++;
    val.resize(2 * n, ti());
    laz.resize(n, ei());
    for (int i = 0; i < (int)vc.size(); ++i) val[i + n] = vc[i];
    for (int i = n - 1; i; --i) _update(i);
  }

  void update(int l, int r, const E& x) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) _apply(l++, x);
        if (r & 1) _apply(--r, x);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) _update(l >> i);
      if (((r >> i) << i) != r) _update((r - 1) >> i);
    }
  }

  T query(int l, int r) {
    if (l == r) return ti();
    l += n, r += n;
    T L = ti(), R = ti();
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    while (l < r) {
      if (l & 1) L = f(L, val[l++]);
      if (r & 1) R = f(val[--r], R);
      l >>= 1;
      r >>= 1;
    }
    return f(L, R);
  }

  void set_val(int k, const T& x) {
    k += n;
    for (int i = log; i >= 1; i--) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _push(k >> i);
    }
    val[k] = x;
    for (int i = 1; i <= log; i++) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _update(k >> i);
    }
  }

  void update_val(int k, const E& x) {
    k += n;
    for (int i = log; i >= 1; i--) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _push(k >> i);
    }
    val[k] = g(val[k], x);
    for (int i = 1; i <= log; i++) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _update(k >> i);
    }
  }

  T get_val(int k) {
    k += n;
    for (int i = log; i >= 1; i--) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _push(k >> i);
    }
    return val[k];
  }

 private:
  void _push(int i) {
    if (laz[i] != ei()) {
      val[2 * i + 0] = g(val[2 * i + 0], laz[i]);
      val[2 * i + 1] = g(val[2 * i + 1], laz[i]);
      if (2 * i < n) {
        compose(laz[2 * i + 0], laz[i]);
        compose(laz[2 * i + 1], laz[i]);
      }
      laz[i] = ei();
    }
  }
  inline void _update(int i) { val[i] = f(val[2 * i + 0], val[2 * i + 1]); }
  inline void _apply(int i, const E& x) {
    if (x != ei()) {
      val[i] = g(val[i], x);
      if (i < n) compose(laz[i], x);
    }
  }
  inline void compose(E& a, const E& b) { a = a == ei() ? b : h(a, b); }
};

namespace SegmentTreeUtil {

template <typename T>
struct Pair {
  T first, second;
  Pair() = default;
  Pair(const T& f, const T& s) : first(f), second(s) {}
  operator T() const { return first; }
  friend ostream& operator<<(ostream& os, const Pair<T>& p) {
    os << T(p.first);
    return os;
  }
};

template <typename T>
T Mx(T a, T b) {
  return max(a, b);
}
template <typename T>
T Mn(T a, T b) {
  return min(a, b);
}
template <typename T>
T Update(T, T b) {
  return b;
}
template <typename T>
T Add(T a, T b) {
  return a + b;
}
template <typename T>
Pair<T> Psum(Pair<T> a, Pair<T> b) {
  return Pair<T>(a.first + b.first, a.second + b.second);
}
template <typename T>
Pair<T> Padd(Pair<T> a, T b) {
  return Pair<T>(a.first + a.second * b, a.second);
}
template <typename T>
Pair<T> PUpdate(Pair<T> a, T b) {
  return Pair<T>(a.second * b, a.second);
}
template <typename T>
Pair<T> Pid() {
  return Pair<T>(0, 0);
}
template <typename T>
T Zero() {
  return T(0);
}
template <typename T, T val>
T Const() {
  return val;
}

template <typename T, T MINF>
struct AddMax_LazySegmentTree
    : LazySegmentTree<T, T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>> {
  using base =
      LazySegmentTree<T, T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;
  AddMax_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T, T INF>
struct AddMin_LazySegmentTree
    : LazySegmentTree<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {
  using base =
      LazySegmentTree<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>>;
  AddMin_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T>
struct AddSum_LazySegmentTree
    : LazySegmentTree<Pair<T>, T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>> {
  using base =
      LazySegmentTree<Pair<T>, T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>;
  AddSum_LazySegmentTree(const vector<T>& v) {
    vector<Pair<T>> w(v.size());
    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i], 1);
    base::init(w);
  }
};

template <typename T, T MINF>
struct UpdateMax_LazySegmentTree
    : LazySegmentTree<T, T, Mx<T>, Update<T>, Update<T>, Const<T, MINF>,
                      Const<T, MINF>> {
  using base = LazySegmentTree<T, T, Mx<T>, Update<T>, Update<T>,
                               Const<T, MINF>, Const<T, MINF>>;
  UpdateMax_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T, T INF>
struct UpdateMin_LazySegmentTree
    : LazySegmentTree<T, T, Mn<T>, Update<T>, Update<T>, Const<T, INF>,
                      Const<T, INF>> {
  using base = LazySegmentTree<T, T, Mn<T>, Update<T>, Update<T>,
                               Const<T, INF>, Const<T, INF>>;
  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T, T UNUSED_VALUE>
struct UpdateSum_LazySegmentTree
    : LazySegmentTree<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>, Pid<T>,
                      Const<T, UNUSED_VALUE>> {
  using base = LazySegmentTree<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>,
                               Pid<T>, Const<T, UNUSED_VALUE>>;
  UpdateSum_LazySegmentTree(const vector<T>& v) {
    vector<Pair<T>> w(v.size());
    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i], 1);
    base::init(w);
  }
};

}  // namespace SegmentTreeUtil
using SegmentTreeUtil::AddMax_LazySegmentTree;
using SegmentTreeUtil::AddMin_LazySegmentTree;
using SegmentTreeUtil::AddSum_LazySegmentTree;
using SegmentTreeUtil::UpdateMax_LazySegmentTree;
using SegmentTreeUtil::UpdateMin_LazySegmentTree;
using SegmentTreeUtil::UpdateSum_LazySegmentTree;

/**
 * @brief 
 * @docs docs/segment-tree/lazy-segment-tree-utility.md
 */

using namespace Nyaan;

void q() {
  inl(N, M);
  vl A(N);
  in(A);

  vvl B(M);
  rep(i, M) {
    ini(x);
    vl v(x);
    in(v);
    B[i] = v;
  }

  sort(all(A));
  A.erase(begin(A), begin(A) + N - M);
  N = M;

  vi init(M);
  rep(i, M) init[i] = -i - 1;
  AddMin_LazySegmentTree<int, inf> seg(init);

  auto lwb = [&](ll k, ll s) {
    ll ng = -1, ok = M;
    while (ng + 1 < ok) {
      ll me = (ng + ok) / 2;
      (A[me] * k >= s ? ok : ng) = me;
    }
    return ok;
  };

  rep(i, M) {
    ll s = Sum(B[i]);
    ll k = sz(B[i]);
    int l = lwb(k, s);
    // [l, M) OK
    seg.update(l, M, 1);
  }

  string ans;
  rep(i, M) {
    ll k = sz(B[i]);
    ll s = Sum(B[i]);
    int l = lwb(k, s);
    seg.update(l, M, -1);
    rep(j, k) {
      ll nk = k - 1;
      ll ns = s - B[i][j];
      int nl = lwb(nk, ns);
      seg.update(nl, M, 1);
      ll mn = seg.query(0, M);
      ans.push_back('0' + (mn >= 0));
      seg.update(nl, M, -1);
    }
    seg.update(l, M, 1);
  }

  out(ans);
}

void Nyaan::solve() {
  ini(T);
  while (T--) q();
}