/**
 *  date : 2021-03-01 01:29:48
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

namespace HashMapImpl {
using u32 = uint32_t;
using u64 = uint64_t;

template <typename Key, typename Data>
struct HashMapBase;

template <typename Key, typename Data>
struct itrB
    : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data *, Data &> {
  using base =
      iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data *, Data &>;
  using ptr = typename base::pointer;
  using ref = typename base::reference;

  u32 i;
  HashMapBase<Key, Data> *p;

  explicit constexpr itrB() : i(0), p(nullptr) {}
  explicit constexpr itrB(u32 _i, HashMapBase<Key, Data> *_p) : i(_i), p(_p) {}
  explicit constexpr itrB(u32 _i, const HashMapBase<Key, Data> *_p)
      : i(_i), p(const_cast<HashMapBase<Key, Data> *>(_p)) {}
  friend void swap(itrB &l, itrB &r) { swap(l.i, r.i), swap(l.p, r.p); }
  friend bool operator==(const itrB &l, const itrB &r) { return l.i == r.i; }
  friend bool operator!=(const itrB &l, const itrB &r) { return l.i != r.i; }
  const ref operator*() const {
    return const_cast<const HashMapBase<Key, Data> *>(p)->data[i];
  }
  ref operator*() { return p->data[i]; }
  ptr operator->() const { return &(p->data[i]); }

  itrB &operator++() {
    assert(i != p->cap && "itr::operator++()");
    do {
      i++;
      if (i == p->cap) break;
      if (p->flag[i] == true && p->dflag[i] == false) break;
    } while (true);
    return (*this);
  }
  itrB operator++(int) {
    itrB it(*this);
    ++(*this);
    return it;
  }
  itrB &operator--() {
    do {
      i--;
      if (p->flag[i] == true && p->dflag[i] == false) break;
      assert(i != 0 && "itr::operator--()");
    } while (true);
    return (*this);
  }
  itrB operator--(int) {
    itrB it(*this);
    --(*this);
    return it;
  }
};

template <typename Key, typename Data>
struct HashMapBase {
  using u32 = uint32_t;
  using u64 = uint64_t;
  using iterator = itrB<Key, Data>;
  using itr = iterator;

 protected:
  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K &key) const {
    return u32((u64(key ^ r) * 11995408973635179863ULL) >> shift);
  }
  template <
      typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K &key) const {
    u64 a = key.first ^ r;
    u64 b = key.second ^ r;
    a *= 11995408973635179863ULL;
    b *= 10150724397891781847ULL;
    return u32((a + b) >> shift);
  }
  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D &dat) const {
    return inner_hash(dat);
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D &dat) const {
    return inner_hash(dat.first);
  }

  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline Key dtok(const D &dat) const {
    return dat;
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline Key dtok(const D &dat) const {
    return dat.first;
  }

  void reallocate(u32 ncap) {
    vector<Data> ndata(ncap);
    vector<bool> nf(ncap);
    shift = 64 - __lg(ncap);
    for (u32 i = 0; i < cap; i++) {
      if (flag[i] == true && dflag[i] == false) {
        u32 h = hash(data[i]);
        while (nf[h]) h = (h + 1) & (ncap - 1);
        ndata[h] = data[i];
        nf[h] = true;
      }
    }
    data.swap(ndata);
    flag.swap(nf);
    cap = ncap;
    dflag.resize(cap);
    fill(std::begin(dflag), std::end(dflag), false);
  }

  inline bool extend_rate(u32 x) const { return x * 2 >= cap; }

  inline bool shrink_rate(u32 x) const {
    return HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;
  }

  inline void extend() { reallocate(cap << 1); }

  inline void shrink() { reallocate(cap >> 1); }

 public:
  u32 cap, s;
  vector<Data> data;
  vector<bool> flag, dflag;
  u32 shift;
  static u64 r;
  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;

  explicit HashMapBase()
      : cap(HASHMAP_DEFAULT_SIZE),
        s(0),
        data(cap),
        flag(cap),
        dflag(cap),
        shift(64 - __lg(cap)) {}

  itr begin() const {
    u32 h = 0;
    while (h != cap) {
      if (flag[h] == true && dflag[h] == false) break;
      h++;
    }
    return itr(h, this);
  }
  itr end() const { return itr(this->cap, this); }

  friend itr begin(const HashMapBase &h) { return h.begin(); }
  friend itr end(const HashMapBase &h) { return h.end(); }

  itr find(const Key &key) const {
    u32 h = inner_hash(key);
    while (true) {
      if (flag[h] == false) return this->end();
      if (dtok(data[h]) == key) {
        if (dflag[h] == true) return this->end();
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  bool contain(const Key &key) const { return find(key) != this->end(); }

  itr insert(const Data &d) {
    u32 h = hash(d);
    while (true) {
      if (flag[h] == false) {
        if (extend_rate(s + 1)) {
          extend();
          h = hash(d);
          continue;
        }
        data[h] = d;
        flag[h] = true;
        ++s;
        return itr(h, this);
      }
      if (dtok(data[h]) == dtok(d)) {
        if (dflag[h] == true) {
          data[h] = d;
          dflag[h] = false;
          ++s;
        }
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  // tips for speed up :
  // if return value is unnecessary, make argument_2 false.
  itr erase(itr it, bool get_next = true) {
    if (it == this->end()) return this->end();
    s--;
    if (shrink_rate(s)) {
      Data d = data[it.i];
      shrink();
      it = find(dtok(d));
    }
    int ni = (it.i + 1) & (cap - 1);
    if (this->flag[ni]) {
      this->dflag[it.i] = true;
    } else {
      this->flag[it.i] = false;
    }
    if (get_next) ++it;
    return it;
  }

  itr erase(const Key &key) { return erase(find(key)); }

  bool empty() const { return s == 0; }

  int size() const { return s; }

  void clear() {
    fill(std::begin(flag), std::end(flag), false);
    fill(std::begin(dflag), std::end(dflag), false);
    s = 0;
  }

  void reserve(int n) {
    if (n <= 0) return;
    n = 1 << min(23, __lg(n) + 2);
    if (cap < u32(n)) reallocate(n);
  }
};

template <typename Key, typename Data>
uint64_t HashMapBase<Key, Data>::r =
    chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch())
        .count();

}  // namespace HashMapImpl

/**
 * @brief Hash Map(base)()
 */

