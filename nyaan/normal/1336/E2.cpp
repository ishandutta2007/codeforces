#pragma region kyopro_template
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
using namespace std;
void solve();
using ll = long long;
template <class T = ll>
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
ll ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr ll TEN(int n) {
  ll ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
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
template <typename T>
void die(T x) {
  out(x);
  exit(0);
}

#ifdef NyaanDebug
#include "NyaanDebug.h"
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
#else
#define trc(...)
#define trca(...)
#define trcc(...)
int main() { solve(); }
#endif

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

#pragma endregion

constexpr long long MOD = /** 1000000007;  //*/ 998244353;

// popcount
inline int popcount(unsigned long long a) { return __builtin_popcountll(a); }
// least significant bit
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
// most significant bit
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
// get i-th bit
template <typename T>
inline int getbit(T a, int i) {
  return (a >> i) & 1;
}
// set i-th bit
template <typename T>
inline void setbit(T &a, int i) {
  a |= (1LL << i);
}
// delete i-th bit
template <typename T>
inline void delbit(T &a, int i) {
  a &= ~(1LL << i);
}

// lower_bound
template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
// upper_bound
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}

// cumulative sum
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};

// order
template <typename T>
vector<int> mkord(const vector<T> &v, function<bool(T, T)> f) {
  vector<int> ord(v.size());
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}

// unique
template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

template <int mod>
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }

  static constexpr int get_mod() { return mod; }
};
using mint = ModInt<MOD>;
using vm = vector<mint>;

template <size_t N>
bitset<N> gcd(bitset<N> x, bitset<N> y) {
  int xm = int(N) - 1, ym = int(N) - 1;
  while (xm != -1 && x[xm] == 0) xm--;
  while (ym != -1 && y[ym] == 0) ym--;
  if (xm < ym) swap(x, y), swap(xm, ym);
  while (ym >= 0) {
    x ^= y << (xm - ym);
    while (xm != -1 && x[xm] == 0) xm--;
    while (ym != -1 && y[ym] == 0) ym--;
    if (xm < ym) swap(x, y), swap(xm, ym);
  }
  return x;
}

template <size_t MAX_H, size_t MAX_W>
struct BitMat {
  int H, W;
  bitset<MAX_W> a[MAX_H];
  BitMat(int h, int w) : H(h), W(w) {}
  inline bitset<MAX_W> &operator[](int i) { return a[i]; }
};

template <size_t MAX_H, size_t MAX_W>
int Gauss(BitMat<MAX_H, MAX_W> &A, bool is_greater = true,
          bool is_extended = false) {
  int rank = 0, H = A.H, W = (is_extended ? A.W - 1 : A.W);
  for (int j = (is_greater ? W - 1 : 0); j != (is_greater ? -1 : W);
       j += (is_greater ? -1 : 1)) {
    for (int i = rank; i < H; i++) {
      if (A[i][j] == 1) {
        swap(A[rank], A[i]);
        for (int k = 0; k < H; k++) {
          if (k != rank && A[k][j]) A[k] ^= A[rank];
        }
        rank++;
        break;
      }
    }
  }
  if (is_extended) {
    for (int i = rank; i < H; i++)
      if (A[i][W] == 1) return -1;
  }
  return rank;
}

template <size_t MAX_H, size_t MAX_W>
void OrthogonalComplement(BitMat<MAX_H, MAX_W> &A, int N) {
  int rank = 0;
  while (rank < N && A[rank].any()) rank++;
  for (int i = 0; i < rank; i++) {
    int j = A[i]._Find_first();
    if (j != i)
      for (int k = 0; k < rank; k++) {
        int buf = A[k][i];
        A[k][i] = A[k][j];
        A[k][j] = buf;
      }
  }
  for (int i = rank; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = (j < rank ? A[j][i] : i == j);
    }
  }
}

vector<ll> fac, finv, inv;
void cominit(int MAX) {
  MAX++;
  fac.resize(MAX, 0);
  finv.resize(MAX, 0);
  inv.resize(MAX, 0);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
// nCk combination
inline long long COM(int n, int k) {
  if (n < k || k < 0 || n < 0)
    return 0;
  else
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// nPk permutation
inline long long PER(int n, int k) {
  if (n < k || k < 0 || n < 0)
    return 0;
  else
    return (fac[n] * finv[n - k]) % MOD;
}
// nHk homogeneous polynomial
inline long long HGP(int n, int k) {
  if (n == 0 && k == 0)
    return 1;  // depending on problem?
  else if (n < 1 || k < 0)
    return 0;
  else
    return fac[n + k - 1] * (finv[k] * finv[n - 1] % MOD) % MOD;
}

void solve() {
  ini(N, M);
  vl a(N);
  in(a);
  BitMat<200200, 64> mat(N, 64);
  rep(i, N) mat[i] = a[i];
  int rank = Gauss(mat, false);
  if (rank <= 27) {
    vl b(rank);
    rep(i, rank) b[i] = mat[i].to_ullong();
    vm ans(M + 1);
    auto dfs = [&](auto rec, ll i, ll cur) -> void {
      if (i == rank) {
        ans[popcount(cur)] += 1;
        return;
      }
      rec(rec, i + 1, cur);
      rec(rec, i + 1, cur ^ b[i]);
    };
    dfs(dfs, 0, 0);
    mint rest = mint(2).pow(N - rank);
    each(x, ans) x *= rest;
    out(ans);
    return;
  }
  //
  cominit(2000);
  OrthogonalComplement(mat, M);
  vl b(M);
  rep(i, M) b[i] = mat[i].to_ullong();
  vm cnt(M + 1);
  auto dfs = [&](auto rec, ll i, ll cur) -> void {
    if (i == M) {
      cnt[popcount(cur)] += 1;
      return;
    }
    rec(rec, i + 1, cur);
    rec(rec, i + 1, cur ^ b[i]);
  };
  dfs(dfs, rank, 0);

  vm ans(M + 1);
  rep(l, M + 1) rep(k, M + 1) rep(j, M + 1) {
    mint n = mint(COM(l, j)) * COM(M - l, k - j);
    ans[k] += cnt[l] * (j & 1 ? -n : n);
  }
  mint rest=mint(2).pow(N)/mint(2).pow(M);
  each(x,ans)x*=rest;
  out(ans);
}