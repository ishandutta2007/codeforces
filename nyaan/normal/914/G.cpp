/**
 *  date : 2021-03-07 19:09:26
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
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
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
template <typename T, size_t N>
void mem(T (&a)[N], int c) {
  memset(a, c, sizeof(T) * N);
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
vector<T> reord(const vector<T> &v, const vector<T> &ord) {
  int N = v.size();
  vector<T> ret(N);
  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];
  return ret;
};

template <typename T = int>
vector<T> mkiota(int N) {
  vector<T> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}

template <typename T>
vector<int> mkinv(vector<T> &v, int max_val = -1) {
  if (max_val < (int)v.size()) max_val = v.size() - 1;
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

__attribute__((target("bmi"))) inline int lsb(const u64 &a) {
  return _tzcnt_u64(a);
}
__attribute__((target("bmi"))) inline int ctz(const u64 &a) {
  return _tzcnt_u64(a);
}

__attribute__((target("lzcnt"))) inline int msb(const u64 &a) {
  return 63 - _lzcnt_u64(a);
}
__attribute__((target("lzcnt"))) inline int clz64(const u64 &a) {
  return _lzcnt_u64(a);
}

template <typename T>
inline int gbit(const T &a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void sbit(T &a, int i, bool b) {
  a ^= (gbit(a, i) == b ? 0 : (T(b) << i));
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

void in() {}
template <typename T, class... U>
void in(T &t, U &... u) {
  cin >> t;
  in(u...);
}

void out() { cout << "\n"; }
template <typename T, class... U, char sep = ' '>
void out(const T &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << sep;
  out(u...);
}

void outr() {}
template <typename T, class... U, char sep = ' '>
void outr(const T &t, const U &... u) {
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

template <typename U,
          enable_if_t<!is_specialize<U>::value, nullptr_t> = nullptr>
void dump(const U& t) {
  cerr << t;
}

template <typename T>
void dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr) {
  string res;
  if (t == Nyaan::inf) res = "inf";
  if (is_signed<T>::value)
    if (t == -Nyaan::inf) res = "-inf";
  if (sizeof(T) == 8) {
    if (t == Nyaan::infLL) res = "inf";
    if (is_signed<T>::value)
      if (t == -Nyaan::infLL) res = "-inf";
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
#define trc(...)
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
#define repc(i, a, cond) for (long long i = (a); (cond); i++)
#define enm(i, val, vec)                                  \
  for (long long i = 0; i < (long long)(vec).size(); i++) \
    if (auto& val = vec[i]; false)                        \
      ;                                                   \
    else

#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define inl(...)         \
  long long __VA_ARGS__; \
  in(__VA_ARGS__)
#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define inc(...)    \
  char __VA_ARGS__; \
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




template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 a;

  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  constexpr mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
  constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
  constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
  constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
  constexpr bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }

  constexpr mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  
  constexpr mint inverse() const { return pow(mod - 2); }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }
  
  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static constexpr u32 get_mod() { return mod; }
};
using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;

template <typename T>
struct Binomial {
  vector<T> fac_, finv_, inv_;
  Binomial(int MAX = 0) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {
    assert(T::get_mod() != 0);
    MAX += 9;
    fac_[0] = finv_[0] = inv_[0] = 1;
    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;
    finv_[MAX] = fac_[MAX].inverse();
    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);
    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];
  }

  void extend() {
    int n = fac_.size();
    T fac = fac_.back() * n;
    T inv = (-inv_[T::get_mod() % n]) * (T::get_mod() / n);
    T finv = finv_.back() * inv;
    fac_.push_back(fac);
    finv_.push_back(finv);
    inv_.push_back(inv);
  }

  T fac(int i) {
    if(i < 0) return T(0);
    while (i >= (int)fac_.size()) extend();
    return fac_[i];
  }

  T finv(int i) {
    if(i < 0) return T(0);
    while (i >= (int)finv_.size()) extend();
    return finv_[i];
  }

  T inv(int i) {
    if(i < 0) return T(0);
    while (i >= (int)inv_.size()) extend();
    return inv_[i];
  }

  T C(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r) * finv(r);
  }

  T C_naive(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    T ret = T(1);
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
    return ret;
  }

  T P(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r);
  }

  T H(int n, int r) {
    if (n < 0 || r < 0) return T(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

Binomial<mint> C;



template <typename T>
void superset_zeta_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j] += f[j | i];
      }
    }
  }
}

template <typename T>
void superset_mobius_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j] -= f[j | i];
      }
    }
  }
}

template <typename T>
void subset_zeta_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j | i] += f[j];
      }
    }
  }
}

template <typename T>
void subset_mobius_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j | i] -= f[j];
      }
    }
  }
}

/**
 * @brief Zeta Transform / Moebius Transform
 */

