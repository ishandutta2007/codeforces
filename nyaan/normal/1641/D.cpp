/**
 *  date : 2022-02-23 20:40:55
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


namespace HashMapImpl {
using u32 = uint32_t;
using u64 = uint64_t;

template <typename Key, typename Data>
struct HashMapBase;

template <typename Key, typename Data>
struct itrB
    : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data*, Data&> {
  using base =
      iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data*, Data&>;
  using ptr = typename base::pointer;
  using ref = typename base::reference;

  u32 i;
  HashMapBase<Key, Data>* p;

  explicit constexpr itrB() : i(0), p(nullptr) {}
  explicit constexpr itrB(u32 _i, HashMapBase<Key, Data>* _p) : i(_i), p(_p) {}
  explicit constexpr itrB(u32 _i, const HashMapBase<Key, Data>* _p)
      : i(_i), p(const_cast<HashMapBase<Key, Data>*>(_p)) {}
  friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }
  friend bool operator==(const itrB& l, const itrB& r) { return l.i == r.i; }
  friend bool operator!=(const itrB& l, const itrB& r) { return l.i != r.i; }
  const ref operator*() const {
    return const_cast<const HashMapBase<Key, Data>*>(p)->data[i];
  }
  ref operator*() { return p->data[i]; }
  ptr operator->() const { return &(p->data[i]); }

  itrB& operator++() {
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
  itrB& operator--() {
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
  template <typename K>
  inline u64 randomized(const K& key) const {
    return u64(key) ^ r;
  }

  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) const {
    return (randomized(key) * 11995408973635179863ULL) >> shift;
  }
  template <
      typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) const {
    u64 a = randomized(key.first), b = randomized(key.second);
    a *= 11995408973635179863ULL;
    b *= 10150724397891781847ULL;
    return (a + b) >> shift;
  }
  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<typename K::value_type>::value, nullptr_t> =
                nullptr>
  inline u32 inner_hash(const K& key) const {
    static constexpr u64 mod = (1LL << 61) - 1;
    static constexpr u64 base = 950699498548472943ULL;
    u64 res = 0;
    for (auto& elem : key) {
      __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);
      res = (x & mod) + (x >> 61);
    }
    __uint128_t x = __uint128_t(res) * base;
    res = (x & mod) + (x >> 61);
    if (res >= mod) res -= mod;
    return res >> (shift - 3);
  }

  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D& dat) const {
    return inner_hash(dat);
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D& dat) const {
    return inner_hash(dat.first);
  }

  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline Key dtok(const D& dat) const {
    return dat;
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline Key dtok(const D& dat) const {
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
        ndata[h] = move(data[i]);
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

  friend itr begin(const HashMapBase& h) { return h.begin(); }
  friend itr end(const HashMapBase& h) { return h.end(); }

  itr find(const Key& key) const {
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

  bool contain(const Key& key) const { return find(key) != this->end(); }

  itr insert(const Data& d) {
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

  itr erase(const Key& key) { return erase(find(key)); }

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

  Val& operator[](const Key& k) {
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

  typename base::itr emplace(const Key& key, const Val& val) {
    return base::insert(Data(key, val));
  }
};

/* 
 * @brief ()
 * @docs docs/hashmap/hashmap.md
**/



using namespace std;

namespace fastio {
static constexpr int SZ = 1 << 17;
char inbuf[SZ], outbuf[SZ];
int in_left = 0, in_right = 0, out_right = 0;

struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  int len = in_right - in_left;
  memmove(inbuf, inbuf + in_left, len);
  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);
  in_left = 0;
}

inline void flush() {
  fwrite(outbuf, 1, out_right, stdout);
  out_right = 0;
}

inline void skip_space() {
  if (in_left + 32 > in_right) load();
  while (inbuf[in_left] <= ' ') in_left++;
}

inline void rd(char& c) {
  if (in_left + 32 > in_right) load();
  c = inbuf[in_left++];
}
template <typename T>
inline void rd(T& x) {
  if (in_left + 32 > in_right) load();
  char c;
  do c = inbuf[in_left++];
  while (c < '-');
  [[maybe_unused]] bool minus = false;
  if constexpr (is_signed<T>::value == true) {
    if (c == '-') minus = true, c = inbuf[in_left++];
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    c = inbuf[in_left++];
  }
  if constexpr (is_signed<T>::value == true) {
    if (minus) x = -x;
  }
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head& head, Tail&... tail) {
  rd(head);
  rd(tail...);
}

