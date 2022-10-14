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
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> pref;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    string s;
    for (int j = 0; j < A[i].size(); j++) {
      s.push_back(A[i][j]);
      pref.emplace_back(s);
    }
  }

  sort(begin(pref), end(pref));
  pref.resize(unique(begin(pref), end(pref)) - begin(pref));
  pref.emplace_back("");

  int P = pref.size();
  int L = 6;

  map<pair<string, string>, int> states;
  const auto Valid = [&](string S, string T) {
    reverse(begin(S), end(S));
    reverse(begin(T), end(T));
    for (int i = 0; i < min(S.size(), T.size()); i++) {
      if (S[i] != T[i]) return false;
    }
    return true;
  };

  const auto GetStateID = [&](string S, string T) {
    assert(Valid(S, T));
    if (S > T) swap(S, T);
    if (states.count({S, T})) return states[{S, T}];
    return states[{S, T}] = states.size();
  };

  for (int i = 0; i < P; i++) {
    for (int j = 0; j < P; j++) {
      if (Valid(pref[i], pref[j])) {
        GetStateID(pref[i], pref[j]);
      }
    }
  }

  // #states:
  // if S and T share same suffix
  // Assume |S| >= |T|
  // There are L * N strings for S
  // For each, there are O(L) strings for T
  // number of states = O(L * L * N)

  int S = states.size();
  vector<vector<Mint>> ways(S, vector<Mint>(S));

  const auto InitWays = [&](string S, string T) {
    assert(Valid(S, T));
    if (S > T) swap(S, T);
    if (S.empty() && T.empty()) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (Valid(A[i], A[j])) {
            string C = A[i]; C.pop_back();
            string D = A[j]; D.pop_back();
            ways[GetStateID(S, T)][GetStateID(C, D)] += 1;
          }
        }
      }
    } else if (S.empty()) {
      for (int i = 0; i < N; i++) {
        if (Valid(A[i], T)) {
          string C = A[i]; C.pop_back();
          string D = T; D.pop_back();
          ways[GetStateID(S, T)][GetStateID(C, D)] += 1;
        }
      }
    } else if (T.empty()) {
      for (int i = 0; i < N; i++) {
        if (Valid(S, A[i])) {
          string C = S; C.pop_back();
          string D = A[i]; D.pop_back();
          ways[GetStateID(S, T)][GetStateID(C, D)] += 1;
        }
      }
    } else {
      string C = S; C.pop_back();
      string D = T; D.pop_back();
      ways[GetStateID(S, T)][GetStateID(C, D)] += 1;
    }
  };

  for (int i = 0; i < P; i++) {
    for (int j = i; j < P; j++) {
      if (Valid(pref[i], pref[j])) {
        InitWays(pref[i], pref[j]);
      }
    }
  }

  vector<Mint> dp(S); dp[GetStateID("", "")] = 1;
  for (int x = M; x > 0; x /= 2){
    if (x & 1) {
      vector<Mint> dp2(S);
      for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
          dp2[i] += ways[i][j] * dp[j];
        }
      }
      dp = dp2;
    }
    vector<vector<Mint>> ways2(S, vector<Mint>(S));
    for (int i = 0; i < S; i++) {
      for (int j = 0; j < S; j++) {
        for (int k = 0; k < S; k++) {
          ways2[i][j] += ways[i][k] * ways[k][j];
        }
      }
    }
    ways = ways2;
  }

  cout << dp[GetStateID("", "")] << '\n';
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