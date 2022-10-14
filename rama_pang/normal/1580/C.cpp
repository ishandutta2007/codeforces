#include <bits/stdc++.h>
using namespace std;

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
using lint = long long;

const int DEBUG = 0;
const int STESS = 0;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  int N, M;
  if (!STESS) {
    cin >> N >> M;
  } else {
    N = 1e4;
    M = 2e5;
  }
  const int BLOCK = 220;
  vector<int> bruteAns(M + 1);
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    if (!STESS) {
      cin >> X[i] >> Y[i];
    } else {
      X[i] = rnd() % (BLOCK / 2 - 10) + 1;
      Y[i] = rnd() % (BLOCK / 2 - 10) + 1;      
    }
  }
  // x + y > sqrt: brute
  // x + y <= sqrt: group by [x + y]
  // group m times as [x + y]
  // if out range brute
  // if in range update in pref sum
  vector<int> haveTrain(M);
  vector<int> ans(M + 1);
  vector<int> prefAns(M + 1);
  vector<int> last(N, -1);
  vector<vector<array<int, 3>>> blocks(BLOCK);
  const auto BigUpdate = [&](int k, int lft, int rgt, int brute = 0) {
    if (brute == 0) {
      for (long long i = lft; i <= rgt; i += X[k] + Y[k]) {
        prefAns[i] += 1;
        prefAns[min(i + X[k], 1ll * rgt + 1)] -= 1;
      }
    } else {
      for (long long i = lft; i <= rgt; i += X[k] + Y[k]) {
        bruteAns[i] += 1;
        bruteAns[min(i + X[k], 1ll * rgt + 1)] -= 1;
      }
    }
  };
  for (int i = 0; i < M; i++) {
    int op, k;
    if (!STESS) {
      cin >> op >> k;
    } else {
      int r = i % (2 * N);
      if (r < N) {
        op = 1;
      } else {
        op = 2;
      }
      k = r % N + 1;
    }
    k--;
    if (op == 1) {
      haveTrain[i] += 1;
      assert(last[k] == -1);
      last[k] = i;
    } else {
      if (DEBUG) {
        BigUpdate(k, last[k], i - 1, 1);
      }
      haveTrain[i] -= 1;
      assert(last[k] != -1);
      if (X[k] + Y[k] < BLOCK) {
        blocks[X[k] + Y[k]].push_back({X[k], last[k], i - 1});
      } else {
        BigUpdate(k, last[k], i - 1);
      }
      last[k] = -1;
    }
  }
  for (int k = 0; k < N; k++) {
    if (last[k] != -1) {
      if (X[k] + Y[k] < BLOCK) {
        blocks[X[k] + Y[k]].push_back({X[k], last[k], M - 1});
      } else {
        BigUpdate(k, last[k], M - 1);
      }
    }
  }
  for (int i = 1; i < M; i++) {
    prefAns[i] += prefAns[i - 1];
    bruteAns[i] += bruteAns[i - 1];
    haveTrain[i] += haveTrain[i -1 ];
  }
  for (int i = 0; i < M; i++) {
    ans[i] += prefAns[i];
  }
  for (int period = 1; period < BLOCK; period++) {
    fill(begin(prefAns), end(prefAns), 0);
    for (auto [upd, lft, rgt] : blocks[period]) {
      if (rgt - lft <= 4 * period) {
        for (int i = 0; i <= rgt - lft; i++) {
          ans[lft + i] += (i % period) < upd;
        }
      } else {
        int blockL = (lft + period - 1) / period * period;
        int blockR = rgt / period * period;        
        for (int i = lft; i < blockL; i++) {
          ans[i] += ((i - lft) % period) < upd;
        }
        for (int i = blockR; i <= rgt; i++) {
          ans[i] += ((i - lft) % period) < upd;
        }
        assert(blockL + period <= blockR);
        for (int i = blockL; i < blockL + period; i++) {
          prefAns[i] += ((i - lft) % period) < upd;
        }
        for (int i = blockR; i < blockR + period && i < M; i++) {
          prefAns[i] -= ((i - lft) % period) < upd;
        }
      }
    }
    for (int i = period; i < M; i++) {
      prefAns[i] += prefAns[i - period];
    }
    for (int i = 0; i < M; i++) {
      ans[i] += prefAns[i];
    }
  }
  
  if (DEBUG) {
    for (int i = 0; i < M; i++) {
      assert(ans[i] == bruteAns[i]);
    }
  }

  for (int i = 0; i < M; i++) {
    if (!DEBUG) {
      cout << haveTrain[i] - ans[i] << '\n';
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}