#include <bits/stdc++.h>
using namespace std;
void solve();
int main() { solve(); }

static constexpr uint32_t get_r(int mod) {
  uint64_t ret = 1, m = mod, n = mod - 2;
  while (n) {
    ret = uint32_t(ret * m);
    m = uint32_t(m * m);
    n >>= 1;
  }
  return ret;
};

template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 r = get_r(mod);
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 a;

  LazyMontgomeryModInt() : a(0) {}
  LazyMontgomeryModInt(const int64_t &b) : a(reduce(u64(b % mod + mod) * n2)){};

  static u32 reduce(const u64 &b) {
    return u32(b >> 32) + mod - u32((u64(u32(b) * r) * mod) >> 32);
  }

  mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }

  u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }

  mint inverse() const { return pow(mod - 2); }

  static constexpr u32 get_mod() { return mod; }
};

static constexpr uint32_t get_pr(uint32_t mod) {
  using u64 = uint64_t;
  u64 ds[32] = {};
  int idx = 0;
  u64 m = mod - 1;
  for (u64 i = 2; i * i <= m; ++i) {
    if (m % i == 0) {
      ds[idx++] = i;
      while (m % i == 0) m /= i;
    }
  }
  if (m != 1) ds[idx++] = m;

  uint32_t pr = 2;
  while (1) {
    int flg = 1;
    for (int i = 0; i < idx; i++) {
      u64 a = pr, b = (mod - 1) / ds[i], r = 1;
      while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
      }
      if (r == 1) {
        flg = 0;
        break;
      }
    }
    if (flg == 1) break;
    ++pr;
  }
  return pr;
};

template <typename mint>
struct NTT {
  static constexpr uint32_t mod = mint::get_mod();
  static constexpr uint32_t pr = get_pr(mod);
  static constexpr int level = __builtin_ctzll(mod - 1);
  mint dw[level], dy[level];

  void setwy(int k) {
    mint w[level], y[level];
    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
    y[k - 1] = w[k - 1].inverse();
    for (int i = k - 2; i > 0; --i)
      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
    for (int i = 3; i < k; ++i) {
      dw[i] = dw[i - 1] * y[i - 2] * w[i];
      dy[i] = dy[i - 1] * w[i - 2] * y[i];
    }
  }

  void fft4(vector<mint> &a, int k) {
    if (k & 1) {
      int v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        mint ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] += ajv;
      }
    }
    int u = 1 << (2 + (k & 1));
    int v = 1 << (k - 2 - (k & 1));
    mint one = mint(1);
    mint imag = dw[1];
    while (v) {
      // jh = 0
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      // jh >= 1
      mint ww = one, xx = one * dw[2], wx = one;
      for (int jh = 4; jh < u;) {
        ww = xx * xx, wx = ww * xx;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for (; j0 < je; ++j0, ++j2) {
          mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww,
               t3 = a[j2 + v] * wx;
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;
        }
        xx *= dw[__builtin_ctzll((jh += 4))];
      }
      u <<= 2;
      v >>= 2;
    }
  }

  void ifft4(vector<mint> &a, int k) {
    int u = 1 << (k - 2);
    int v = 1;
    mint one = mint(1);
    mint imag = dy[1];
    while (u) {
      // jh = 0
      {
        int j0 = 0;
        int j1 = v;
        int j2 = v + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;
          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
        }
      }
      // jh >= 1
      mint ww = one, xx = one * dy[2], yy = one;
      u <<= 2;
      for (int jh = 4; jh < u;) {
        ww = xx * xx, yy = xx * imag;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for (; j0 < je; ++j0, ++j2) {
          mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;
        }
        xx *= dy[__builtin_ctzll(jh += 4)];
      }
      u >>= 4;
      v <<= 2;
    }
    if (k & 1) {
      u = 1 << (k - 1);
      for (int j = 0; j < u; ++j) {
        mint ajv = a[j] - a[j + u];
        a[j] += a[j + u];
        a[j + u] = ajv;
      }
    }
  }

  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    int l = a.size() + b.size() - 1;
    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
#ifdef NyaanDebug
    assert(k <= level);
#endif
    setwy(k);
    vector<mint> s(M), t(M);
    for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
    fft4(s, k);
    fft4(t, k);
    for (int i = 0; i < M; ++i) s[i] *= t[i];
    ifft4(s, k);
    s.resize(l);
    mint invm = mint(M).inverse();
    for (int i = 0; i < l; ++i) s[i] *= invm;
    return s;
  }
};

