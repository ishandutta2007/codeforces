#include <bits/stdc++.h>

#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 110;

int n, m;
long long w[N][N];
long long a[N], b[N];
long long k = 0;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> w[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    b[i] = w[1][i];
  }
  memset(a, -1, sizeof(a));
  a[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!k) {
      for (int j = 1; j <= m; j++) {
        if (w[i][j] >= b[j]) {
          a[i] = w[i][j] - b[j];
          break;
        }
      }
      if (a[i] != -1) {
        for (int j = 1; j <= m; j++) {
          if (w[i][j] < b[j]) {
            k = a[i] + b[j] - w[i][j];
            break;
          }
        }
      }
    } else {
      break;
    }
  }
  if (k == 0) {
    k = 1000000000000ll;
  }
  for (int i = 1; i <= n; i++) {
    if (w[i][1] >= b[1]) {
      a[i] = w[i][1] - b[1];
    } else {
      a[i] = w[i][1] + k - b[1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long val = (a[i] + b[j]) % k;
      if (val != w[i][j]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  cout << k << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  for (int i = 1; i <= m; i++) cout << b[i] << " ";
  return 0;
}