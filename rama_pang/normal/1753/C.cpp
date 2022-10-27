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
// using Mint = double;
void Main() {
  int n;
  cin >> n;
  vector<int> cnt(2);  
  vector<int> a(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  if (cnt[0] == 0 || cnt[1] == 0) {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < cnt[0]; i++) {
    cur += a[i] == 0;
  }
  vector<array<Mint, 2>> eq(cnt[0] + 1);
  eq[cnt[0]] = {0, 0};
  for (int i = cnt[0] - 1; i >= 0; i--) {
    Mint lft0 = i;
    Mint lft1 = cnt[0] - i;
    Mint rgt0 = cnt[0] - lft0;
    Mint rgt1 = cnt[1] - lft1;
    Mint wayNone = Mint(cnt[0]) * Mint(cnt[0] - 1) / 2 + Mint(cnt[1]) * Mint(cnt[1] - 1) / 2;
    wayNone += lft0 * rgt0;
    wayNone += lft1 * rgt1;
    wayNone += lft0 * rgt1;
    Mint wayPlus = lft1 * rgt0;
    wayNone /= Mint(n) * Mint(n - 1) / 2;
    wayPlus /= Mint(n) * Mint(n - 1) / 2;
    // (1 - wayNone) E[x] = 1 + wayPlusE[x + 1]
    if (wayNone != 1) {
      for (int j = 0; j < 2; j++) {
        eq[i][j] = wayPlus * eq[i + 1][j] + int(j == 0);
        eq[i][j] /= 1 - wayNone;
      }
    } else {
      break;
    }
    // // E[x] = 1 + wayNone * (E[x]) + wayPlus * (E[x + 1]) + wayMinus * (E[x - 1])
    // // (1 - wayNone) E[x] = 1 + wayPlus E[x + 1] + wayMinus E[x - 1]
    // // E[x - 1] = (1 - wayNone) E[x] - 1 - wayPlus E[x + 1] / wayMinus    
    // // cout << i << ' ' << wayPlus << ' ' << wayMinus << ' ' << wayNone << endl;
    // if (wayMinus != 0) {
    //   for (int j = 0; j < 2; j++) {
    //     eq[i - 1][j] = (1 - wayNone) * eq[i][j] - wayPlus * eq[i + 1][j] - int(j == 0);
    //     eq[i - 1][j] /= wayMinus;
    //   }
    // } else {
    //   // (1 - wayNone) E[x] = 1 + wayPlus E[x + 1]
    //   array<Mint, 2> sp, sp2;
    //   for (int j = 0; j < 2; j++) {
    //     sp[j] = int(j == 0) + wayPlus * eq[i + 1][j];
    //     sp2[j] = (1 - wayNone) * eq[i][j];
    //   }
    //   // cout << sp[0] << ' ' << sp[1] << '\n';
    //   // cout << sp2[0] << ' ' << sp2[1] << '\n';
    //   // return;
    //   Mint x = (sp2[0] - sp[0]) / (sp[1] - sp2[1]);
    //   // cout << x << '\n';
    //   // cout << eq[cur][0] << '\n';
    //   // cout << eq[cur][1] << '\n';
    //   // cout << eq[cur][0] + eq[cur][1] * x << '\n';
    //   cout << eq[1][0] + eq[1][1] * x << '\n';
    //   break;
    // }
  }
  cout << eq[cur][0] << '\n';
  // cout << dp[cur] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
/*
0
26.25 = 1 + 11/15 * 26.25 + 3/15 * 30
30 = 

*/