#include <bits/stdc++.h>

using namespace std;

const int N = 410;

long long res = 0;

int n, m;
int f[2][N][N], g[2][N][N];
char a[N][N], b[N][N];
bool check[N][N];

void go() {
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  int cur = 0;
  for (int i = 1; i <= m; i++) {
    int next = cur ^ 1;
    memset(f[next], 0, sizeof f[next]);
    memset(g[next], 0, sizeof g[next]);
    for (int j = 1; j <= n; j++) {
      for (int k = j; k <= n; k++) {
        check[j][k] = 0;
      }
    }
    for (int len = 1; len <= n; len++) {
      for (int l = 1; l <= n - len + 1; l++) {
        int r = l + len - 1;
        if (len == 1) {
          check[l][r] = (a[l][i] != '0');
        } else {
          check[l][r] = check[l + 1][r] | (a[l][i] != '0');
        }
        f[next][l][r] += (!check[l][r] && len > 1);
        g[next][l][r] += (!check[l][r] && len > 1);
        if ((a[l][i] == '0') && (a[r][i] == '0') && l > 1) {
          f[next][l][r] += f[cur][l - 1][r];
        }
        if ((a[l][i] == '0') && (a[r][i] == '0') && l > 1 && r < n) {
          g[next][l][r] += g[cur][l - 1][r + 1];
        }
        if (len == 1) {
          res += f[next][l][r] + g[next][l][r];
        }
      }
    }
    cur = next;
  }
}

void rot() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] = a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[m - j + 1][i] = b[i][j];
    }
  }
  swap(n, m);
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (a[i] + 1);
  }
  for (int i = 1; i <= 4; i++) {
    go();
    rot();
  }
  cout << res << endl;
  return 0;
}