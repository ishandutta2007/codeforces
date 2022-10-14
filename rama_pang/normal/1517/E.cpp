#include <bits/stdc++.h>
using namespace std;

template<int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD; }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt& operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this; }
  ModInt& operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this; }
  ModInt& operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this; }
  ModInt& operator/=(const ModInt &a) {
    return (*this) *= inverse(a); }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1; assert(x >= 0);
    for (; x; x /= 2, a *= a) if (x & 1) res *= a;
    return res; }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2); }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream& operator>>(istream &is, ModInt &v) { is >> v.v; return is; }
  friend ostream& operator<<(ostream &os, const ModInt &v) { os << v.v; return os; }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

using lint = long long;
const lint INF = 1e18;

void Main() {
  lint N;
  cin >> N;
  vector<lint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  if (N == 1) {
    cout << 1 << '\n';
    return;
  }

  if (N <= 3) {
    int cnt = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
      vector<int> a, b;
      for (int i = 0; i < N; i++) {
        if ((mask >> i) & 1) {
          b.emplace_back(i);
        } else {
          a.emplace_back(i);
        }
      }
      int bad = 0;
      for (int i = 1; i + 1 < a.size(); i++) {
        if (a[i] - a[i - 1] <= a[i + 1] - a[i]) continue;
        bad = 1;
      }
      for (int i = 1; i + 1 < b.size(); i++) {
        if (b[i] - b[i - 1] >= b[i + 1] - b[i]) continue;
        bad = 1;
      }
      if (!bad) {
        lint suma = 0, sumb = 0;
        for (auto i : a) suma += A[i];
        for (auto i : b) sumb += A[i];
        if (suma < sumb) {
          cnt += 1;
        }
      }
    }

    cout << cnt << '\n';
    return;
  }

  lint sumAll = 0;
  for (int i = 0; i < N; i++) {
    sumAll += A[i];
  }
  lint limit = (sumAll - 1) / 2;

  Mint ans = 0;
  lint sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    if (i + 1 == N && sum <= limit) ans += 1;
    if (sumAll - sum <= limit) ans += 1;
  }

  // Pattern:
  // ("0" or "1") + "0..00" + "101010..." + "1111.." + ("1" or "0")

  const auto Solve = [&](vector<lint> A, lint L) -> Mint {
    vector<lint> pref = A;
    for (int i = 2; i < A.size(); i++) {
      pref[i] += pref[i - 2];
    }
    Mint ans = 0;
    lint init = 0;
    for (int i = 0; i <= A.size(); i++) {
      // binary search
      lint atmost = L - init;

      int lo = -1, hi = A.size();
      while (lo < hi) {
        int md = (lo + hi + 1) >> 1;
        int j = i + 2 * md;
        if (j > A.size()) {
          hi = md - 1;
          continue;
        }
        lint p = (j > 0 ? pref[j - 1] : 0) - (i > 0 ? pref[i - 1] : 0);
        if (p <= atmost) {
          lo = md;
        } else {
          hi = md - 1;
        }
      }
      ans += lo + 1;
      
      // for (int j = i; j <= A.size(); j += 2) { // [i, j) = "10"...
      //   lint p = (j > 0 ? pref[j - 1] : 0) - (i > 0 ? pref[i - 1] : 0);
      //   // cout << i << ' ' << j << ' ' << p << " huh?\n";
      //   if (p <= atmost) {
      //     ans += 1;
      //   }
      // }
      

      // A[0...i] = "0"
      // A[i...] = "10"...


      if (i == A.size()) break;
      init += A[i];
    }
    return ans;
  };

  set<vector<int>> done;
  for (int f0 = 0; f0 <= 1; f0++) {
    for (int f1 = 0; f1 <= 1; f1++) {
      vector<int> F(N);
      if (f0 == 1) { // start with "10"
        F[0] |= 1 << 1;
        F[1] |= 1 << 0;
      } else { // start with "0"
        F[0] |= 1 << 0;
      }
      if (f1 == 0) { // end with "10"
        F[N - 2] |= 1 << 1;
        F[N - 1] |= 1 << 0;
      } else { // end with "1"
        F[N - 1] |= 1 << 1;
      }
      if (count(begin(F), end(F), 3)) {
        continue;
      }
      vector<lint> a;
      lint L = limit;
      for (int i = 0; i < N; i++) {
        if (F[i] == 0) {
          a.emplace_back(A[i]);
        }
        if (F[i] == 1) {
          L -= A[i];
        }
      }
      if (done.count(F) == 0) {
        ans += Solve(a, L);
      }
      done.emplace(F);
    }
  }

  cout << ans << '\n';
  return;
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