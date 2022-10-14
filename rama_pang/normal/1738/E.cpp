#include <bits/stdc++.h>
using namespace std;

using lint = long long;

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

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  int n = 10;
  cin >> n;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = rnd() % 3;
    cin >> a[i];
    // cout << a[i] << " \n"[i + 1 == n];
  }

  if (0) cout << [&]() -> int {
    int ans = 0;
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
      lint s = 0;
      vector<lint> ha;
      for (int i = 0; i < n; i++) {
        s += a[i];
        if ((mask >> i) & 1) {
          ha.emplace_back(s);
          s = 0;
        }
      }
      ha.emplace_back(s);
      auto ra = ha;
      reverse(begin(ra), end(ra));
      if (ha == ra) ans++;
    }
    return ans;
  }() << " Brute\n";

  if (a == vector<lint>(n, 0)) {
    cout << pow(Mint(2), n - 1) << '\n';
    return;
  }
  vector<int> ids;
  int pf = 0, sf = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      ids.emplace_back(i);
    }
  }
  vector<Mint> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = i * fac[i - 1];
  const auto C = [&](int n, int k) {
    if (k < 0 || k > n) return Mint(0);
    return fac[n] / fac[k] / fac[n - k];
  };
  const auto Ways = [&](int x, int y) -> Mint {
    Mint ret = 0;
    for (int k = 0; k <= min(x, y) + 1; k++) {
      ret += C(x + 1, k) * C(y + 1, k);
    }
    return ret;
  };
  Mint ans = 1;
  {
    int i = 0, j = ids.size();
    lint sumPref = a[ids[0]];
    lint sumSuff = 0;
    while (i < j) {
      if (sumPref > sumSuff) {
        j--;
        sumSuff += a[ids[j]];
      } else if (sumPref < sumSuff) {
        i++;
        sumPref += a[ids[i]];
      }
      if (i < j && sumPref == sumSuff) {
        // [0, i] = [j, n-1]
        if (i + 1 == j) {
          Mint w = 0;
          int len = ids[i + 1] - ids[i] - 1;
          for (int x = 0; x <= len + 1; x++) {
            w += C(len + 1, x);
          }
          ans *= w;
        } else {
          int lena = ids[i + 1] - ids[i] - 1;
          int lenb = ids[j] - ids[j - 1] - 1;
          ans *= Ways(lena, lenb);
        }
        i++;
        sumPref += a[ids[i]];
      }
    }
  }
  while (a.back() == 0) {
    sf++;
    a.pop_back();
  }
  reverse(begin(a), end(a));
  while (a.back() == 0) {
    pf++;
    a.pop_back();
  }
  if (pf > 0 && sf > 0) {
    ans *= Ways(pf - 1, sf - 1);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}