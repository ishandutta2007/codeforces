#include <bits/stdc++.h>  // clang-format off
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)

#ifdef ONLINE_JUDGE
  #define rep(i,N) for(int i = 0; i < (int)(N); i++)
  #define repr(i,N) for(int i = (int)(N) - 1; i >= 0; i--)
  #define rep1(i,N) for(int i = 1; i <= (int)(N) ; i++)
  #define repr1(i,N) for(int i = (N) ; (int)(i) > 0 ; i--)
#else
  #define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
  #define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
  #define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
  #define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#endif

using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); for(int i=0;i<s;i++) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}

#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);} while(0)
  #define trcc(v) do { cerr << "name : " << #v << "\n"; int cnt = 0; each(x , v){cerr << (cnt++) << " : "; trc(x); } } while(0)
#else
  #define trc(...)
  #define trca(...)
  #define trcc(...)
  int main(){solve();}
#endif

#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define in2(s,t)     rep(i,sz(s)){in(s[i] , t[i]);}
#define in3(s,t,u)   rep(i,sz(s)){in(s[i] , t[i] , u[i]);}
#define in4(s,t,u,v) rep(i,sz(s)){in(s[i] , t[i] , u[i] , v[i]);}
using vd = V<double>; using vs = V<string>; using vvl = V< V<> >;
template<typename T,typename U>ll ceil(T a,U b){return (a + b - 1) / b;}

using P = pair<int,int>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
// clang-format on
///////////////////////////////////////////////////////////

template <typename T, typename F>
struct ST {
  int size;
  vector<T> seg;
  const F func;
  const T UNIT;

  ST(int N, F func, T UNIT) : func(func), UNIT(UNIT) {
    size = 1;
    while (size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
  }

  ST(const vector<T> &v, F func, T UNIT) : func(func), UNIT(UNIT) {
    // initialize
    int N = (int)v.size();
    size = 1;
    while (size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
    // set
    for (int i = 0; i < N; i++) {
      seg[i + size] = v[i];
    }
    build();
  }

  void set(int k, T x) { seg[k + size] = x; }

  void build() {
    for (int k = size - 1; k > 0; k--) {
      seg[k] = func(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void update(int k, T x) {
    k += size;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = func(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void add(int k, T x) {
    k += size;
    seg[k] += x;
    while (k >>= 1) {
      seg[k] = func(seg[2 * k], seg[2 * k + 1]);
    }
  }

  // query to [a, b)
  T query(int a, int b) {
    T L = UNIT, R = UNIT;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = func(L, seg[a++]);
      if (b & 1) R = func(seg[--b], R);
    }
    return func(L, R);
  }

  T &operator[](const int &k) { return seg[k + size]; }
};

template <class T, int H, int W>
struct Matrix {
  using Array = array<array<T, W>, H>;
  Array A;

  Matrix() : A({}) {}

  int height() const { return H; }

  int width() const { return W; }

  inline const array<T, W> &operator[](int k) const { return A[k]; }

  inline array<T, W> &operator[](int k) { return A[k]; }

  static Matrix I() {
    assert(H == W);
    Matrix mat;
    for (int i = 0; i < H; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    assert(H == W);
    Matrix C;
    for (int i = 0; i < H; i++)
      for (int j = 0; j < H; j++)
        for (int k = 0; k < H; k++)
          C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    A.swap(C.A);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I();
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    for (int i = 0; i < H; i++) {
      os << "[";
      for (int j = 0; j < W; j++) {
        os << p[i][j] << (j + 1 == W ? "]\n" : ",");
      }
    }
    return (os);
  }

  T determinant() {
    Matrix B(*this);
    assert(H == W);
    T ret = 1;
    for (int i = 0; i < H; i++) {
      int idx = -1;
      for (int j = i; j < W; j++) {
        if (B[j][i] != 0) idx = j;
      }
      if (idx == -1) return (0);
      if (i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for (int j = 0; j < W; j++) {
        B[i][j] /= vv;
      }
      for (int j = i + 1; j < H; j++) {
        T a = B[j][i];
        for (int k = 0; k < W; k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
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
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< MOD >;
using vm = vector<modint>;
using mint = modint;

void solve() {
  constexpr int S = 100;
  using mat = Matrix<mint , S , S>;
  inl(N , M);
  if(N < M) die(1);
  mat m;
  m[0][0] = m[0][M - 1] = 1;
  for(int i = 1 ; i < M ; i++) m[i][i - 1] = 1;
  m = m ^ (N - M + 1);
  mint ans = 0;
  rep(i , M) ans += m[0][i];
  out(ans);

}