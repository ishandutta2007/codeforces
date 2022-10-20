#include <bits/stdc++.h>

#define matrix vector<vector<int> >

using namespace std;

const int MOD = 1000000007;

int w[10];
int dp[1 << 7];

matrix mul(const matrix &u, const matrix &v) {
  matrix res(u.size(), vector<int> (v[0].size(), 0));
  for (int i = 0; i < u.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        res[i][j] = (1ll * u[i][k] * v[k][j] + res[i][j]) % MOD;
      }
    }
  }
  return res;
}

matrix qpow(matrix u, int v) {
  matrix res(u.size(), vector<int> (u.size(), 0));
  for (int i = 0; i < u.size(); i++) {
    res[i][i] = 1;
  }
  while (v) {
    if (v & 1) {
      res = mul(res, u);
    }
    u = mul(u, u);
    v /= 2;
  }
  return res;
}

bool has(int mask, int i) {
  return (mask & (1 << i));
}

int calc(int u, int v, int cnt) {
  int dp0 = 0, dp1 = 1;
  for (int i = 0; i < cnt; i++) {
    int d0, d1;
    d0 = dp1 + dp0;
    if (has(u, i) && has(v, i)) {
      d1 = dp0;
    } else {
      d1 = d0;
    }
    dp0 = d0;
    dp1 = d1;
  }
  return dp1;
}

int main() {
  for (int i = 1; i <= 7; i++) {
    scanf("%d", w + i);
  }
  dp[0] = 1;
  for (int i = 1; i <= 7; i++) {
    matrix a(1, vector<int> (1 << i, 0));
    for (int j = 0; j < (1 << (i - 1)); j++) {
      a[0][(1 << (i - 1)) | j] = dp[j];
    }
    memset(dp, 0, sizeof dp);
    matrix base(1 << i, vector <int> (1 << i, 0));
    for (int j = 0; j < (1 << i); j++) {
      for (int k = 0; k < (1 << i); k++) {
        base[j][k] = calc(j, k, i);
      }
    }
    base = qpow(base, w[i]);
    a = mul(a, base);
    for (int j = 0; j < (1 << i); j++) {
      dp[j] = a[0][j];
    }
  }
  printf("%d\n", dp[(1 << 7) - 1]);
  return 0;
}