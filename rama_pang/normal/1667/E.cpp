#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD;
  }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt &operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) {
    return (*this) *= inverse(a);
  }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1;
    assert(x >= 0);
    for (; x; x /= 2, a *= a)
      if (x & 1) res *= a;
    return res;
  }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream &operator>>(istream &is, ModInt &v) {
    is >> v.v;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &v) {
    os << v.v;
    return os;
  }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

void Main() {
  int n;
  cin >> n;
  if (0) {
  vector<int> p(n, -1);
  vector<int> ret(n);
  const auto Check = [&]() {
    vector<int> s(n);
    for (int i = n - 1; i >= 0; i--) {
      s[i] += 1;
      if (p[i] != -1) {
        s[p[i]] += s[i];
      }
    }
    pair<int, int> sz = {1e9, 1e9};
    for (int i = 0; i < n; i++) {
      if (s[i] > (n - 1) / 2) {
        sz = min(sz, {s[i], i});
      }
    }    
    ret[sz.second] += 1;
    return;
  };
  const auto Dfs = [&](const auto &self, int pos) {
    if (pos == n) return Check();
    for (int i = 0; i < pos; i++) {
      p[pos] = i;
      self(self, pos + 1);
    }
  };
  Dfs(Dfs, 1);
  int hh = 1;
  for (int i = 1; i <= (n - 1)/2; i++) hh *= i;
  for (int i = 0; i < n; i++) {
    assert(ret[i] % hh == 0);
    cout << ret[i] / hh << " \n"[i + 1 == n];
  }
  }

  {
    vector<Mint> ans(n);
    vector<Mint> fact(n + 5);
    fact[0] = 1;
    for (int i = 1; i < n + 5; i++) {
      fact[i] = i * fact[i - 1];
    }
    const auto Choose = [&](int n, int k) {
      if (k < 0 || k > n) return Mint(0);
      return fact[n] / fact[k] / fact[n - k];
    };
    int H = n / 2;
    for (int k = H; k >= 1; k--) {
      Mint cur = Mint(k) / Mint(k + 1) * Choose(2 * H - k - 1, H - k);
      if (k + 1 <= H) ans[k] = 1 * ans[k + 1];
      ans[k] += cur;
    }
    ans[0] = ans[1];
    for (int k = 0; k <= H; k++) {
      ans[k] *= fact[H + 1];
      ans[k] /= H;
      ans[k] *= fact[H];
    }
    for (int k = 0; k < n; k++) {
      cout << ans[k] << ' ';
    }
    cout << '\n';
    // ans[0] = 0;
    // for (int k = 3; k <= H; k++) {
    //   ans[0] += ;
    // }

    // cout << ans[0] << '\n';
  }
  // ret[(n - 1) / 2] = (n - 1)/2! ** 2
  // 24*24
  // 
  // ans[H] = H! * H!
  // ans[H - 1] = H! * ((H + 1)! - (H - 1)!)
  // ans[0] = ans[1] = (H+1)! * sum(k=1...H)(k/k+1 * binom(2H - k - 1, H - k)) / H
  // 
  // = 24 * (binom(6 - 2, 2) + 2 binom(6 - 3, 3) + 3 binom(6 - 4, 4)) / 3
  // = 24 * (6 + 2 * 1 + 3 * 0)

  // H! * ((H + 2)! - (H - 2)!)
  // 
  // 
  // 1 2 6 24 120 720 5040
  // 1 2 12 144 2880
  // 1 3 9 

  // 1, 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    Main();
  }
  return 0;
}