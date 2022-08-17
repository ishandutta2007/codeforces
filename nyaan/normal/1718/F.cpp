/**
 *  date : 2022-08-17 10:10:06
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
  template <typename S>
  P &operator*=(const S &r) {
    first *= r, second *= r;
    return *this;
  }
  P operator+(const P &r) const { return P(*this) += r; }
  P operator-(const P &r) const { return P(*this) -= r; }
  P operator*(const P &r) const { return P(*this) *= r; }
  template <typename S>
  P operator*(const S &r) const {
    return P(*this) *= r;
  }
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
vector<int> mkord(int N,F f) {
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

vector<int> mkiota(int n) {
  vector<int> ret(n);
  iota(begin(ret), end(ret), 0);
  return ret;
}

template <typename T>
T mkrev(const T &v) {
  T w{v};
  reverse(begin(w), end(w));
  return w;
}

template <typename T>
bool nxp(vector<T> &v) {
  return next_permutation(begin(v), end(v));
}

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

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

istream &operator>>(istream &is, __int128_t &x) {
  string S;
  is >> S;
  x = 0;
  int flag = 0;
  for (auto &c : S) {
    if (c == '-') {
      flag = true;
      continue;
    }
    x *= 10;
    x += c - '0';
  }
  if (flag) x = -x;
  return is;
}

istream &operator>>(istream &is, __uint128_t &x) {
  string S;
  is >> S;
  x = 0;
  for (auto &c : S) {
    x *= 10;
    x += c - '0';
  }
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

#ifdef NyaanDebug
#define trc(...) (void(0))
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

struct Mo {
  int width;
  vector<int> left, right, order;

  Mo(int N, int Q) : order(Q) {
    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
    iota(begin(order), end(order), 0);
  }

  void insert(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  template <typename AL, typename AR, typename DL, typename DR, typename REM>
  void run(const AL &add_left, const AR &add_right, const DL &delete_left,
           const DR &delete_right, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if (ablock != bblock) return ablock < bblock;
      if (ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    for (auto idx : order) {
      while (nl > left[idx]) add_left(--nl);
      while (nr < right[idx]) add_right(nr++);
      while (nl < left[idx]) delete_left(nl++);
      while (nr > right[idx]) delete_right(--nr);
      rem(idx);
    }
  }
};

/**
 * @brief Mo's algorithm
 * @docs docs/misc/mo.md
 */



struct Timer {
  chrono::high_resolution_clock::time_point st;

  Timer() { reset(); }

  void reset() { st = chrono::high_resolution_clock::now(); }

  chrono::milliseconds::rep elapsed() {
    auto ed = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();
  }
};


vector<int> factor_enumerate(int N) {
  vector<int> lp(N + 1, 0);
  if (N < 2) return lp;
  vector<int> pr{2, 3};
  for (int i = 2; i <= N; i += 2) lp[i] = 2;
  for (int i = 3; i <= N; i += 6) lp[i] = 3;
  for (int i = 5, d = 4; i <= N; i += d = 6 - d) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 2; j < (int)pr.size() && i * pr[j] <= N; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) break;
    }
  }
  return lp;
}
template <int MAX>
vector<int> osak(int n) {
  static vector<int> f = factor_enumerate(MAX);
  vector<int> ret;
  while (f[n]) ret.push_back(f[n]), n /= f[n];
  return ret;
}

template <int MAX>
vector<pair<int, int>> osak_table(int n) {
  static vector<int> f = factor_enumerate(MAX);
  vector<pair<int, int>> v;
  for (; f[n]; n /= f[n]) {
    if (v.empty() || v.back().first != f[n]) {
      v.emplace_back(f[n], 1);
    } else {
      v.back().second++;
    }
  }
  return v;
}

template <int MAX>
vector<int> osak_divisors(int n) {
  if(n == 0) return {};
  if(n == 1) return vector<int>(1, 1);
  auto p = osak_table<MAX>(n);
  vector<int> ds;

  auto dfs = [&](auto r, int i, int c) {
    if (i == (int)p.size()) {
      ds.push_back(c);
      return;
    }
    for (int j = 0; j <= p[i].second; j++) {
      r(r, i + 1, c);
      c *= p[i].first;
    }
  };

  dfs(dfs, 0, 1);
  sort(begin(ds), end(ds));
  return ds;
}

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<int> prime_enumerate(int N) {
  vector<bool> sieve(N / 3 + 1, 1);
  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {
    if (!sieve[i]) continue;
    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,
             qe = sieve.size();
         q < qe; q += r = s - r)
      sieve[q] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)
    if (sieve[i]) ret.push_back(p);
  while (!ret.empty() && ret.back() > N) ret.pop_back();
  return ret;
}

using namespace Nyaan;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

