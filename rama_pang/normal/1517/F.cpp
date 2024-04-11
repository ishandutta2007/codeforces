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

const int MAXN = 305;

int N, L;
vector<int> adj[MAXN];
Mint dp[MAXN][MAXN][2][2];

// For each vertex with no volunteers, we set dist[node] = 0.
// Then, we do a multiple source BFS starting from those
// vertices with no volunteers. The level of the tree
// if equal to the maximum dist[] in the tree, minus one.
// dp[vertex][label of current vertex][if label > 0, whether it is connected to label-1][there is label == L]
// Each vertex with label > 0, must be connected to at least 1 other vertex with label-1.

vector<int> ord;

void DfsInit(int u, int p) {
  if (p) {
    adj[u].erase(find(begin(adj[u]), end(adj[u]), p));
  }
  for (auto v : adj[u]) {
    if (v != p) {
      DfsInit(v, u);
    }
  }
  ord.emplace_back(u);
}

void Main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  DfsInit(1, 0);

  Mint ans = N - 1;
  for (int lev = 0; lev < N; lev++) {
    L = lev + 1;
    for (auto u : ord) {
      for (int value = 0; value <= L; value++) {
        for (int done = 0; done < 2; done++) {
          for (int from = 0; from < 2; from++) {
            Mint &ans = dp[u][value][from][done]; ans = 0;
            if (done == 0 && value == L) {
              continue;
            }
            if (value == 0 && from == 0) {
              continue;
            }
            if (adj[u].empty()) {
              if (from == 0) {
                continue;
              }
              if (done == 0 || value == L) {
                ans = 1;
              }
              continue;
            }

            ans = 1;
            Mint bad = (from == 0);
            for (auto v : adj[u]) {
              Mint sum_ans = 0;
              Mint sum_bad = 0;
              for (int dv = -1; dv <= 1; dv++) if (0 <= value + dv && value + dv <= L) {
                for (int di = 0; di <= done; di++) {
                  sum_ans += dp[v][value + dv][dv == 1 || (value + dv == 0)][di];
                  if (dv != -1) {
                    sum_bad += dp[v][value + dv][dv == 1 || (value + dv == 0)][di];
                  }
                }
              }
              ans *= sum_ans;
              bad *= sum_bad;
            }

            ans -= bad;
            if (done == 1) {
              ans -= dp[u][value][from][0];
            }
          }
        }
      }
    }

    Mint cur = 0;
    for (int val = 0; val <= L; val++) {
      cur += dp[1][val][val == 0][1];
    }
    ans += cur * lev;
  }

  ans /= pow(Mint(2), N);
  cout << ans << '\n';
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