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

using lint = long long;
using Mint = ModInt<MOD>;

int Score(vector<pair<int, int>> A) {
  vector<pair<int, int>> dir;
  for (int dx = -2; dx <= 2; dx++) {
    for (int dy = -2; dy <= 2; dy++) {
      if (abs(dx) + abs(dy) == 3) {
        dir.emplace_back(dx, dy);
      }
    }
  }
  assert(dir.size() == 8);

  map<pair<int, int>, int> freq;
  set<pair<int, int>> done(begin(A), end(A));
  set<pair<int, int>> s(begin(A), end(A));

  const auto Relax = [&](int x, int y) {
    freq[{x, y}]++;
    if (freq[{x, y}] >= 4 && done.count({x, y}) == 0) {
      done.emplace(x, y);
      s.emplace(x, y);
    }
  };

  while (!s.empty()) {
    auto [x, y] = *begin(s);
    s.erase(begin(s));
    for (auto [dx, dy] : dir) {
      Relax(x + dx, y + dy);
    }
  }

  return done.size();
}

void Main() {
  int N;
  cin >> N;
  vector<pair<int, int>> A;
  for (int i = 0; A.size() < N; i++) {
    if (i % 2 == 0) {
      if (A.size() < N) A.emplace_back(1, i);
      continue;
    }
    if (A.size() < N) A.emplace_back(0, i);
    if (A.size() < N) A.emplace_back(2, i);
  }
  // auto ev = Score(A);
  // cerr << ev << " / " << (N * N / 10) << " = " << double(ev) / double(int(N * N / 10)) << '\n';
  for (auto [x, y] : A) {
    cout << x << ' ' << y << '\n';
  }
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