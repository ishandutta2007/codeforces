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

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

struct Item {
  Mint cnt = 0;
  Mint sum = 0;
  Item() {}
  Item(Mint c, Mint s) : cnt(c), sum(s) {}
  Item operator*(const Item &o) {
    return Item(cnt * o.cnt, cnt * o.sum + sum * o.cnt);
  }
  Item operator+(const Item &o) {
    return Item(cnt + o.cnt, sum + o.sum);
  }
};

void Main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  const int Z = n + 5;
  vector<Item> dp(2 * Z + 1);
  dp[Z] = Item(1, 0);
  for (int i = n - 1; i >= 0; i--) {
    for (int p = 0; p < 2; p++) {
      vector<Item> ndp(2 * Z + 1);
      for (int x = 0; x < 2; x++) { // j = odd - even
        if (p == 0) {
          if (a[i] == '1' && x == 0) continue;
          if (a[i] == '0' && x == 1) continue;
          if (x == 0) {
            ndp = dp;
          } else if (i & 1) {
            // to odd
            for (int j = -Z + 1; j <= Z - 1; j++) {
              if (j < 0) {
                ndp[Z + j] = ndp[Z + j] + Item(1, +i) * dp[Z + j + 1];
              } else {
                ndp[Z + j] = ndp[Z + j] + Item(1, -i) * dp[Z + j + 1];
              }
            }
          } else {
            // to even
            for (int j = -Z + 1; j <= Z - 1; j++) {
              if (j > 0) {
                ndp[Z + j] = ndp[Z + j] + Item(1, +i) * dp[Z + j - 1];
              } else {
                ndp[Z + j] = ndp[Z + j] + Item(1, -i) * dp[Z + j - 1];
              }
            }
          }
        } else {
          if (b[i] == '1' && x == 0) continue;
          if (b[i] == '0' && x == 1) continue;
          if (x == 0) {
            ndp = dp;
          } else if (!(i & 1)) {
            // to odd
            for (int j = -Z + 1; j <= Z - 1; j++) {
              if (j < 0) {
                ndp[Z + j] = ndp[Z + j] + Item(1, +i) * dp[Z + j + 1];
              } else {
                ndp[Z + j] = ndp[Z + j] + Item(1, -i) * dp[Z + j + 1];
              }
            }
          } else {
            // to even
            for (int j = -Z + 1; j <= Z - 1; j++) {
              if (j > 0) {
                ndp[Z + j] = ndp[Z + j] + Item(1, +i) * dp[Z + j - 1];
              } else {
                ndp[Z + j] = ndp[Z + j] + Item(1, -i) * dp[Z + j - 1];
              }
            }
          }
        }
      }
      dp = ndp;
    }
  }

  cout << dp[Z].sum << '\n';

  // map<string, int> vis;
  // vis[a] = 0;
  // vector<string> que;
  // que.emplace_back(a);
  // for (int q = 0; q < int(que.size()); q++) {
  //   auto u = que[q];
  //   int d = vis[u];
  //   for (int i = 0; i < n - 1; i++) {
  //     if (u[i] == u[i + 1]) {
  //       u[i] ^= '0' ^ '1';
  //       u[i + 1] ^= '0' ^ '1';
  //       if (vis.count(u) == 0) {
  //         vis[u] = d + 1;
  //         que.emplace_back(u);
  //       }
  //       u[i] ^= '0' ^ '1';
  //       u[i + 1] ^= '0' ^ '1';
  //     }
  //   }
  // }

  // int canon = 0, sz = 0;
  // for (int i = 0; i < n; i++) {
  //   if (a[i] == '1') {
  //     if (i & 1) canon++;
  //     else canon--;
  //   }
  // }
  // for (int mask = 0; mask < (1 << n); mask++) {
  //   int cur = 0;
  //   for (int i = 0; i < n; i++) {
  //     if ((mask >> i) & 1) {
  //       if (i & 1) cur++;
  //       else cur--;
  //     }
  //   }
  //   sz += cur == canon;

  // }

  // assert(vis == VIS);
  // assert(vis.size() == sz);
  // for (auto [s, d] : vis) {
  //   cout << d << ' ' << s << '\n';
  // }

  // dp[Z] = 1;
  // for ()

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
1
9
001010010
(1, 2)
(3)
1

000000001
(8)


100110100
000000101
010010101


(4, 6, 8)
(1)

(0, 4, 6) -> (6, 8)
(3) -> ()




1
7 

*/