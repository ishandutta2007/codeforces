/**
 *  date : 2020-11-03 00:19:56
 */

#pragma region kyopro_template
#define Nyaan_template
#include <immintrin.h>
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x, v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define mem(a, val) memset(a, val, sizeof(a))
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
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define die(...)      \
  do {                \
    out(__VA_ARGS__); \
    return;           \
  } while (0)
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vd = V<double>;
using vs = V<string>;
using vvl = vector<vector<long long>>;
using P = pair<long long, long long>;
using vp = vector<P>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;
constexpr int inf = 1001001001;
constexpr long long infLL = (1LL << 61) - 1;
template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
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
template <typename T, class... U>
void out(const T &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}

#ifdef NyaanDebug
#define trc(...)                   \
  do {                             \
    cerr << #__VA_ARGS__ << " = "; \
    dbg_out(__VA_ARGS__);          \
  } while (0)
#define trca(v, N)       \
  do {                   \
    cerr << #v << " = "; \
    array_out(v, N);     \
  } while (0)
#define trcc(v)                             \
  do {                                      \
    cerr << #v << " = {";                   \
    each(x, v) { cerr << " " << x << ","; } \
    cerr << "}" << endl;                    \
  } while (0)
template <typename T>
void _cout(const T &c) {
  cerr << c;
}
void _cout(const int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else if (c == -1001001001)
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else
    cerr << c;
}
void _cout(const long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else if (c == -1001001001 || c == -((1LL << 61) - 1))
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else
    cerr << c;
}
template <typename T, typename U>
void _cout(const pair<T, U> &p) {
  cerr << "{ ";
  _cout(p.fi);
  cerr << ", ";
  _cout(p.se);
  cerr << " } ";
}
template <typename T>
void _cout(const vector<T> &v) {
  int s = v.size();
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } ";
}
template <typename T>
void _cout(const vector<vector<T>> &v) {
  cerr << "[ ";
  for (const auto &x : v) {
    cerr << endl;
    _cout(x);
    cerr << ", ";
  }
  cerr << endl << " ] ";
}
void dbg_out() { cerr << endl; }
template <typename T, class... U>
void dbg_out(const T &t, const U &... u) {
  _cout(t);
  if (sizeof...(u)) cerr << ", ";
  dbg_out(u...);
}
template <typename T>
void array_out(const T &v, int s) {
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } " << endl;
}
template <typename T>
void array_out(const T &v, int H, int W) {
  cerr << "[ ";
  for (int i = 0; i < H; i++) {
    cerr << (i ? ", " : "");
    array_out(v[i], W);
  }
  cerr << " ] " << endl;
}
#else
#define trc(...)
#define trca(...)
#define trcc(...)
#endif

inline int popcnt(unsigned long long a) { return __builtin_popcountll(a); }
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
template <typename T>
inline int getbit(T a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void setbit(T &a, int i) {
  a |= (1LL << i);
}
template <typename T>
inline void delbit(T &a, int i) {
  a &= ~(1LL << i);
}
template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int btw(T a, T x, T b) {
  return a <= x && x < b;
}
template <typename T, typename U>
T ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
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
template <typename T = int>
vector<T> mkiota(int N) {
  vector<T> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}
template <typename T>
vector<int> mkinv(vector<T> &v) {
  vector<int> inv(v.size());
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

void solve();
int main() { solve(); }

#pragma endregion
using namespace std;

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
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using namespace std;

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
    while (i >= (int)fac_.size()) extend();
    return fac_[i];
  }

  T finv(int i) {
    while (i >= (int)finv_.size()) extend();
    return finv_[i];
  }

  T inv(int i) {
    while (i >= (int)inv_.size()) extend();
    return inv_[i];
  }

  T C(int n, int r) {
    if (n < r || r < 0) return T(0);
    return fac(n) * finv(n - r) * finv(r);
  }

  T C_naive(int n, int r) {
    if (n < r || r < 0) return T(0);
    T ret = T(1);
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
    return ret;
  }

  T P(int n, int r) {
    if (n < r || r < 0) return T(0);
    return fac(n) * finv(n - r);
  }

  T H(int n, int r) {
    if (n < 0 || r < 0) return T(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

Binomial<mint> C;

void solve() {
  ini(N, m);
  vvi g(N), h(N);
  rep(i, m) {
    ini(u, v);
    --u, --v;
    g[u].pb(v);
    h[v].pb(u);
  }

  int ma = 24;

  {
    vvl d(N, vl(ma, infLL));
    auto comp = [&](P a, P b) {
      return d[a.first][a.second] > d[b.first][b.second];
    };
    priority_queue<P, vp, decltype(comp)> Q(comp);
    d[0][0] = 0;
    Q.emplace(0, 0);

    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      trc(c.first, c.second, d[c.first][c.second]);
      if (c.first == N - 1) break;
      ll cd = d[c.first][c.second];
      // tugi no ten
      if (c.second != ma - 1) {
        ll nd = 1 << c.second;
        nd += cd;
        if (d[c.first][c.second + 1] > nd) {
          d[c.first][c.second + 1] = nd;
          Q.emplace(c.first, c.second + 1);
        }
      }
      // tugi no ten
      auto& G = (c.second & 1) ? h : g;
      each(dst, G[c.first]) {
        if (d[dst][c.second] > cd + 1) {
          d[dst][c.second] = cd + 1;
          Q.emplace(dst, c.second);
        }
      }
    }
    trc(d);

    ll ans = infLL;
    rep(j, ma) amin(ans, d[N - 1][j]);
    if (ans != infLL) die(mint(ans));
  }

  {
    ll hv = (1LL << 30);
    vvl d(N, vl(2, infLL));

    auto comp = [&](P a, P b) {
      return d[a.first][a.second] > d[b.first][b.second];
    };
    priority_queue<P, vp, decltype(comp)> Q(comp);
    d[0][0] = 0;
    Q.emplace(0, 0);

    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      if (c.first == N - 1) break;
      ll cd = d[c.first][c.second];
      // tugi no ten
      {
        ll nd = cd + hv;
        if (d[c.first][c.second ^ 1] > nd) {
          d[c.first][c.second ^ 1] = nd;
          Q.emplace(c.first, c.second ^ 1);
        }
      }
      // tugi no ten
      auto& G = (c.second & 1) ? h : g;
      each(dst, G[c.first]) {
        if (d[dst][c.second] > cd + 1) {
          d[dst][c.second] = cd + 1;
          Q.emplace(dst, c.second);
        }
      }
    }
    trc(d);
    ll ans = infLL;
    rep(j, 2) amin(ans, d[N - 1][j]);

    ll x = ans >> 30;
    ll y = ans & ((1 << 30) - 1);

    // 2^x - 1
    mint bns = mint(2).pow(x) - 1 + mint(y);
    out(bns);
    return;
  }
}