template <typename T>
vector<T> and_convolution(vector<T> a, vector<T> b) {
  superset_zeta_transform(a);
  superset_zeta_transform(b);
  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
  superset_mobius_transform(a);
  return a;
}

/**
 * @brief AND Convoluion
 */


template <typename mint, int _s>
struct SubsetConvolution {
  using fps = array<mint, _s + 1>;
  static constexpr int s = _s;
  vector<int> pc;

  SubsetConvolution() : pc(1 << s) {
    for (int i = 1; i < (1 << s); i++) pc[i] = pc[i - (i & -i)] + 1;
  }

  void add(fps& l, const fps& r, int d) {
    for (int i = 0; i < d; ++i) l[i] += r[i];
  }

  void sub(fps& l, const fps& r, int d) {
    for (int i = d; i <= s; ++i) l[i] -= r[i];
  }

  void zeta(vector<fps>& a) {
    int n = a.size();
    for (int w = 1; w < n; w *= 2) {
      for (int k = 0; k < n; k += w * 2) {
        for (int i = 0; i < w; ++i) {
          add(a[k + w + i], a[k + i], pc[k + w + i]);
        }
      }
    }
  }

  void mobius(vector<fps>& a) {
    int n = a.size();
    for (int w = n >> 1; w; w >>= 1) {
      for (int k = 0; k < n; k += w * 2) {
        for (int i = 0; i < w; ++i) {
          sub(a[k + w + i], a[k + i], pc[k + w + i]);
        }
      }
    }
  }

  vector<fps> lift(const vector<mint>& a) {
    vector<fps> A(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
      fill(begin(A[i]), end(A[i]), mint());
      A[i][pc[i]] = a[i];
    }
    return A;
  }

  vector<mint> unlift(const vector<fps>& A) {
    vector<mint> a(A.size());
    for (int i = 0; i < (int)A.size(); i++) a[i] = A[i][pc[i]];
    return a;
  }

  void prod(vector<fps>& A, const vector<fps>& B) {
    int n = A.size(), d = __builtin_ctz(n);
    for (int i = 0; i < n; i++) {
      fps c{};
      for (int j = 0; j <= d; j++) {
        for (int k = 0; k <= d - j; k++) {
          c[j + k] += A[i][j] * B[i][k];
        }
      }
      A[i].swap(c);
    }
  }

  vector<mint> multiply(const vector<mint>& a, const vector<mint>& b) {
    vector<fps> A = lift(a), B = lift(b);
    zeta(A), zeta(B);
    prod(A, B);
    mobius(A);
    return unlift(A);
  }
};

/**
 * @brief Subset Convolution
 * @docs docs/set-function/subset-convolution.md
 */



template <typename T>
void walsh_hadamard_transform(vector<T>& f, bool inverse = false) {
  int n = f.size();
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j], y = f[j | i];
        f[j] = x + y, f[j | i] = x - y;
      }
    }
  }
  if (inverse) {
    if constexpr (is_integral<T>::value) {
      for (auto& x : f) x /= n;
    } else {
      T invn = T(1) / T(f.size());
      for (auto& x : f) x *= invn;
    }
  }
}

/**
 * @brief Walsh Hadamard Transform
 */

template <typename T>
vector<T> xor_convolution(vector<T> a, vector<T> b) {
  walsh_hadamard_transform(a);
  walsh_hadamard_transform(b);
  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
  walsh_hadamard_transform(a, true);
  return a;
}

/**
 * @brief XOR Convoluion
 */


using namespace Nyaan;

void Nyaan::solve() {
  ini(N);
  vi s(N);
  in(s);

  vm f(2 * TEN(5) + 100);
  f[0] = 0, f[1] = 1;
  reg(i, 2, 2 * TEN(5)) f[i] = f[i - 1] + f[i - 2];

  int M = 1 << 17;
  vm cnt(M);
  each(x, s) cnt[x] += 1;

  SubsetConvolution<mint, 17> sc;

  auto f1 = sc.multiply(cnt, cnt);
  auto f2 = cnt;
  auto f3 = xor_convolution(cnt, cnt);

  rep(i, M) f1[i] *= f[i], f2[i] *= f[i], f3[i] *= f[i];

  auto g = and_convolution(f1, f2);
  g = and_convolution(g, f3);

  mint ans=0;
  rep(i,17)ans+=g[1<<i];
  out(ans);
}