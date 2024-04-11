#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, m, k;
long long a[10][N], rmq[10][N][30];
long long res[10];

void Make_RMQ() {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      rmq[i][j][0] = a[i][j];
    }
    for (int k = 1; k <= log2(n); k++) {
      for (int j = 1; j <= n; j++) {
        rmq[i][j][k] = max(rmq[i][j][k - 1], rmq[i][j + (1 << (k - 1))][k - 1]);
      }
    }
  }
}

bool Check(int u) {
  for (int i = 1; i <= n - u + 1; i++) {
    long long foo[10], sum = 0;
    int l = log2(u);
    memset(foo, 0, sizeof foo);
    for (int j = 1; j <= m; j++) {
      foo[j] = max(rmq[j][i][l], rmq[j][i + u - (1 << l)][l]);
      sum += foo[j];
    }
    if (sum <= k) {
      for (int j = 1; j <= m; j++) {
        res[j] = foo[j];
      }
      return 1;
    }
  }
  return 0;
}

void Findans() {
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (Check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << res[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[j][i];
    }
  }
  Make_RMQ();
  Findans();
  return 0;
}