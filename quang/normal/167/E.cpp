#include <bits/stdc++.h>

using namespace std;

const int N = 610;

int p;

inline int add(int u, int v) {
  u += v;
  if (u >= p) {
    u -= p;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % p;
}

int n, m;
vector <int> pre[N];
int f[N], in[N], out[N], c[N][N];
int cntSource, cntSink;

int dfs(int u) {
  if (f[u] >= 0) {
    return f[u];
  }
  f[u] = 0;
  for (int v : pre[u]) {
    f[u] = add(f[u], dfs(v));
  }
  return f[u];
}

int Power(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = mul(res, u);
    }
    u = mul(u, u);
    v >>= 1;
  }
  return res;
}

int inv(int u) {
  return Power(u, p - 2);
}

int main() {
 // freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    pre[v].push_back(u);
    in[v]++;
    out[u]++;
  }
  cntSource = 0;
  for (int i = 1; i <= n; i++) {
    if (!in[i] && out[i]) {
      cntSource++;
      for (int j = 1; j <= n; j++) {
        f[j] = -1;
        if (i == j) {
          f[j] = 1;
        }
      }
      cntSink = 0;
      for (int j = 1; j <= n; j++) {
        if (in[j] && !out[j]) {
          cntSink++;
          c[cntSource][cntSink] = dfs(j);
        }
      }
    }
  }
  int sign = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] + out[i] == 0) {
      int x = 0, y = 0;
      for (int j = 1; j < i; j++) {
        x += (!in[j] && out[j]);
        y += (in[j] && !out[j]);
      }
      sign ^= ((x + y) % 2 == 1);
    }
  }
  int mm = 1;
  n = cntSource;
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      cout << c[i][j] << " ";
//    }
//    cout << endl;
//  }
  for (int i = 1; i <= n; i++) {
    int pos = i;
    for (int j = i + 1; j <= n; j++) {
      if (c[j][i] > c[pos][i]) {
        pos = j;
      }
    }
    if (pos != i) {
      sign ^= 1;
      for (int j = 1; j <= n; j++) {
        swap(c[i][j], c[pos][j]);
      }
    }
    for (int j = i + 1; j <= n; j++) {
      int x = c[i][i], y = c[j][i];
      mm = mul(mm, x);
      for (int k = 1; k <= n; k++) {
        c[j][k] = (mul(c[j][k], x) - mul(c[i][k], y) + p) % p;
      }
    }
  }
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = mul(res, c[i][i]);
  }
  res = mul(res, inv(mm));
  if (sign) {
    res = (p - res) % p;
  }
  cout << res << endl;
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      cout << c[i][j] << " ";
//    }
//    cout << endl;
//  }
  return 0;
}