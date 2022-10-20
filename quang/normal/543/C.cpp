#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m;
string s[N];
int a[N][N];
int cost[N][N], b[N][N];
int f[1 << N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int foo = 0;
      for (int k = 0 ; k < n; k++) {
        if (s[i][j] == s[k][j]) {
          cost[i][j] += a[k][j];
          foo = max(foo, a[k][j]);
          b[i][j] |= (1 << k);
        }
      }
      cost[i][j] -= foo;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    f[i] = 1000000000;
  }
  f[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (i == 0) {
      continue;
    }
    int pos;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        pos = j;
        break;
      }
    }
    for (int j = 0; j < m; j++) {
      f[i] = min(f[i], f[i ^ (1 << pos)] + a[pos][j]);
      f[i] = min(f[i], f[i ^ (i & b[pos][j])] + cost[pos][j]);
    }
  }
  cout << f[(1 << n) - 1];
  return 0;
}