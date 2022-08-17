/**
 *  date : 2021-12-30 02:31:08
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
using namespace Nyaan;




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

template <typename T>
struct Binomial {
  vector<T> f, g, h;
  Binomial(int MAX = 0) : f(1, T(1)), g(1, T(1)), h(1, T(1)) {
    while (MAX >= (int)f.size()) extend();
  }

  void extend() {
    int n = f.size();
    int m = n * 2;
    f.resize(m);
    g.resize(m);
    h.resize(m);
    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);
    g[m - 1] = f[m - 1].inverse();
    h[m - 1] = g[m - 1] * f[m - 2];
    for (int i = m - 2; i >= n; i--) {
      g[i] = g[i + 1] * T(i + 1);
      h[i] = g[i] * f[i - 1];
    }
  }

  T fac(int i) {
    if (i < 0) return T(0);
    while (i >= (int)f.size()) extend();
    return f[i];
  }

  T finv(int i) {
    if (i < 0) return T(0);
    while (i >= (int)g.size()) extend();
    return g[i];
  }

  T inv(int i) {
    if (i < 0) return -inv(-i);
    while (i >= (int)h.size()) extend();
    return h[i];
  }

  T C(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r) * finv(r);
  }

  inline T operator()(int n, int r) { return C(n, r); }

  template <typename I>
  T multinomial(const vector<I>& r) {
    static_assert(is_integral<I>::value == true);
    int n = 0;
    for (auto& x : r) {
      if(x < 0) return T(0);
      n += x;
    }
    T res = fac(n);
    for (auto& x : r) res *= finv(x);
    return res;
  }

  template <typename I>
  T operator()(const vector<I>& r) {
    return multinomial(r);
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




__attribute__((target("sse4.2"))) inline __m128i my128_mullo_epu32(
    const __m128i &a, const __m128i &b) {
  return _mm_mullo_epi32(a, b);
}

__attribute__((target("sse4.2"))) inline __m128i my128_mulhi_epu32(
    const __m128i &a, const __m128i &b) {
  __m128i a13 = _mm_shuffle_epi32(a, 0xF5);
  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);
  __m128i prod02 = _mm_mul_epu32(a, b);
  __m128i prod13 = _mm_mul_epu32(a13, b13);
  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),
                                    _mm_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("sse4.2"))) inline __m128i montgomery_mul_128(
    const __m128i &a, const __m128i &b, const __m128i &r, const __m128i &m1) {
  return _mm_sub_epi32(
      _mm_add_epi32(my128_mulhi_epu32(a, b), m1),
      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a, b), r), m1));
}

__attribute__((target("sse4.2"))) inline __m128i montgomery_add_128(
    const __m128i &a, const __m128i &b, const __m128i &m2, const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("sse4.2"))) inline __m128i montgomery_sub_128(
    const __m128i &a, const __m128i &b, const __m128i &m2, const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(a, b);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("avx2"))) inline __m256i my256_mullo_epu32(
    const __m256i &a, const __m256i &b) {
  return _mm256_mullo_epi32(a, b);
}

__attribute__((target("avx2"))) inline __m256i my256_mulhi_epu32(
    const __m256i &a, const __m256i &b) {
  __m256i a13 = _mm256_shuffle_epi32(a, 0xF5);
  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);
  __m256i prod02 = _mm256_mul_epu32(a, b);
  __m256i prod13 = _mm256_mul_epu32(a13, b13);
  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13),
                                       _mm256_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("avx2"))) inline __m256i montgomery_mul_256(
    const __m256i &a, const __m256i &b, const __m256i &r, const __m256i &m1) {
  return _mm256_sub_epi32(
      _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),
      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a, b), r), m1));
}

__attribute__((target("avx2"))) inline __m256i montgomery_add_256(
    const __m256i &a, const __m256i &b, const __m256i &m2, const __m256i &m0) {
  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a, b), m2);
  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2),
                          ret);
}

__attribute__((target("avx2"))) inline __m256i montgomery_sub_256(
    const __m256i &a, const __m256i &b, const __m256i &m2, const __m256i &m0) {
  __m256i ret = _mm256_sub_epi32(a, b);
  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2),
                          ret);
}
namespace Gauss {
uint32_t a_buf_[4096][4096] __attribute__((aligned(64)));

// return value: (rank, (-1) ^ (number of swap time))
template <typename mint>
__attribute__((target("avx2"))) pair<int, mint> GaussianElimination(
    const vector<vector<mint>> &m, int LinearEquation = false) {
  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
  int H = m.size(), W = m[0].size(), rank = 0;
  mint det = 1;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) a[i][j].a = m[i][j].a;

  __m256i r = _mm256_set1_epi32(mint::r);
  __m256i m0 = _mm256_set1_epi32(0);
  __m256i m1 = _mm256_set1_epi32(mint::get_mod());
  __m256i m2 = _mm256_set1_epi32(mint::get_mod() << 1);

  for (int j = 0; j < (LinearEquation ? (W - 1) : W); j++) {
    // find basis
    if (rank == H) break;
    int idx = -1;
    for (int i = rank; i < H; i++) {
      if (a[i][j].get() != 0) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      det = 0;
      continue;
    }

    // swap
    if (rank != idx) {
      det = -det;
      for (int l = j; l < W; l++) swap(a[rank][l], a[idx][l]);
    }
    det *= a[rank][j];

    // normalize
    if (LinearEquation) {
      if (a[rank][j].get() != 1) {
        mint coeff = a[rank][j].inverse();
        __m256i COEFF = _mm256_set1_epi32(coeff.a);
        for (int i = j / 8 * 8; i < W; i += 8) {
          __m256i R = _mm256_load_si256((__m256i *)(a[rank] + i));
          __m256i RmulC = montgomery_mul_256(R, COEFF, r, m1);
          _mm256_store_si256((__m256i *)(a[rank] + i), RmulC);
        }
      }
    }

    // elimination
    for (int k = (LinearEquation ? 0 : rank + 1); k < H; k++) {
      if (k == rank) continue;
      if (a[k][j].get() != 0) {
        mint coeff = a[k][j] / a[rank][j];
        __m256i COEFF = _mm256_set1_epi32(coeff.a);
        for (int i = j / 8 * 8; i < W; i += 8) {
          __m256i R = _mm256_load_si256((__m256i *)(a[rank] + i));
          __m256i K = _mm256_load_si256((__m256i *)(a[k] + i));
          __m256i RmulC = montgomery_mul_256(R, COEFF, r, m1);
          __m256i KmnsR = montgomery_sub_256(K, RmulC, m2, m0);
          _mm256_store_si256((__m256i *)(a[k] + i), KmnsR);
        }
      }
    }
    rank++;
  }
  return {rank, det};
}

// calculate determinant
template <typename mint>
mint determinant(const vector<vector<mint>> &mat) {
  return GaussianElimination(mat).second;
}

// return V<V<mint>>
// 0 column ... one of solutions
// 1 ~ (W - rank) column ... bases
// if not exist, return empty vector
template <typename mint>
vector<vector<mint>> LinearEquation(vector<vector<mint>> A, vector<mint> B) {
  int H = A.size(), W = A[0].size();
  for (int i = 0; i < H; i++) A[i].push_back(B[i]);

  auto p = GaussianElimination(A, true);

  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
  int rank = p.first;

  // check if solutions exist
  for (int i = rank; i < H; ++i)
    if (a[i][W] != 0) return vector<vector<mint>>{};

  vector<vector<mint>> res(1, vector<mint>(W));
  vector<int> pivot(W, -1);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (a[i][j] == 0) ++j;
    res[0][j] = a[i][W], pivot[j] = i;
  }
  for (int j = 0; j < W; ++j) {
    if (pivot[j] == -1) {
      vector<mint> x(W);
      x[j] = 1;
      for (int k = 0; k < j; ++k)
        if (pivot[k] != -1) x[k] = -a[pivot[k]][j];
      res.push_back(x);
    }
  }
  return res;
}

}  // namespace Gauss

using Gauss::determinant;
using Gauss::LinearEquation;

//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<3>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

// https://hitonanode.github.io/cplib-cpp/other_algorithms/enumerate_triangles.hpp





// CUT begin
// Enumerate triangles
// Complexity: O(N + M \sqrt{M})
// Reference:
// - https://www.slideshare.net/catupper/trianguler
struct EnumerateTriangles {
  int V;
  std::vector<int> deg;
  std::vector<std::vector<int>> to;
  std::vector<std::pair<int, int>> edges;
  EnumerateTriangles(int N = 0) : V(N), deg(N), to(N) {}
  void add_edge(int s, int t) {
    assert(s >= 0 and s < V);
    assert(t >= 0 and t < V);
    assert(s != t);
    edges.emplace_back(s, t);
    deg[s]++, deg[t]++;
  }
  template <class F>
  void run(F f) {
    auto comp = [&](int i, int j) {
      return deg[i] != deg[j] ? deg[i] < deg[j] : i < j;
    };
    for (auto p : edges) {
      int s = p.first, t = p.second;
      if (comp(s, t)) {
        to[s].push_back(t);
      } else {
        to[t].push_back(s);
      }
    }
    std::vector<char> flag(V);
    for (int i = 0; i < V; i++) {
      for (auto j : to[i]) flag[j] = 1;
      for (auto j : to[i]) {
        for (auto k : to[j]) {
          if (flag[k]) f(i, j, k);
        }
      }
      for (auto j : to[i]) flag[j] = 0;
    }
  }
};

int add(int a, int b) {
  int c = a + b;
  return c >= 3 ? c - 3 : c;
}

void q() {
  inl(N, M);
  vl U(M), V(M);
  EnumerateTriangles g(N);

  vvi W(N, vi(N, -inf));
  vvi num(N, vi(N, -1));

  vvm A;
  vm B;

  rep(i, M) {
    ini(u, v, w);
    --u, --v;
    if (w >= 0) --w;
    U[i] = u, V[i] = v;
    g.add_edge(u, v);

    W[u][v] = W[v][u] = w;
    num[u][v] = num[v][u] = i;
  }

  int ok = 1;
  {
    auto f = [&](int i, int j, int k) {
      int flag = 0;
      int sm = 0;
      vm a(M);
      if (W[i][j] == -1) {
        flag = 1;
        a[num[i][j]] = 1;
      } else {
        sm += W[i][j];
      }
      if (W[k][j] == -1) {
        flag = 1;
        a[num[k][j]] = 1;
      } else {
        sm += W[k][j];
      }
      if (W[k][i] == -1) {
        flag = 1;
        a[num[k][i]] = 1;
      } else {
        sm += W[k][i];
      }

      sm = (3 - sm);
      sm %= 3;
      sm += 3;
      sm %= 3;

      if (flag == 0) {
        if (sm != 0) ok = 0;
      } else {
        A.push_back(a);
        B.push_back(sm);
      }
    };
    g.run(f);
  }

  if (!ok) die(-1);
  trc(A);
  trc(B);

  vm bns;

  if (A.empty()) {
    bns.resize(M);
  } else {
    auto sol = LinearEquation(A, B);
    if (sol.empty()) die(-1);
    bns = sol[0];
  }
  vi ans;
  rep(i, M) {
    int u = U[i], v = V[i];
    if (W[u][v] != -1)
      ans.push_back(W[u][v] + 1);
    else
      ans.push_back(bns[i].get() + 1);
  }
  die(ans);
}

void Nyaan::solve() {
  ini(T);
  rep(i, T) q();
}