// LazyMontgomeryModInt2^24
namespace ArbitaryNTT {
constexpr int32_t m0 = 167772161;
constexpr int32_t m1 = 469762049;
constexpr int32_t m2 = 754974721;
using mint0 = LazyMontgomeryModInt<m0>;
using mint1 = LazyMontgomeryModInt<m1>;
using mint2 = LazyMontgomeryModInt<m2>;

// modint
template <typename submint, typename mint>
vector<submint> mul(const vector<mint> &a, const vector<mint> &b) {
  int l = a.size() + b.size() - 1;
  int k = 2, M = 4;
  while (M < l) M <<= 1, ++k;
  NTT<submint> ntt;
  vector<submint> s(M), t(M);
  for (int i = 0; i < (int)a.size(); ++i) {
    s[i].a = submint::reduce(uint64_t(a[i].a) * submint::n2);
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    t[i].a = submint::reduce(uint64_t(b[i].a) * submint::n2);
  }
  ntt.setwy(k);
  ntt.fft4(s, k);
  ntt.fft4(t, k);
  for (int i = 0; i < M; ++i) s[i] *= t[i];
  ntt.ifft4(s, k);
  s.resize(l);
  submint invm = submint(M).inverse();
  for (int i = 0; i < l; ++i) s[i] *= invm;
  return s;
}
template <typename mint>
vector<mint> multiply(const vector<mint> &s, const vector<mint> &t) {
  auto d0 = mul<mint0>(s, t);
  auto d1 = mul<mint1>(s, t);
  auto d2 = mul<mint2>(s, t);
  int n = d0.size();
  vector<mint> res(n);
  using i64 = int64_t;
  static const int r01 = mint1(m0).inverse().get();
  static const int r02 = mint2(m0).inverse().get();
  static const int r12 = mint2(m1).inverse().get();
  static const int r02r12 = i64(r02) * r12 % m2;
  static const int w1 = m0 % mint::get_mod();
  static const int w2 = i64(w1) * m1 % mint::get_mod();
  // reducemod * 2^32
  // a + b * w1 + c * w2
  // <= (m0-1) + (m1-1)*(mod-1) + (m2-1)*(mod-1)
  // = (m0-1) + (m1+m2-2)*(mod-1)
  // < 2^32+2^32*(mod-1) = 2^32*mod
  // for5mod
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    res[i].a = mint::reduce(a + b * w1 + c * w2);
  }
  return res;
}

template <class submint, typename T>
std::enable_if_t<std::is_integral<T>::value, vector<submint>> int_friendly_mul(
    const vector<T> &a, const vector<T> &b) {
  int l = a.size() + b.size() - 1;
  int k = 2, M = 4;
  while (M < l) M <<= 1, ++k;
  NTT<submint> ntt;
  vector<submint> s(M), t(M);
  for (int i = 0; i < (int)a.size(); ++i) {
    s[i].a = submint::reduce(uint64_t(a[i]) * submint::n2);
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    t[i].a = submint::reduce(uint64_t(b[i]) * submint::n2);
  }
  ntt.setwy(k);
  ntt.fft4(s, k);
  ntt.fft4(t, k);
  for (int i = 0; i < M; ++i) s[i] = s[i] * t[i];
  ntt.ifft4(s, k);
  s.resize(l);
  submint invm = submint(M).inverse();
  for (int i = 0; i < l; ++i) s[i] *= invm;
  return s;
}

// require 0 <= s[i] , t[i] < 2 ^ 32 
template <class T>
std::enable_if_t<std::is_integral<T>::value, vector<int64_t>>
int_friendly_multiply(const vector<T> &s, const vector<T> &t, int64_t mod) {
  auto d0 = int_friendly_mul<mint0, T>(s, t);
  auto d1 = int_friendly_mul<mint1, T>(s, t);
  auto d2 = int_friendly_mul<mint2, T>(s, t);
  int n = d0.size();
  vector<int64_t> res(n);
  using i64 = int64_t;
  static const int r01 = mint1(m0).inverse().get();
  static const int r02 = mint2(m0).inverse().get();
  static const int r12 = mint2(m1).inverse().get();
  static const int r02r12 = i64(r02) * r12 % m2;
  static const int64_t w1 = m0 % mod;
  static const int64_t w2 = i64(w1) * m1 % mod;
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    res[i] = (a + b * w1 + c * w2) % mod;
  }
  return res;
}

}  // namespace ArbitaryNTT
using ArbitaryNTT::int_friendly_multiply;
using ArbitaryNTT::multiply;

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

void solve() {
  int N, M, MOD;
  cin >> N >> M >> MOD;
  vector<int64_t> a(N), b(M);
  for (int i = 0; i < N; ++i) cin >> a[i];
  for (int i = 0; i < M; ++i) cin >> b[i];
  auto c = int_friendly_multiply(a, b, MOD);
  for (int i = 0; i < M + N - 1; i++) {
    if (c[i] % MOD != 0) {
      cout << i << '\n';
      return;
    }
  }
}