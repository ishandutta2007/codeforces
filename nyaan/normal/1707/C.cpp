/**
 *  date : 2022-07-17 00:24:49
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



#define inV(T, v, n) \
  vector<T> v(n);    \
  in(v)

#define inVV(T, v, h, w)                \
  vector<vector<T>> v(h, vector<T>(w)); \
  in(v);

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

//  (ng, ok]  [ok, ng)
template <typename T, typename F>
T binary_search(T ng, T ok, const F& f) {
  if constexpr (is_integral<T>::value == true) {
    while (abs(ok - ng) > 1) {
      T x = (ok + ng) / 2;
      (f(x) ? ok : ng) = x;
    }
    return ok;
  } else {
    for (int iter = 0; iter < 60; iter++) {
      T x = (ok + ng) / 2;
      (f(x) ? ok : ng) = x;
    }
    return ok;
  }
}

//  (l, r)
template <typename T, typename F>
void ternary_search(T l, T r, const F& f, bool greater = false) {
  if constexpr (is_integral<T>::value == true) {
    while (abs(l - r) > 2) {
      T llr = (l * 2 + r * 1) / 3;
      T lrr = (l * 1 + r * 2) / 3;
      bool flag = f(llr) < f(lrr);
      if (flag != greater) {
        r = lrr;
      } else {
        l = llr;
      }
    }
    return (l + r) / 2;
  } else {
    for (int iter = 0; iter < 80; iter++) {
      T llr = (l * 2 + r * 1) / 3;
      T lrr = (l * 1 + r * 2) / 3;
      bool flag = f(llr) < f(lrr);
      if (flag != greater) {
        r = lrr;
      } else {
        l = llr;
      }
    }
    return (l + r) / 2;
  }
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

struct UnionFind {
  vector<int> data;
  UnionFind(int N) : data(N, -1) {}

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  // f ... merge function
  template<typename F>
  int unite(int x, int y,const F &f) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    f(x, y);
    return true;
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }
};

/**
 * @brief Union Find(Disjoint Set Union)
 * @docs docs/data-structure/union-find.md
 */


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



template <typename T>
T kruskal(int N, Edges<T> &es) {
  sort(begin(es), end(es),
       [&](edge<T> a, edge<T> b) { return a.cost < b.cost; });
  UnionFind uf(N);
  T ret = 0;
  for (edge<T> &e : es) {
    if (uf.same(e.src, e.to)) continue;
    ret += e.cost;
    uf.unite(e.src, e.to);
  }
  return ret;
}

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

template <typename G>
struct Tree {
 private:
  G& g;
  int root;
  vector<vector<int>> bl;
  vector<int> dp;
  void build() {
    bl.resize(g.size());
    dp.resize(g.size());
    dfs(root, -1, 0);
  }

  void dfs(int c, int p, int _dp) {
    dp[c] = _dp;
    for (int i = p, x = -1; i != -1;) {
      bl[c].push_back(i);
      i = ++x < (int)bl[i].size() ? bl[i][x] : -1;
    }
    for (auto& d : g[c]) {
      if (d == p) continue;
      dfs(d, c, _dp + 1);
    }
  }

 public:
  Tree(G& _g, int _r = 0) : g(_g), root(_r) { build(); }

  int depth(int u) const { return dp[u]; }

  int par(int u) const { return u == root ? -1 : bl[u][0]; }

  int kth_ancestor(int u, int k) const {
    if (dp[u] < k) return -1;
    for (int i = k ? __lg(k) : -1; i >= 0; --i) {
      if ((k >> i) & 1) u = bl[u][i];
    }
    return u;
  }

  int nxt(int s, int t) const {
    if (dp[s] >= dp[t]) return par(s);
    int u = kth_ancestor(t, dp[t] - dp[s] - 1);
    return bl[u][0] == s ? u : bl[s][0];
  }

  vector<int> path(int s, int t) const {
    vector<int> pre, suf;
    while (dp[s] > dp[t]) {
      pre.push_back(s);
      s = bl[s][0];
    }
    while (dp[s] < dp[t]) {
      suf.push_back(t);
      t = bl[t][0];
    }
    while (s != t) {
      pre.push_back(s);
      suf.push_back(t);
      s = bl[s][0];
      t = bl[t][0];
    }
    pre.push_back(s);
    reverse(begin(suf), end(suf));
    copy(begin(suf), end(suf), back_inserter(pre));
    return pre;
  }

  int lca(int u, int v) {
    if (dp[u] != dp[v]) {
      if (dp[u] > dp[v]) swap(u, v);
      v = kth_ancestor(v, dp[v] - dp[u]);
    }
    if (u == v) return u;
    for (int i = __lg(dp[u]); i >= 0; --i) {
      if (dp[u] < (1 << i)) continue;
      if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    }
    return bl[u][0];
  }
};

/**
 * @brief 
 * @docs docs/tree/tree-query.md
 */

using namespace Nyaan;

void q() {
  inl(N, M);
  using E = edge<int>;
  V<E> es;
  rep1(i, M) {
    ini(u, v);
    --u, --v;
    es.emplace_back(u, v, i);
  }
  set<int> mst;
  {
    UnionFind uf(N);
    each(e, es) {
      int u = e.src;
      int v = e.to;
      if (uf.same(u, v)) continue;
      uf.unite(u, v);
      mst.emplace(e.cost);
    }
  }

  SegmentTree seg(
      vi(N), [](int a, int b) { return a + b; }, 0);
  vvi tree(N);
  each(e, es) {
    if (mst.count(e.cost)) {
      int u = e.src;
      int v = e.to;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
  }
  trc(tree);
  Tree t(tree);
  VV<E> g(N);
  each(e, es) {
    int u = e.src;
    int v = e.to;
    int c = e.cost;
    if (mst.count(c)) {
      g[u].emplace_back(u, v, c);
      g[v].emplace_back(v, u, c);
    } else {
      int du = t.depth(u);
      int dv = t.depth(v);
      if (du > dv) swap(u, v);
      g[v].emplace_back(v, u, c);
    }
  }

  vi dp(N + 1);
  vi par(N);
  {
    auto dfs = [&](auto rc, int c, int p = -1,
                   [[maybe_unused]] ll dat = 0) -> void {
      par[c] = 1;
      for (auto& d : g[c]) {
        if (d == p) continue;
        if (mst.count(d.cost) == 0) {
          // d 
          if (par[d]) {
            int x = t.nxt(d, c);
            trc(d, x, c);
            dp[x]++, dp[c]--;
          } else {
            dp[d]--, dp[c]--, dp[0]++;
          }
        } else {
          rc(rc, d, c);
        }
      }
      par[c] = 0;
    };
    dfs(dfs, 0);
  }
  trc(dp);

  {
    auto dfs = [&](auto rc, int c, int p = -1, ll dat = 0) -> void {
      dp[c] += dat;
      for (auto& d : g[c]) {
        if (d == p) continue;
        if (mst.count(d.cost) == 0) {
        } else {
          rc(rc, d, c, dp[c]);
        }
      }
    };
    dfs(dfs, 0);
  }

  trc(dp);
  string ans(N, '0');
  rep(i, N) ans[i] = dp[i] ? '0' : '1';
  out(ans);
}

void Nyaan::solve() {
  int T = 1;
  // in(T);
  while (T--) q();
}