template <int X>
struct FenwickSimd {
  static_assert(1 <= X && X <= 8 && X % 2 == 0);
  using m256 = __m256i;
  int *seg_base, *seg[X];
  m256 segC;
  FenwickSimd() {}
  FenwickSimd(int N) {
    // N < 8**X
    assert(N < 1 << (3 * X));
    int S = 0;
    int segCbuf[8] = {};
    for (int i = 0; i < X; i++) {
      N = (N + 7) / 8;
      segCbuf[i] = S;
      S += 8 * ((N + 4) / 4 * 4);
    }
    seg_base = new (align_val_t{32}) int[S]{};
    for (int i = 0; i < X; i++) seg[i] = seg_base + segCbuf[i];
    segC = _mm256_load_si256((m256 *)segCbuf);
  }
  /// a[i] += x
  void add(int p, int x) {
    const m256 xx = _mm256_set1_epi32(x);
    const m256 base = _mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0);
    for (int i = 0; i < X; i++) {
      #define f(I) \
      int dp##I = (p >> (i * 3)) & 7, up##I = (p >> (i * 3)) & ~7;\
      const m256 pd##I = _mm256_set1_epi32(dp##I);\
      const m256 ma##I = _mm256_cmpgt_epi32(base, pd##I);\
      const m256 xx##I = _mm256_and_si256(xx, ma##I);\
      const m256 ta##I = _mm256_loadu_si256((m256 *)(seg[i + I] + up##I));\
      const m256 re##I = _mm256_add_epi32(ta##I, xx##I);\
      _mm256_storeu_si256((m256 *)(seg[i + I] + up##I), re##I);
      
      f(0);
    }
  }
  // sum [0, i)
  int sum(int p) {
    int s{0};
    const m256 off = _mm256_set_epi32(21, 18, 15, 12, 9, 6, 3, 0);
    m256 adr = _mm256_set1_epi32(p);
    adr = _mm256_srlv_epi32(adr, off);
    adr = _mm256_add_epi32(adr, segC);

    m256 buf = _mm256_setzero_si256();
    const m256 mask = _mm256_set_epi32(
        7 < X ? -1 : 0, 6 < X ? -1 : 0, 5 < X ? -1 : 0, 4 < X ? -1 : 0,
        3 < X ? -1 : 0, 2 < X ? -1 : 0, 1 < X ? -1 : 0, 0 < X ? -1 : 0);
    buf = _mm256_mask_i32gather_epi32(buf, seg_base, adr, mask, 4);

    buf = _mm256_hadd_epi32(buf, buf);
    buf = _mm256_hadd_epi32(buf, buf);
    s += _mm256_extract_epi32(buf, 0);
    s += _mm256_extract_epi32(buf, 4);

    return s;
  }
  // sum [a, b)
  int sum(int a, int b) { return sum(b) - sum(a); }
};

FenwickSimd<6> bit(101000);

void bit_add(int i) { bit.add(i, 1); }
void bit_del(int i) { bit.add(i, -1); }
int bit_sum(int r) { return bit.sum(r + 1); }

vi fs[100100];
int exist[100100];
int Pi[100100];
vi ps;
int ans = 0, bns[100100];
ll N, M, C, Q;

void dfs(int i, int prod) {
  int lim = C / prod, p = ps[i];
  // 
  int curng = bit_sum(p - 1);
  ans += (Pi[lim] - Pi[p - 1]) - (bit_sum(lim) - curng);
  int j = i, je = sz(ps);
  for (; j < je and 1LL * ps[j] * ps[j] * ps[j] <= lim; j++) {
    if (exist[ps[j]]) {
      curng++;
      continue;
    }
    dfs(j, prod * ps[j]);
  }
  for (; j < je and 1LL * ps[j] * ps[j] <= lim; j++) {
    if (exist[ps[j]]) {
      curng++;
      continue;
    }
    int lim2 = lim / ps[j];
    ans += (Pi[lim2] - Pi[ps[j] - 1]) - (bit_sum(lim2) - curng);
  }
}

void q() {
  in(N, M, C, Q);
  vi a(N);
  in(a);
  {
    ps = prime_enumerate(100010);
    each(p, ps) Pi[p]++;
    rep(i, 100020) Pi[i + 1] += Pi[i];
    ps = prime_enumerate(4000);
    while (sz(ps) and ps.back() * ps.back() > C) ps.pop_back();
  }
  rep(i, N) {
    auto f = osak<20200>(a[i]);
    fs[i] = mkuni(f);
  }

  Mo mo(N, Q);
  rep(i, Q) {
    ini(l, r);
    --l;
    mo.insert(l, r);
  }
  auto add = [&](int i) {
    each(f, fs[i]) {
      if (exist[f] == 0) bit_add(f);
      exist[f]++;
    }
  };
  auto del = [&](int i) {
    each(f, fs[i]) {
      exist[f]--;
      if (exist[f] == 0) bit_del(f);
    }
  };
  auto query = [&](int q) {
    ans = Pi[C] - bit_sum(C) + 1;
    rep(i, sz(ps)) {
      if (exist[ps[i]]) continue;
      dfs(i, ps[i]);
    }
    bns[q] = ans;
  };
  mo.run(add, add, del, del, query);
  rep(i, Q) out(bns[i]);
}

void Nyaan::solve() {
  Timer timer;
  int T = 1;
  // in(T);
  while (T--) q();
  cerr << timer.elapsed() << endl;
}