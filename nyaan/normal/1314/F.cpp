/**
 *  date : 2021-12-23 14:03:45
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

void dump(const bool& t) { cerr << (t ? "true" : "false"); }

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


// input  : a, M (0 < a < M)
// output : pair(g, x) s.t. g = gcd(a, M), xa = g (mod M), 0 <= x < b/g
template <typename uint>
pair<uint, uint> gcd_inv(uint a, uint M) {
  assert(M != 0 && 0 < a);
  a %= M;
  uint b = M, s = 1, t = 0;
  while (true) {
    if (a == 0) return {b, t + M};
    t -= b / a * s;
    b %= a;
    if (b == 0) return {a, s};
    s -= a / b * t;
    a %= b;
  }
}

//  : 0 <= rem[i] < mod[i], 1 <= mod[i]
//    : return {rem, mod}
//  : return {0, 0}
template <typename T, typename U>
pair<unsigned long long, unsigned long long> garner(const vector<T>& rem,
                                                    const vector<U>& mod) {
  assert(rem.size() == mod.size());
  using u64 = unsigned long long;
  u64 r0 = 0, m0 = 1;
  for (int i = 0; i < (int)rem.size(); i++) {
    assert(1 <= mod[i]);
    assert(0 <= rem[i] && rem[i] < mod[i]);
    u64 m1 = mod[i], r1 = rem[i] % m1;
    if (m0 < m1) swap(r0, r1), swap(m0, m1);
    if (m0 % m1 == 0) {
      if (r0 % m1 != r1) return {0, 0};
      continue;
    }
    u64 g, im;
    tie(g, im) = gcd_inv(m0, m1);
    u64 y = r0 < r1 ? r1 - r0 : r0 - r1;
    if (y % g != 0) return {0, 0};
    u64 u1 = m1 / g;
    y = y / g % u1;
    if (r0 > r1 && y != 0) y = u1 - y;
    u64 x = y * im % u1;
    r0 += x * m0;
    m0 *= u1;
  }
  return {r0, m0};
}

/**
 * @brief Garner's algorithm
 */

namespace NimberImpl {
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

struct calc8 {
  u16 dp[1 << 8][1 << 8];
  constexpr calc8() : dp() {
    dp[0][0] = dp[0][1] = dp[1][0] = 0;
    dp[1][1] = 1;
    for (int e = 1; e <= 3; e++) {
      int p = 1 << e, q = p >> 1;
      u16 ep = 1u << p, eq = 1u << q;
      for (u16 i = 0; i < ep; i++) {
        for (u16 j = i; j < ep; j++) {
          if (i < eq && j < eq) continue;
          if (min(i, j) <= 1u) {
            dp[i][j] = dp[j][i] = i * j;
            continue;
          }
          u16 iu = i >> q, il = i & (eq - 1);
          u16 ju = j >> q, jl = j & (eq - 1);
          u16 u = dp[iu][ju], l = dp[il][jl];
          u16 ul = dp[iu ^ il][ju ^ jl];
          u16 uq = dp[u][eq >> 1];
          dp[i][j] = ((ul ^ l) << q) ^ uq ^ l;
          dp[j][i] = dp[i][j];
        }
      }
    }
  }
} constexpr c8;

struct calc16 {
 private:
  static constexpr u16 proot = 10279;
  static constexpr u32 ppoly = 92191;
  static constexpr int order = 65535;

  u16 base[16], exp[(1 << 18) + 100];
  int log[1 << 16];

  constexpr u16 d(u32 x) { return (x << 1) ^ (x < 32768u ? 0 : ppoly); }

  constexpr u16 naive(u16 i, u16 j) {
    if (min(i, j) <= 1u) return i * j;
    u16 q = 8, eq = 1u << 8;
    u16 iu = i >> q, il = i & (eq - 1);
    u16 ju = j >> q, jl = j & (eq - 1);
    u16 u = c8.dp[iu][ju];
    u16 l = c8.dp[il][jl];
    u16 ul = c8.dp[iu ^ il][ju ^ jl];
    u16 uq = c8.dp[u][eq >> 1];
    return ((ul ^ l) << q) ^ uq ^ l;
  }

 public:
  constexpr calc16() : base(), exp(), log() {
    base[0] = 1;
    for (int i = 1; i < 16; i++) base[i] = naive(base[i - 1], proot);
    exp[0] = 1;
    for (int i = 1; i < order; i++) exp[i] = d(exp[i - 1]);
    u16* pre = exp + order + 1;
    pre[0] = 0;
    for (int b = 0; b < 16; b++) {
      int is = 1 << b, ie = is << 1;
      for (int i = is; i < ie; i++) pre[i] = pre[i - is] ^ base[b];
    }
    for (int i = 0; i < order; i++) exp[i] = pre[exp[i]], log[exp[i]] = i;

    int ie = 2 * order + 30;
    for (int i = order; i < ie; i++) exp[i] = exp[i - order];
    for (unsigned int i = ie; i < sizeof(exp) / sizeof(u16); i++) exp[i] = 0;
    log[0] = ie + 1;
  }