template <typename Key, typename Val>
struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {
  using base = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;
  using HashMapImpl::HashMapBase<Key, pair<Key, Val>>::HashMapBase;
  using Data = pair<Key, Val>;

  Val &operator[](const Key &k) {
    typename base::u32 h = base::inner_hash(k);
    while (true) {
      if (base::flag[h] == false) {
        if (base::extend_rate(base::s + 1)) {
          base::extend();
          h = base::hash(k);
          continue;
        }
        base::data[h].first = k;
        base::data[h].second = Val();
        base::flag[h] = true;
        ++base::s;
        return base::data[h].second;
      }
      if (base::data[h].first == k) {
        if (base::dflag[h] == true) base::data[h].second = Val();
        return base::data[h].second;
      }
      h = (h + 1) & (base::cap - 1);
    }
  }

  typename base::itr emplace(const Key &key, const Val &val) {
    return base::insert(Data(key, val));
  }
};

/*
 * @brief ()
 * @docs docs/hashmap/hashmap.md
 **/

namespace my_rand {

// [0, 2^64 - 1)
uint64_t rng() {
  static uint64_t x_ =
      uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                   chrono::high_resolution_clock::now().time_since_epoch())
                   .count()) *
      10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

// [l, r)
int64_t randint(int64_t l, int64_t r) {
  assert(l < r);
  return l + rng() % (r - l);
}

// choose n numbers from [l, r) without overlapping
vector<int64_t> randset(int64_t l, int64_t r, int64_t n) {
  assert(l <= r && n <= r - l);
  unordered_set<int64_t> s;
  for (int64_t i = n; i; --i) {
    int64_t m = randint(l, r + 1 - i);
    if (s.find(m) != s.end()) m = r - i;
    s.insert(m);
  }
  vector<int64_t> ret;
  for (auto &x : s) ret.push_back(x);
  return ret;
}

