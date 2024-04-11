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
  int N, K;
  cin >> N >> K;

  const auto Query = [&](vector<int> a) {
    cout << "?";
    for (auto i : a) cout << ' ' << i + 1;
    cout << endl;
    int foo;
    cin >> foo;
    return foo;
  };

  vector<int> dist(N + 1, -1);
  vector<array<int, 3>> prv(N + 1, {-1, -1, -1});
  dist[0] = 0;
  vector<int> que = {0};

  for (int q = 0; q < int(que.size()); q++) {
    int turnedOn = que[q];
    int turnedOff = N - turnedOn;
    for (int i = 0; i <= K; i++) {
      if (i <= turnedOff && K - i <= turnedOn) {
        int nxt = turnedOn + i - (K - i);
        if (dist[nxt] == -1) {
          dist[nxt] = dist[turnedOn] + 1;
          prv[nxt] = {turnedOn, i, K - i};
          que.emplace_back(nxt);
        }
      }
    }
  }

  if (dist[N] == -1) {
    cout << -1 << endl;
    return;
  }

  int ans = 0;
  vector<int> state(N);
  int cur = N;
  vector<pair<int, int>> ops; // (turn on, turn off)
  while (cur > 0) {
    ops.push_back({prv[cur][1], prv[cur][2]});
    cur = prv[cur][0];
  }
  reverse(begin(ops), end(ops));

  for (auto [on, off] : ops) {
    int newOn = 0;
    int newOff = 0;
    vector<int> q;
    for (int i = 0; i < N; i++) {
      if (state[i] == 0 && newOn < on) {
        newOn++;
        state[i] ^= 1;
        q.emplace_back(i);
      } else if (state[i] == 1 && newOff < off) {
        newOff++;
        state[i] ^= 1;
        q.emplace_back(i);
      }
    }
    assert(newOn == on && newOff == off);
    ans ^= Query(q);
  }

  cout << "! " << ans << endl;
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