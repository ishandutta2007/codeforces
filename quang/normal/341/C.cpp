#include <bits/stdc++.h>

using namespace std;

const int N = 2010, MOD = 1000000007;

long long c[N][N], f[N];
int n;
int x[N], y[N];

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  //freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
      }
    }
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * i % MOD;
  }
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    if (u != -1) {
      x[i] = 1;
      y[u] = 1;
    }
  }
  int free = 0, ex = 0;
  for (int i = 1; i <= n; i++) {
    if (!x[i] && !y[i]) {
      free++;
    }
    if (!x[i]) {
      ex++;
    }
  }
  long long res = 0;
  for (int i = 0; i <= free; i++) {
    if (i & 1) {
      res = (res - (c[free][i] * f[ex - i]) % MOD + MOD) % MOD;
    } else {
      res = (res + c[free][i] * f[ex - i]) % MOD;
    }
  }
  cout << res << endl;
  return 0;
}