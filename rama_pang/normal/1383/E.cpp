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

void Main() {
  string S;
  cin >> S;
  int N = S.size();

  // split into segments
  // take OR of each segment

  int st = 0, et = N;
  while (st < et && S[st] == '0') st++;
  while (st < et && S[et - 1] == '0') et--;

  if (st == et) {
    cout << N << '\n';
    return;
  }

  vector<int> zero;
  for (int i = st + 1, last = 0; i < et; i++) {
    if (S[i] == '0') {
      last++;
    } else {
      zero.push_back(last);
      last = 0;
    }
  }

  int M = zero.size();
  vector<Mint> dp(M + 1, 1);

  Mint sum_in_stack = 0;
  vector<int> stk; // on the right, has greater zero[] value

  const auto Calc = [&](int jid) -> Mint {
    if (jid == -1) return 0;
    int j = stk[jid];
    int low = (jid + 1 == stk.size()) ? -1 : zero[stk[jid + 1]];
    return (zero[j] - low) * dp[j + 1];
  };

  for (int i = M - 1; i >= 0; i--) {
    while (!stk.empty() && zero[stk.back()] <= zero[i]) {
      sum_in_stack -= Calc(int(stk.size()) - 2);
      sum_in_stack -= Calc(int(stk.size()) - 1);
      stk.pop_back();
      sum_in_stack += Calc(int(stk.size()) - 1);
    }

    sum_in_stack -= Calc(int(stk.size()) - 1);
    stk.emplace_back(i);
    sum_in_stack += Calc(int(stk.size()) - 2);
    sum_in_stack += Calc(int(stk.size()) - 1);

    dp[i] += sum_in_stack;

    // // next characters are [1] + [0] * k
    // for (int jid = int(stk.size()) - 1; jid >= 0; jid--) {
    //   // zero[stk[j + 1]] < k <= zero[stk[j]]
    //   int j = stk[jid];
    //   int low = (jid + 1 == stk.size()) ? -1 : zero[stk[jid + 1]];
    //   dp[i] += (zero[j] - low) * dp[j + 1];
    // }
  }

  cout << dp[0] * (st + 1) * (N - et + 1) << '\n';
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