// [0.0, 1.0)
double rnd() {
  union raw_cast {
    double t;
    uint64_t u;
  };
  constexpr uint64_t p = uint64_t(1023 - 64) << 52;
  return rng() * ((raw_cast *)(&p))->t;
}

template <typename T>
void randshf(vector<T> &v) {
  int n = v.size();
  for (int loop = 0; loop < 2; loop++)
    for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]);
}

}  // namespace my_rand

using my_rand::randint;
using my_rand::randset;
using my_rand::randshf;
using my_rand::rnd;
using my_rand::rng;

using namespace Nyaan;

vi fib;
int n;
V<HashMap<int, int>> g;
pl kouho1, kouho2;

int sz(int c, int p, int dst1, int dst2) {
  int sm = 1;
  each(x, g[c]) {
    if (x.first == p) continue;
    if (x.second == 0) continue;
    sm += sz(x.first, c, dst1, dst2);
  }
  if (sm == dst1) {
    kouho1 = {c, p};
  } else if (sm == dst2) {
    kouho2 = {p, c};
  }
  return sm;
}

inline void flip(int u, int v) {
  g[u][v] ^= 1;
  g[v][u] ^= 1;
}

// d1ok
bool sol(int st, int N, bool judged = false, bool ok = false) {
  if (N <= 3) return true;
  int fi = lb(fib, N);
  int dst1 = fib[fi - 1];
  int dst2 = fib[fi - 2];

  pl non = pl{-1, -1};
  kouho1 = kouho2 = non;
  sz(st, -1, dst1, dst2);
  pl ko1 = kouho1;
  pl ko2 = kouho2;

  if (ko1 == non and ko2 == non) return false;
  if (ko1 != non and ko2 == non) {
    pl ko = ko1;
    auto [u, v] = ko;
    flip(u, v);
    bool uu = false, vv = false;
    uu = judged ? ok : sol(u, dst1);
    if (uu) vv = sol(v, dst2);
    flip(u, v);
    if (uu && vv) return true;
    return false;
  }
  if (ko1 == non and ko2 != non) {
    pl ko = ko2;
    auto [u, v] = ko;
    flip(u, v);
    bool uu = false, vv = false;
    uu = sol(u, dst1);
    if (uu) vv = sol(v, dst2);
    flip(u, v);
    if (uu && vv) return true;
    return false;
  }
  auto [u1, v1] = ko1;
  auto [u2, v2] = ko2;
  flip(u1, v1), flip(u2, v2);
  bool f1 = false, f2 = false;
  f1 = judged ? ok : sol(v1, dst2);
  f2 = sol(v2, dst2);
  bool f4 = true;

  if (f1 == false and f2 == false) {
    flip(u1, v1), flip(u2, v2);
    return false;
  }
  if (f1 == true and f2 == true) {
    bool f3 = sol(u1, dst1 - dst2);
    if (f3) {
      flip(u1, v1), flip(u2, v2);
      return true;
    }
    f4 = false;
  }
  if (f1 == true) {
    flip(u2, v2);
    bool f3 = sol(u1, dst1, true, f2 && f4);
    if (f3) {
      flip(u1, v1);
      return true;
    }
    flip(u2, v2);
  }
  if (f2 == true) {
    flip(u1, v1);
    bool f3 = sol(u1, dst1, true, f1 && f4);
    if (f3) {
      flip(u2, v2);
      return true;
    }
    flip(u1, v1);
  }

  flip(u1, v1), flip(u2, v2);
  return false;
}

void Nyaan::solve() {
  rep(_, 2) fib.push_back(1);
  while (fib.back() < TEN(7)) {
    int last = fib[sz(fib) - 2] + fib[sz(fib) - 1];
    fib.push_back(last);
  }
  in(n);
  g.resize(n);
  rep(i, n - 1) {
    ini(a, b);
    --a, --b;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  if (find(all(fib), n) == fib.end()) die("NO");

  bool ans = sol(0, n);
  out(ans ? "YES" : "NO");
}