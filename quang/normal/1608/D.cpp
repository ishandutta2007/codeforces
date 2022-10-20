#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <int MOD>
class Modular {
  static_assert(MOD > 0, "MOD must be positive");
  static_assert(MOD * 2 > 0, "MOD is too large for int");

 public:
  Modular() : v_(0) {}
  template <class T, typename enable_if<is_integral<T>::value>::type* = nullptr>
  explicit Modular(T v = 0) : v_((v %= MOD) < 0 ? v + MOD : v) {}

  Modular Inv() const { return Modular(Inverse(v_, MOD)); }

  template <class T, typename enable_if<is_integral<T>::value>::type* = nullptr>
  Modular Power(T v) const {
    Modular res(1), u(*this);
    if (v < 0) {
      v = -v;
      u = u.Inv();
    }
    for (; v; v >>= 1, u *= u)
      if (v & 1) res *= u;
    return res;
  }

  explicit operator int() const { return v_; }
  explicit operator bool() const { return static_cast<bool>(v_); }
  Modular& operator++() { return *this += Modular(1); }
  Modular& operator--() { return *this -= Modular(1); }
  Modular operator++(int) {
    Modular result(*this);
    *this += Modular(1);
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= Modular(1);
    return result;
  }
  Modular operator-() const { return Modular(-v_); }
  Modular operator+() const { return Modular(*this); }
  Modular& operator+=(const Modular& other) {
    if ((v_ += other.v_) >= MOD) v_ -= MOD;
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((v_ -= other.v_) < 0) v_ += MOD;
    return *this;
  }
  Modular& operator*=(const Modular& other) {
    v_ = 1ll * v_ * other.v_ % MOD;
    return *this;
  }
  Modular& operator/=(const Modular& other) { return *this *= other.Inv(); }

  friend bool operator==(const Modular& lhs, const Modular& rhs) {
    return lhs.v_ == rhs.v_;
  }
  friend bool operator!=(const Modular& lhs, const Modular& rhs) {
    return !(lhs == rhs);
  }
  friend Modular operator+(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) += rhs;
  }
  friend Modular operator-(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) -= rhs;
  }
  friend Modular operator*(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) *= rhs;
  }
  friend Modular operator/(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) /= rhs;
  }
  friend istream& operator>>(istream& in, Modular& number) {
    int64_t v;
    in >> v;
    number = Modular(v);
    return in;
  }
  friend ostream& operator<<(ostream& out, const Modular& number) {
    return out << int(number);
  }
  friend string to_string(const Modular& number) {
    return to_string(static_cast<int>(number));
  }

 private:
  // return u : a * u == 1 (mod m)
  // NOTE: CAN'T assume that 0 <= u < m
  static int Inverse(int a, int m) {
    assert(a && "Divide by zero");
    auto u = 0, v = 1;
    while (a) {
      auto t = m / a;
      m -= t * a;
      swap(a, m);
      u -= t * v;
      swap(u, v);
    }
    assert(m == 1 && "Can't find inversion");
    return u;
  }

  int v_;
};
constexpr int MOD = 998244353;
using Mint = Modular<MOD>;

class NTT {
 public:
  NTT() {
    max_base_ = __builtin_ctz(MOD - 1);
    auto root = Mint(2);
    while (root.Power(1 << max_base_) != Mint(1) ||
           root.Power(1 << max_base_ - 1) == Mint(1))
      root++;
    for (int i = 0; i < max_base_; i++, root *= root) roots_.push_back(root);
    reverse(roots_.begin(), roots_.end());
    rev_.resize(1 << max_base_);
    for (int i = 0; i < (1 << max_base_); i++)
      rev_[i] = (rev_[i >> 1] >> 1) + ((i & 1) << (max_base_ - 1));
  }