inline void wt(char c) {
  if (out_right > SZ - 32) flush();
  outbuf[out_right++] = c;
}
inline void wt(bool b) {
  if (out_right > SZ - 32) flush();
  outbuf[out_right++] = b ? '1' : '0';
}
inline void wt(const string &s) {
  if (out_right + s.size() > SZ - 32) flush();
  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());
  out_right += s.size();
}
template <typename T>
inline void wt(T x) {
  if (out_right > SZ - 32) flush();
  if (!x) {
    outbuf[out_right++] = '0';
    return;
  }
  if constexpr (is_signed<T>::value == true) {
    if (x < 0) outbuf[out_right++] = '-', x = -x;
  }
  int i = 12;
  char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
    x /= 10000;
    i -= 4;
  }
  if (x < 100) {
    if (x < 10) {
      outbuf[out_right] = '0' + x;
      ++out_right;
    } else {
      uint32_t q = (uint32_t(x) * 205) >> 11;
      uint32_t r = uint32_t(x) - q * 10;
      outbuf[out_right] = '0' + q;
      outbuf[out_right + 1] = '0' + r;
      out_right += 2;
    }
  } else {
    if (x < 1000) {
      memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);
      out_right += 3;
    } else {
      memcpy(outbuf + out_right, pre.num + (x << 2), 4);
      out_right += 4;
    }
  }
  memcpy(outbuf + out_right, buf + i + 4, 12 - i);
  out_right += 12 - i;
}
inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head&& head, Tail&&... tail) {
  wt(head);
  wt(forward<Tail>(tail)...);
}
template <typename... Args>
inline void wtn(Args&&... x) {
  wt(forward<Args>(x)...);
  wt('\n');
}

struct Dummy {
  Dummy() { atexit(flush); }
} dummy;

}  // namespace fastio
using fastio::rd;
using fastio::skip_space;
using fastio::wt;
using fastio::wtn;


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
vector<long long> randset(int64_t l, int64_t r, int64_t n) {
  assert(l <= r && n <= r - l);
  unordered_set<int64_t> s;
  for (int64_t i = n; i; --i) {
    int64_t m = randint(l, r + 1 - i);
    if (s.find(m) != s.end()) m = r - i;
    s.insert(m);
  }
  vector<long long> ret;
  for (auto& x : s) ret.push_back(x);
  return ret;
}

// [0.0, 1.0)
double rnd() {
  union raw_cast {
    double t;
    uint64_t u;
  };
  constexpr uint64_t p = uint64_t(1023 - 64) << 52;
  return rng() * ((raw_cast*)(&p))->t;
}

template <typename T>
void randshf(vector<T>& v) {
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



struct Timer {
  chrono::high_resolution_clock::time_point st;

  Timer() { reset(); }

  void reset() { st = chrono::high_resolution_clock::now(); }

  chrono::milliseconds::rep elapsed() {
    auto ed = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();
  }
};
using namespace Nyaan;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

constexpr int LG = 20;
constexpr int L = 1 << LG;
int a[L];

void zeta() {
  {
    int k = 2;
    for (int l = 0; l < L; l += k * 2) {
      for (int i = 0; i < k; ++i) {
        a[l + k + i] = min(a[l + k + i], a[l + i]);
      }
    }
  }

  {
    int k = 4;
    for (int l = 0; l < L; l += k * 2) {
      for (int i = 0; i < k; ++i) {
        a[l + k + i] = min(a[l + k + i], a[l + i]);
      }
    }
  }

  {
    int k = 8;
    for (int l = 0; l < L; l += k * 2) {
      for (int i = 0; i < k; ++i) {
        a[l + k + i] = min(a[l + k + i], a[l + i]);
      }
    }
  }

  for (int k = 16; k < L; k *= 2) {
    for (int l = 0; l < L; l += k * 2) {
      for (int i = 0; i < k; ++i) {
        a[l + k + i] = min(a[l + k + i], a[l + i]);
      }
    }
  }
}

void q() {
  Timer timer;

  int N, M;
  rd(N, M);
  vvi A(N, vi(M));
  vi w(N);
  vi xs;
  rep(i, N) {
    each(x, A[i]) {
      rd(x);
      xs.push_back(x);
    }
    rd(w[i]);
  }
  xs = mkuni(xs);
  rep(i, N) { each(x, A[i]) x = lb(xs, x); }
  vi hash(sz(xs));
  trc(A);

  ll ans = infLL;
  vi mask(N);
  ll cnt = 0;
  while (timer.elapsed() < 2700) {
    each(x, hash) x = rng() % LG;
    fill(a, a + L, inf);
    rep(i, N) {
      int m = 0;
      each(x, A[i]) m |= 1 << hash[x];
      mask[i] = m;
      amin(a[m], w[i]);
    }
    zeta();
    rep(i, N) {
      int m = mask[i];
      int x = a[L - 1 - m];
      if(x != inf) amin(ans, w[i] + x);
    }
    cnt++;
  }
  cerr << cnt << "\n";
  if(ans == infLL) ans = -1;
  out(ans);
}

void Nyaan::solve() {
  int T = 1;

  // in(T);

  while (T--) q();
}