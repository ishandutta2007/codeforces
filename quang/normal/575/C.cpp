#include <bits/stdc++.h>

using namespace std;

const int N = 25, inf = 1e9;

int n;
int a[2][N][N];
int b[N][N];
int res = -inf;
int u[N], v[N], p[N], pre[N];
bool used[N];
int minv[N];

void dfs(int i, int zero, int one) {
  if (i == n + 1) {
    res = max(res, v[0]);
    return;
  }
  for (int x = 0; x < 2; x++) {
    if (x == 0 && zero == n / 2) {
      continue;
    }
    if (x == 1 && one == n / 2) {
      continue;
    }
    for (int j = 1; j <= n; j++) {
      b[i][j] = -a[x][i][j];
    }
    int oldu[N], oldv[N], oldp[N], oldpre[N];
    for (int j = 0; j <= n; j++) {
      oldu[j] = u[j];
      oldv[j] = v[j];
      oldp[j] = p[j];
      oldpre[j] = pre[j];
    }
    for (int j = 0; j <= n; j++) {
      minv[j] = inf;
      used[j] = 0;
    }
    int j0 = 0;
    p[0] = i;
    while (p[j0]) {
      used[j0] = 1;
      int i0 = p[j0], delta = inf, j1;
      for (int j = 1; j <= n; j++) {
        if (!used[j]) {
          int cur = b[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            pre[j] = j0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= n; j++) {
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      j0 = j1;
    }
    while (j0) {
      int j1 = pre[j0];
      p[j0] = p[j1];
      j0 = j1;
    }
    dfs(i + 1, zero + (x == 0), one + x);
    for (int j = 0; j <= n; j++) {
      u[j] = oldu[j];
      v[j] = oldv[j];
      p[j] = oldp[j];
      pre[j] = oldpre[j];
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  for (int k = 0; k <= 1; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[k][i][j];
      }
    }
  }
  dfs(1, 0, 0);
  cout << res << endl;
    return 0;
}