  void FFT(vector<Mint>& a, bool inverse) {
    auto n = static_cast<int>(a.size());
    assert(n == (n & -n) && "size of a is not a power of 2");
    auto base = n == 1 ? 0 : 32 - __builtin_clz(n - 1);
    assert(base <= max_base_ && "size of a is to large");
    auto shift = max_base_ - base;
    for (int i = 0; i < n; i++)
      if (i < (rev_[i] >> shift)) swap(a[i], a[rev_[i] >> shift]);
    for (int i = 0; i < base; i++)
      for (auto [j, w] = pair(0, Mint(1)); j < 1 << i; j++, w *= roots_[i])
        for (int k = j; k < n; k += 2 << i) {
          auto u = a[k];
          auto v = a[k + (1 << i)] * w;
          a[k] = u + v;
          a[k + (1 << i)] = u - v;
        }
    if (inverse) {
      reverse(a.begin() + 1, a.end());
      auto inv_n = Mint(n).Inv();
      for (auto& u : a) u *= inv_n;
    }
  }

  vector<Mint> Mult(vector<Mint> a, vector<Mint> b) {
    if (a.empty() || b.empty()) return {};
    auto n = static_cast<int>(a.size() + b.size()) - 1;
    auto cur_base = n == 1 ? 0 : 32 - __builtin_clz(n - 1);
    a.resize(1 << cur_base), b.resize(1 << cur_base);
    FFT(a, false);
    FFT(b, false);
    for (int i = 0; i < 1 << cur_base; i++) a[i] *= b[i];
    FFT(a, true);
    a.resize(n);
    return a;
  }

 private:
  int max_base_;
  vector<Mint> roots_;  // 0: -1, 1: i, ...
  vector<int> rev_;
};

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &u : a) {
    cin >> u;
    if (u[0] != '?') {
      if (u[0] == 'W') u[0] = 'B';
      else u[0] = 'W';
    }
  }
  vector<int> cnt(6);

  // 0: 0 1
  // 1: -1 0
  // 2: -1 0 1
  // 3: 1
  // 4: -1
  // 5: 0
  for (const auto &u : a) {
    if (u == "B?" || u == "?W") {
      cnt[0]++;
    }
    if (u == "W?" || u == "?B") {
      cnt[1]++;
    }
    if (u == "??") {
      cnt[2]++;
    }
    if (u == "BW") {
      cnt[3]++;
    }
    if (u == "WB") {
      cnt[4]++;
    }
    if (u == "BB" || u == "WW") {
      cnt[5]++;
    }
  }

  NTT ntt;

  auto Power = [&](vector<Mint> a, int v) {
    vector<Mint> res(1, Mint(1));
    while (v) {
      if (v & 1) {
        res = ntt.Mult(res, a);
      }
      a = ntt.Mult(a, a);
      v >>= 1;
    }
    return res;
  };

  vector<Mint> res(1, Mint(1));

  vector<Mint> x;

  x = {Mint(0), Mint(1), Mint(1)};
  x = Power(x, cnt[0]);
  res = ntt.Mult(res, x);

  x = {Mint(1), Mint(1), Mint(0)};
  x = Power(x, cnt[1]);
  res = ntt.Mult(res, x);

  x = {Mint(1), Mint(2), Mint(1)};
  x = Power(x, cnt[2]);
  res = ntt.Mult(res, x);

  x = {Mint(0), Mint(0), Mint(1)};
  x = Power(x, cnt[3]);
  res = ntt.Mult(res, x);

  x = {Mint(1), Mint(0), Mint(0)};
  x = Power(x, cnt[4]);
  res = ntt.Mult(res, x);

  x = {Mint(0), Mint(1), Mint(0)};
  x = Power(x, cnt[5]);
  res = ntt.Mult(res, x);

  assert(res.size() > n);
  Mint all_equal(1);
  for (auto &u : a) {
    if (u == "??") {
      all_equal = all_equal + all_equal;
    }
    if (u == "BW") {
      all_equal = Mint(0);
    }
    if (u == "WB") {
      all_equal = Mint(0);
    }
  }

  Mint all_zero(1);
  for (auto &u : a) {
    for (auto &v : u) {
      if (v == 'W') {
        all_zero = Mint(0);
      }
    }
  }
  Mint all_one(1);
  for (auto &u : a) {
    for (auto &v : u) {
      if (v == 'B') {
        all_one = Mint(0);
      }
    }
  }
  // debug(res);
  // debug(all_equal, all_zero, all_one);
  cout << res[n] - all_equal + all_zero + all_one << '\n';
  return 0;
}