  constexpr u16 prod(u16 i, u16 j) const { return exp[log[i] + log[j]]; }

  // exp[3] = 2^{15} = 32768
  constexpr u16 Hprod(u16 i, u16 j) const { return exp[log[i] + log[j] + 3]; }
  constexpr u16 H(u16 i) const { return exp[log[i] + 3]; }
  constexpr u16 H2(u16 i) const { return exp[log[i] + 6]; }
} constexpr c16;

constexpr u32 product32(u32 i, u32 j) {
  u16 iu = i >> 16, il = i & 65535;
  u16 ju = j >> 16, jl = j & 65535;
  u16 l = c16.prod(il, jl);
  u16 ul = c16.prod(iu ^ il, ju ^ jl);
  u16 uq = c16.Hprod(iu, ju);
  return (u32(ul ^ l) << 16) ^ uq ^ l;
}

// (+ : xor, x : nim product, * : integer product)
// i x j
// = (iu x ju + il x ju + iu x ji) * 2^{16}
// + (iu x ju x 2^{15}) + il x jl
//
// assign ju = 2^{15}, jl = 0s
// -> i x j
// = ((iu + il) x 2^{15}) * 2^{16} + (iu x 2^{15} x 2^{15})
constexpr u32 H(u32 i) {
  u16 iu = i >> 16;
  u16 il = i & 65535;
  return (u32(c16.H(iu ^ il)) << 16) ^ c16.H2(iu);
}

constexpr u64 product64(u64 i, u64 j) {
  u32 iu = i >> 32, il = i & u32(-1);
  u32 ju = j >> 32, jl = j & u32(-1);
  u32 l = product32(il, jl);
  u32 ul = product32(iu ^ il, ju ^ jl);
  u32 uq = H(product32(iu, ju));
  return (u64(ul ^ l) << 32) ^ uq ^ l;
}
}  // namespace NimberImpl

template <typename uint, uint (*prod)(uint, uint)>
struct NimberBase {
  using N = NimberBase;
  uint x;
  NimberBase() : x(0) {}
  NimberBase(uint _x) : x(_x) {}
  static N id0() { return {}; }
  static N id1() { return {1}; }

  N& operator+=(const N& p) {
    x ^= p.x;
    return *this;
  }
  N& operator-=(const N& p) {
    x ^= p.x;
    return *this;
  }
  N& operator*=(const N& p) {
    x = prod(x, p.x);
    return *this;
  }
  N operator+(const N& p) const { return x ^ p.x; }
  N operator-(const N& p) const { return x ^ p.x; }
  N operator*(const N& p) const { return prod(x, p.x); }
  bool operator==(const N& p) const { return x == p.x; }
  bool operator!=(const N& p) const { return x != p.x; }
  N pow(uint64_t n) const {
    N a = *this, r = 1;
    for (; n; a *= a, n >>= 1)
      if (n & 1) r *= a;
    return r;
  }
  friend ostream& operator<<(ostream& os, const N& p) { return os << p.x; }

  uint discrete_logarithm(N y) {
    assert(x != 0 && y != 0);
    vector<uint> rem, mod;
    for (uint p : {3, 5, 17, 257, 641, 65537, 6700417}) {
      if (uint(-1) % p) continue;
      uint q = uint(-1) / p;
      uint STEP = 1;
      while (4 * STEP * STEP < p) STEP *= 2;
      // a^m = z  1  m 
      auto inside = [&](N a, N z) -> uint {
        unordered_map<uint, int> mp;
        N big = 1, now = 1;  // x^m
        for (int i = 0; i < int(STEP); i++) {
          mp[z.x] = i, z *= a, big *= a;
        }
        for (int step = 0; step < int(p + 10); step += STEP) {
          now *= big;
          if (mp.find(now.x) != mp.end()) return (step + STEP) - mp[now.x];
        }
        return uint(-1);
      };
      N xq = (*this).pow(q), yq = y.pow(q);
      if (xq == 1 and yq == 1) continue;
      if (xq == 1 and yq != 1) return uint(-1);
      uint res = inside(xq, yq);
      if (res == uint(-1)) return uint(-1);
      rem.push_back(res % p);
      mod.push_back(p);
    }
    return garner(rem, mod).first;
  }
};

using Nimber32 = NimberBase<uint32_t, NimberImpl::product32>;
using Nimber64 = NimberBase<uint64_t, NimberImpl::product64>;

/**
 * @brief Nim Product
 * @docs docs/math/nimber.md
 */


void Nyaan::solve() {
  ini(T);
  while (T--) {
    u64 a, b;
    in(a, b);
    u64 ans = Nimber64(a).discrete_logarithm(b);
    if (ans == u64(-1)) {
      out(-1);
    } else {
      out(ans);
    }
  }
}