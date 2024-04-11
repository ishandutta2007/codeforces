#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int a[N][N], n, x[N];
long long res[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = n; i; i--) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        a[x[j]][x[k]] = min(a[x[j]][x[k]], a[x[j]][x[i]] + a[x[i]][x[k]]);
      }
    }
    for (int j = i; j <= n; j++) {
      for (int k = i; k <= n; k++) {
        res[i] += a[x[j]][x[k]];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}