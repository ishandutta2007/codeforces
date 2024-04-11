/**
 *  date : 2021-04-21 23:34:30
 */

#define NDEBUG
/**
 *  date : 2021-04-21 23:29:45
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

void dump(const char &t) { cerr << t; }

void dump(const string &t) { cerr << t; }

template <typename U,
          enable_if_t<!is_specialize<U>::value, nullptr_t> = nullptr>
void dump(const U &t) {
  cerr << t;
}

template <typename T>
void dump(const T &t, enable_if_t<is_integral<T>::value> * = nullptr) {
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
void dump(const pair<T, U> &);
template <typename T>
void dump(const pair<T *, int> &);

template <typename T>
void dump(const T &t,
          enable_if_t<!is_void<typename T::iterator>::value> * = nullptr) {
  cerr << "[ ";
  for (auto it = t.begin(); it != t.end();) {
    dump(*it);
    cerr << (++it == t.end() ? "" : ", ");
  }
  cerr << " ]";
}

template <typename T, typename U>
void dump(const pair<T, U> &t) {
  cerr << "( ";
  dump(t.first);
  cerr << ", ";
  dump(t.second);
  cerr << " )";
}

template <typename T>
void dump(const pair<T *, int> &t) {
  cerr << "[ ";
  for (int i = 0; i < t.second; i++) {
    dump(t.first[i]);
    cerr << (i == t.second - 1 ? "" : ", ");
  }
  cerr << " ]";
}

void trace() { cerr << endl; }
template <typename Head, typename... Tail>
void trace(Head &&head, Tail &&...tail) {
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
#define each(x, v) for (auto &&x : v)
#define each2(x, y, v) for (auto &&[x, y] : v)
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
    if (auto &val = vec[i]; false)                        \
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

template <typename T>
struct BinaryLifting {
  using Data = pair<int, T>;

  const int N, LOG;
  vector<vector<Data>> table;
  T I;

  BinaryLifting(int n, uint64_t lim, const T I_ = T())
      : N(n), LOG(__lg(lim) + 2), I(I_) {
    table.resize(n, vector<Data>(LOG, Data(-1, I)));
  }

  void set_next(int k, int nxt, const T &t) { table[k][0] = Data(nxt, t); }

  void build() {
    for (int k = 0; k + 1 < LOG; ++k)
      for (int i = 0; i < N; ++i) {
        int pre = table[i][k].first;
        if (pre == -1) {
          table[i][k + 1] = table[i][k];
        } else {
          table[i][k + 1].first = table[pre][k].first;
          table[i][k + 1].second = table[i][k].second + table[pre][k].second;
        }
      }
  }

  // from i, move t times
  Data query(int i, uint64_t t) const {
    T d = I;
    for (int k = LOG - 1; k >= 0; k--) {
      if ((t >> k) & 1) {
        d = d + table[i][k].second;
        i = table[i][k].first;
      }
      if (i == -1) break;
    }
    return Data(i, d);
  }

  // query(i, pow(2, k))
  inline Data query_pow(int i, int k) const { return table[i][k]; }

  // assuming graph is DAG ( edge(u, v) <-> u < v )
  // find max j | j <= t, path from i to j exists
  inline pair<uint64_t, Data> binary_search(int i, int t) {
    int thres = i;
    T d = I;
    uint64_t times = 0;
    for (int k = LOG - 1; k >= 0; k--) {
      int nxt = table[thres][k].first;
      if (nxt != -1 && nxt <= t) {
        d = d + table[thres][k].second;
        thres = nxt;
        times += 1LL << k;
      }
    }
    return make_pair(times, Data(thres, d));
  }
};

template <typename T>
using Doubling = BinaryLifting<T>;

/**
 * @brief Binary Lifting()
 * @docs docs/misc/doubling.md
 */

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
  if (n == 0) return {};
  if (n == 1) return vector<int>(1, 1);
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
using namespace Nyaan;

void Nyaan::solve() {
  ini(N, Q);
  vi a(N);
  in(a);

  vvi ds(TEN(5) + 1);
  rep1(i, TEN(5)) ds[i] = osak<TEN(5) + 3>(i);

  vi b(N);

  // syakutori
  {
    int j = 0;
    vi vis(TEN(5) + 3);
    rep(i, N) {
      // [i, j)
      while (true) {
        if (j == N) break;
        int f = 1;
        auto& d = ds[a[j]];
        each(x, d) f &= x == 1 or vis[x] == 0;
        if (!f) break;
        each(x, d) vis[x] += 1;
        j++;
      }
      b[i] = j;
      auto& d = ds[a[i]];
      each(x, d) vis[x] -= 1;
    }
  }

  trc(b);
  BinaryLifting<int> db(N, inf, 0);
  rep(i, N) {
    if (b[i] != N) db.set_next(i, b[i], 1);
  }
  db.build();

  rep(i, Q) {
    ini(l, r);
    --l, --r;
    out(db.binary_search(l, r).second.second + 1);
  }
}