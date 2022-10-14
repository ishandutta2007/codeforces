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

const int MAX = 5e6 + 25;

const int MOD = 1e9 + 9;
using Mint = ModInt<MOD>;

const int KEY = 67;
const int INVKEY = (Mint(1) / Mint(KEY)).v;

using lint = long long;
const lint INF = 1e18;

Mint power_key[MAX];
Mint inverse_power[MAX];

class HashString {
 public:
  vector<Mint> prefix;

  HashString() {}
  HashString(string S) {
    prefix.assign(S.size(), 0);
    for (int i = 0; i < int(S.size()); i++) {
      prefix[i] = ((i ? prefix[i - 1] : 0) + (S[i] - 'a' + 1) * power_key[i]);
    }
  }

  int size() { return prefix.size(); }

  Mint GetSubstring(int L, int R) {
    if (L > R) return 0;
    assert(0 <= L && L <= R && R < size());
    Mint res = prefix[R] - (L ? prefix[L - 1] : 0);
    res *= inverse_power[L];
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < MAX; i++) {
    power_key[i] = i == 0 ? 1 : (KEY * power_key[i - 1]);
    inverse_power[i] = i == 0 ? 1 : (INVKEY * inverse_power[i - 1]);
  }

  int N, Q;
  cin >> N >> Q;
  string S, T;
  cin >> S >> T;

  using MintAns = ModInt<int(1e9 + 7)>;

  vector<array<MintAns, 26>> cnt_letter(N + 1);
  for (int i = 1; i <= N; i++) {
    cnt_letter[i][T[i - 1] - 'a'] += 1;
    for (int j = 0; j < 26; j++) {
      cnt_letter[i][j] += 2 * cnt_letter[i - 1][j];
    }
  }

  vector<lint> lenS(N + 1);
  lenS[0] = S.size();
  for (int i = 1; i <= N; i++) {
    lenS[i] = min(INF, 2ll * lenS[i - 1] + 1);
  }

  int LOG = 1;
  while (LOG <= N && lenS[LOG] < MAX / 3) LOG += 1;

  vector<HashString> H(LOG);
  H[0] = HashString(S);
  for (int i = 1; i < LOG; i++) {
    S = S + T[i - 1] + S;
    H[i] = HashString(S);
  }

  const auto CountAns = [&](int s_idx, int w_sz, Mint W) -> int {
    assert(s_idx < LOG);
    int ans = 0;
    for (int i = 0; i + w_sz - 1 < H[s_idx].size(); i++) {
      if (H[s_idx].GetSubstring(i, i + w_sz - 1) == W) {
        ans += 1;
      }
    }
    return ans;
  };

  while (Q--) {
    int K;
    cin >> K;
    string W;
    cin >> W;

    if (lenS[K] < W.size()) {
      cout << 0 << '\n';
      continue;
    }

    int C = 0;
    while (C <= N && lenS[C] < W.size()) {
      C += 1;
    }

    assert(C <= K && lenS[C] >= W.size());

    // ans(K, W) = 2 * ans(K - 1, W) + ans_merging
    // |W| <= lenS[C]. That means, the suffix before T[K-1] and
    // prefix after T[K-1] == |W|, C, since we can ignore the
    // remaining characters. This means, we can compute ans_merging
    // for only 26 characters of T[], then sum it up.
    //
    // ans(K, W) = 2^{K - C} * ans(C, W) + ans_merging

    Mint hashW = HashString(W).GetSubstring(0, int(W.size()) - 1);
    MintAns ans = pow(MintAns(2), K - C) * CountAns(C, W.size(), hashW);

    array<MintAns, 26> merge_char = {};
    for (int shift = 0; shift < int(W.size()); shift++) {
      Mint left = H[C].GetSubstring(H[C].size() - shift, H[C].size() - 1);
      Mint right = H[C].GetSubstring(0, int(W.size()) - 2 - shift);
      Mint res = left + power_key[shift] * ((W[shift] - 'a' + 1) + power_key[1] * right);
      if (res == hashW) merge_char[W[shift] - 'a'] += 1;
    }

    for (int character = 0; character < 26; character++) {
      MintAns contrib = cnt_letter[K][character] - pow(MintAns(2), K - C) * cnt_letter[C][character];
      ans += contrib * merge_char[character];
    }

    cout << ans << '\n';
  }
  return 0;
}