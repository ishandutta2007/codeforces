#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

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

void Main() {
  int N;
  cin >> N;

  vector<pair<int, int>> edges;
  const auto Query = [&](int x) {
    cout << "? " << x + 1 << endl;
    vector<int> res(N);
    for (int i = 0; i < N; i++) cin >> res[i];
    for (int i = 0; i < N; i++) {
      if (res[i] == 1) {
        edges.emplace_back(min(i, x), max(i, x));
      }
    }
    return res;
  };

  auto res = Query(0);

  // X - 1 <= N - X -> X queries
  // X - 1 > N - X -> N - X + 1 queries
  // If X <= ceil(N / 2), done
  // Otherwise, X > (N + 1) / 2
  // N - X + 1 = N - (N + 1) / 2 = ceil(N / 2)

  vector<int> odd, even;
  for (int i = 1; i < N; i++) {
    if (res[i] % 2 == 1) {
      odd.emplace_back(i);
    } else {
      even.emplace_back(i);
    }
  }
  if (even.size() <= odd.size()) {
    for (auto i : even) Query(i);
  } else {
    for (auto i : odd) Query(i);
  }

  sort(begin(edges), end(edges));
  edges.resize(unique(begin(edges), end(edges)) - begin(edges));
  assert(edges.size() == N - 1);
  cout << "!" << endl;
  for (auto [u, v] : edges) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
  cout << flush;
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