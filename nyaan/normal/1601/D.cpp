/**
 *  date : 2021-10-25 17:04:32
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
//




struct bit_vector {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  static constexpr u32 w = 64;
  vector<u64> block;
  vector<u32> count;
  u32 n, zeros;

  inline u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }
  inline void set(u32 i) { block[i / w] |= 1LL << (i % w); }

  bit_vector() {}
  bit_vector(int _n) { init(_n); }
  __attribute__((optimize("O3,unroll-loops"))) void init(int _n) {
    n = zeros = _n;
    block.resize(n / w + 1, 0);
    count.resize(block.size(), 0);
  }

  __attribute__((target("popcnt"))) void build() {
    for (u32 i = 1; i < block.size(); ++i)
      count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);
    zeros = rank0(n);
  }

  inline u32 rank0(u32 i) const { return i - rank1(i); }

  __attribute__((target("bmi2,popcnt"))) inline u32 rank1(u32 i) const {
    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));
  }
};

template <typename S, typename T>
struct WaveletMatrix {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  struct BIT {
    u32 N;
    vector<T> data;

    BIT() = default;
    BIT(int size) { init(size); }

    void init(int size) {
      N = size;
      data.assign(N + 1, 0);
    }

    __attribute__((target("bmi"))) void add(u32 k, T x) {
      for (++k; k <= N; k += _blsi_u32(k)) data[k] += x;
    }

    __attribute__((target("bmi"))) T sum(u32 k) const {
      T ret = T();
      for (; k; k = _blsr_u32(k)) ret += data[k];
      return ret;
    }

    __attribute__((target("bmi"))) T sum(int l, int r) const {
      T ret = T();
      while (l != r) {
        if (l < r) {
          ret += data[r];
          r = _blsr_u32(r);
        } else {
          ret -= data[l];
          l = _blsr_u32(l);
        }
      }
      return ret;
    }
  };

  using P = pair<S, S>;
  int n, lg;
  vector<bit_vector> bv;
  vector<BIT> bit;
  vector<P> ps;
  vector<S> ys;

  WaveletMatrix() {}

  void add_point(S x, S y) {
    ps.emplace_back(x, y);
    ys.emplace_back(y);
  }

  __attribute__((optimize("O3"))) void build() {
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));
    n = ps.size();
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    vector<u32> cur(n), nxt(n);
    for (int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);
    lg = __lg(max(n, 1)) + 1;
    bv.assign(lg, n);
    bit.assign(lg, n);
    for (int h = lg - 1; h >= 0; --h) {
      for (int i = 0; i < n; ++i)
        if ((cur[i] >> h) & 1) bv[h].set(i);
      bv[h].build();
      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
      swap(cur, nxt);
    }
  }

  int xid(S x) const {
    return lower_bound(
               begin(ps), end(ps), make_pair(x, S()),
               [](const P& a, const P& b) { return a.first < b.first; }) -
           begin(ps);
  }

  int yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys); }

  void add(S x, S y, T val) {
    int i = lower_bound(begin(ps), end(ps), P{x, y}) - begin(ps);
    for (int h = lg - 1; h >= 0; --h) {
      int i0 = bv[h].rank0(i);
      if (bv[h].get(i))
        i += bv[h].zeros - i0;
      else
        i = i0;
      bit[h].add(i, val);
    }
  }

  T sum(int l, int r, u32 upper) const {
    T res = 0;
    for (int h = lg; h--;) {
      int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      if ((upper >> h) & 1) {
        res += bit[h].sum(l0, r0);
        l += bv[h].zeros - l0;
        r += bv[h].zeros - r0;
      } else {
        l = l0, r = r0;
      }
    }
    return res;
  }

  T sum(S lx, S ly, S rx, S ry) const {
    int l = xid(lx), r = xid(rx);
    return sum(l, r, yid(ry)) - sum(l, r, yid(ly));
  }
};
using namespace Nyaan;

void Nyaan::solve() {
  inl(N, D);
  vl s(N), a(N);
  in2(s, a);

  WaveletMatrix<int, int> wm;

  vp v, v2;
  ll ans = 0;
  rep(i, N) {
    if (s[i] >= a[i]) {
      if (D <= s[i]) {
        wm.add_point(s[i], a[i]);
        v2.emplace_back(s[i], a[i]);
        ans++;
      }
    } else {
      if (D <= s[i]) v.emplace_back(s[i], a[i]);
    }
  }
  wm.build();
  trc(v);
  trc(v2);
  each2(x, y, v2) wm.add(x, y, 1);

  sort(all(v), [](pl p, pl q) { return p.se < q.se; });

  V<pl> ps;
  each(p, v) {
    auto [x, y] = p;
    int cnt = wm.sum(x + 1, x + 1, y, y);
    trc(p, cnt);
    if (cnt == 0) ps.push_back(p);
  }
  trc(ps);
  sort(all(ps), [](pl p, pl q) { return p.se < q.se; });
  each(p, ps) {
    if (D <= p.fi) {
      ans++;
      D = p.se;
    }
  }
  out(ans);
}