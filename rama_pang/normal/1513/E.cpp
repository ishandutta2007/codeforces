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

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  lint bal = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    bal += A[i];
  }
  if (bal % N != 0) {
    cout << 0 << '\n';
    return;
  }
  if (N == 1) {
    cout << 1 << '\n';
    return;
  }
  bal /= N;

  vector<Mint> fact(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i;
  }

  Mint mul = 1;
  {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] == bal) {
        cnt += 1;
      }
    }
    if (cnt == N) {
      cout << 1 << '\n';
      return;
    }
    mul = fact[N] / fact[N - cnt] / fact[cnt];
    vector<int> B;
    for (int i = 0; i < N; i++) {
      if (A[i] != bal) {
        B.emplace_back(A[i]);
      }
    }
    A = B;
    N = A.size();
  }

  // The "sink" and "source" is contiguous (except corners).
  // if there is element "bal", then put it wherever

  Mint ans = 0;
  int source = 0;
  int sink = 0;

  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    assert(A[i] != bal);
    mp[A[i]]++;
    if (A[i] < bal) {
      sink++;
    } else {
      source++;
    }
  }

  Mint psource = fact[source];
  Mint psink = fact[sink];
  
  for (auto i : mp) {
    if (i.first < bal) {
      psink /= fact[i.second];
    } else if (i.first > bal) {
      psource /= fact[i.second];
    } else {
      assert(false);
    }
  }

  if (source == 1 || sink == 1) {
    cout << psource * psink * N * mul << '\n';
    return;
  }

  cout << psource * psink * 2 * mul << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}