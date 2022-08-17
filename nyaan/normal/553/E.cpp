/**
 *  date : 2021-06-09 20:50:38
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

namespace ArbitraryModConvolution {

template <typename T>
struct Cp {
  T x, y;
  constexpr Cp() : x(0), y(0) {}
  constexpr Cp(T _x, T _y) : x(_x), y(_y) {}
  constexpr inline Cp operator+(const Cp& c) const {
    return Cp(x + c.x, y + c.y);
  }
  constexpr inline Cp operator-(const Cp& c) const {
    return Cp(x - c.x, y - c.y);
  }
  constexpr inline Cp operator*(const Cp& c) const {
    return Cp(x * c.x - y * c.y, x * c.y + y * c.x);
  }
  constexpr inline Cp operator-() const { return Cp(-x, -y); }
  constexpr inline Cp conj() const { return Cp(x, -y); }
  constexpr inline Cp rotl() const { return Cp(-y, x); }
  friend ostream& operator<<(ostream& os, const Cp& c) {
    os << "(" << c.x << ", " << c.y << ")" << endl;
    return os;
  }
};

using C = Cp<double>;
const long double PI = acosl(-1);

struct CooleyTukey {
  static vector<C> w;

  static void setw(int k) {
    --k;
    if ((int)w.size() >= (1 << k)) return;
    w.resize(1 << k);
    vector<Cp<long double>> base(k);
    const long double arg = PI / (1 << k);
    for (int i = 0, j = 1 << (k - 1); j; i++, j >>= 1) {
      complex<long double> z = exp(complex<long double>(1i) * (arg * j));
      base[i] = Cp<long double>{z.real(), z.imag()};
    }
    genw(0, k - 1, Cp<long double>{1, 0}, base);
  }

  static void genw(int i, int b, Cp<long double> z,
                   const vector<Cp<long double>>& base) {
    if (b == -1) {
      w[i].x = z.x, w[i].y = z.y;
    } else {
      genw(i, b - 1, z, base);
      genw(i | (1 << b), b - 1, z * base[b], base);
    }
  }

  static void fft(vector<C>& a, int k) {
    if (k <= 0) return;
    if (k == 1) {
      C a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    if (k & 1) {
      int v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        C ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] = a[j] + ajv;
      }
    }
    int u = 1 << (k & 1), v = 1 << (k - 2 - (k & 1));
    while (v) {
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = v;
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          C t0p2 = t0 + t2, t1p3 = t1 + t3;
          C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      // jh >= 1
      for (int jh = 1; jh < u; ++jh) {
        int j0 = jh * v * 4;
        int j1 = j0 + v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = j1;
        C ww = w[jh];
        C xx = w[jh << 1];
        C wx = ww * xx;
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1] * xx, t2 = a[j2] * ww, t3 = a[j3] * wx;
          C t0p2 = t0 + t2, t1p3 = t1 + t3;
          C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      u <<= 2, v >>= 2;
    }
  }

  static void ifft(vector<C>& a, int k) {
    if ((int)a.size() <= 1) return;
    if (k == 1) {
      C a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    int u = 1 << (k - 2);
    int v = 1;
    while (u) {
      // jh = 0
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          C t0p1 = t0 + t1, t2p3 = t2 + t3;
          C t0m1 = t0 - t1, t2m3 = (t2 - t3) * w[1].conj();
          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
        }
      }
      // jh >= 1
      for (int jh = 1; jh < u; ++jh) {
        int j0 = (jh * v) << 2;
        int j1 = j0 + v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = j1;
        C ww = w[jh].conj();
        C xx = w[jh << 1].conj();
        C yy = w[(jh << 1) + 1].conj();
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          C t0p1 = t0 + t1, t2p3 = t2 + t3;
          C t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
          a[j1] = t0m1 + t2m3, a[j3] = (t0m1 - t2m3) * ww;
        }
      }
      u >>= 2;
      v <<= 2;
    }
    if (k & 1) {
      u = 1 << (k - 1);
      for (int j = 0; j < u; j++) {
        C ajv = a[j] - a[j + u];
        a[j] = a[j] + a[j + u];
        a[j + u] = ajv;
      }
    }
  }

  static void fft_real(vector<C>& AL, vector<C>& AH, int k) {
    fft(AL, k);
    AH[0] = C{AL[0].y * 2.0, 0};
    AL[0] = C{AL[0].x * 2.0, 0};
    AH[1] = C{AL[1].y * 2.0, 0};
    AL[1] = C{AL[1].x * 2.0, 0};
    for (int i = 2, y = 2; y < (1 << k); y <<= 1) {
      for (; i < 2 * y; i += 2) {
        int j = i ^ (y - 1);
        AH[i] = (AL[j].conj() - AL[i]).rotl();
        AL[i] = (AL[j].conj() + AL[i]);
        AH[j] = AH[i].conj();
        AL[j] = AL[i].conj();
      }
    }
  }

  // naive convolution for int
  template <typename T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr>
  static vector<long long> multiply(const vector<T>& s, const vector<T>& t) {
    int l = s.size() + t.size() - 1;
    if (min(s.size(), t.size()) <= 40) {
      vector<long long> u(l);
      for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j < (int)t.size(); j++) u[i + j] += 1LL * s[i] * t[j];
      }
      return u;
    }

    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
    setw(k);
    auto round = [](double x) -> long long {
      return (long long)(x + (x > 0 ? 0.5 : -0.5));
    };

    vector<C> a(M);
    for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];
    for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];
    fft(a, k);

    a[0].y = 4.0 * a[0].x * a[0].y;
    a[1].y = 4.0 * a[1].x * a[1].y;
    a[0].x = a[1].x = 0.0;
    for (int i = 2; i < M; i += 2) {
      int c = 1 << (31 - __builtin_clz(i));
      int j = i ^ (c - 1);
      a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());
      a[j] = -a[i].conj();
    }

    vector<C> b(M / 2);
    for (int j = 0; j < M / 2; j++) {
      C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];
      C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();
      b[j] = tmp1 + tmp2.rotl();
    }
    ifft(b, k - 1);

    vector<long long> u(l);
    for (int i = 0; i < l; i++) {
      if (i & 1) {
        u[i] = round(-b[i >> 1].x / (4.0 * M));
      } else {
        u[i] = round(b[i >> 1].y / (4.0 * M));
      }
    }
    return u;
  }

  static vector<double> multiply(const vector<double>& s,
                                 const vector<double>& t) {
    int l = s.size() + t.size() - 1;
    if (min(s.size(), t.size()) <= 40) {
      vector<double> u(l);
      for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j < (int)t.size(); j++) u[i + j] += s[i] * t[j];
      }
      return u;
    }

    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
    setw(k);

    vector<C> a(M);
    for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];
    for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];
    fft(a, k);

    a[0].y = 4.0 * a[0].x * a[0].y;
    a[1].y = 4.0 * a[1].x * a[1].y;
    a[0].x = a[1].x = 0.0;
    for (int i = 2; i < M; i += 2) {
      int c = 1 << (31 - __builtin_clz(i));
      int j = i ^ (c - 1);
      a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());
      a[j] = -a[i].conj();
    }

    vector<C> b(M / 2);
    for (int j = 0; j < M / 2; j++) {
      C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];
      C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();
      b[j] = tmp1 + tmp2.rotl();
    }
    ifft(b, k - 1);

    vector<double> u(l);
    for (int i = 0; i < l; i++) {
      if (i & 1) {
        u[i] = -b[i >> 1].x / (4.0 * M);
      } else {
        u[i] = b[i >> 1].y / (4.0 * M);
      }
    }
    return u;
  }

  template <unsigned int MOD>
  static vector<int> multiply_15bit(const vector<int>& a,
                                    const vector<int>& b) {
    using u64 = unsigned long long;
    constexpr u64 B = 32000;
    int l = a.size() + b.size() - 1;
    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
    setw(k);
    auto round = [](double x) -> u64 { return u64(x + 0.5); };

    vector<C> AL(M), AH(M), BL(M), BH(M);
    for (int i = 0; i < (int)a.size(); i++) {
      AL[i] = C{double(a[i] % B), double(a[i] / B)};
    }
    for (int i = 0; i < (int)b.size(); i++) {
      BL[i] = C{double(b[i] % B), double(b[i] / B)};
    }

    fft_real(AL, AH, k);
    fft_real(BL, BH, k);

    for (int i = 0; i < M; i++) {
      C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();
      BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();
      BL[i] = tmp;
    }

    ifft(BL, k);
    ifft(BH, k);

    vector<int> u(l);
    double im = 1.0 / (4.0 * M);
    for (int i = 0; i < l; i++) {
      BL[i].x *= im, BL[i].y *= im;
      BH[i].x *= im, BH[i].y *= im;
      int x1 = u64(round(BL[i].x)) % MOD;
      int x2 = u64(round(BH[i].x) + round(BH[i].y)) % MOD * B % MOD;
      int x3 = u64(round(BL[i].y)) % MOD * (B * B % MOD) % MOD;
      if ((x1 += x2) >= (int)MOD) x1 -= MOD;
      if ((x1 += x3) >= (int)MOD) x1 -= MOD;
      u[i] = x1;
    }
    return u;
  }
};
vector<C> CooleyTukey::w;

}  // namespace ArbitraryModConvolution


using namespace Nyaan;

struct E {
  int a, b, c;
  vd v;
  E(int _a, int _b, int _c, const vd& _v) : a(_a), b(_b), c(_c), v(_v) {}
};

void Nyaan::solve() {
  using namespace ArbitraryModConvolution;

  ini(N, M, T, X);
  V<E> es;

  rep(i, M) {
    ini(a, b, c);
    --a, --b;
    vd v(T + 1);
    rep1(_, T) in(v[_]);
    each(x, v) x /= TEN(5);
    es.emplace_back(a, b, c, v);
  }

  vi dist(N, -1);
  // dijkstra
  {
    priority_queue<pl, vp, greater<>> Q;
    dist[N - 1] = 0;
    Q.emplace(0, N - 1);
    while (!Q.empty()) {
      auto [dc, c] = Q.top();
      Q.pop();
      if (dist[c] != dc) continue;
      each(e, es) {
        if (c != e.b) continue;
        int d = e.a;
        int dd = dc + e.c;
        if (dist[d] == -1 or dist[d] > dd) {
          dist[d] = dd;
          Q.emplace(dd, d);
        }
      }
    }
  }
  trc(dist);

  // -T  T 
  V<vd> Wn(N, vd(2 * T + 1));
  V<vd> We(M, vd(2 * T + 1));
  int of = T;

  rep(i, N) {
    auto& w = Wn[i];
    if (i == N - 1) {
      fill(begin(w), begin(w) + T, double(X));
      fill(begin(w) + T + 1, end(w), 0.0);
      continue;
    }
    // 0Wn
    fill(begin(w), begin(w) + T, double(X + dist[i]));
    // 0
    fill(begin(w) + T, end(w), 1e30);
  }

  // WeX
  rep(i, M) {
    auto& e = es[i];
    auto& w = We[i];
    fill(begin(w), end(w), double(es[i].c));
    // 
    double p = 1.0;
    double cost = Wn[e.b][0];
    for (int j = 0; j <= T; j++) {
      p -= e.v[j];
      We[i][j + of] += cost * p;
    }
  }

  auto dd = [&](auto rc, int l, int r) {
    if (l + 1 == r) {
      // Wn[*][l]
      rep(i, M) {
        auto& e = es[i];
        amin(Wn[e.a][l + of], We[i][l + of]);
      }
      return;
    }

    int m = (l + r) / 2;

    // [l, m)Wn
    rc(rc, l, m);

    // Wn[*][l...m) -> We[*][m...r)
    rep(i, M) {
      auto& e = es[i];
      // We[i][x] += sum_j Wn[b][x-j] * t[j]
      vd f{begin(Wn[e.b]) + of + l, begin(Wn[e.b]) + of + m};
      vd g{begin(e.v), begin(e.v) + min(r - l, T + 1)};
      auto h = CooleyTukey::multiply(f, g);
      for (int x = m; x < r; x++) {
        if (x - l < sz(h)) We[i][of + x] += h[x - l];
      }
    }

    // [m, r)Wn
    rc(rc, m, r);
  };

  dd(dd, 0, T + 1);

  // rep(i, N) trc(Wn[i]);
  // rep(i, M) trc(We[i]);

  out(Wn[0].back());
}