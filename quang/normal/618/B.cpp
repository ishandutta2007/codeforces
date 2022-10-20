#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
int a[N][N];
int res[N], used[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      if (used[j]) {
        continue;
      }
      int f = 0;
      for (int k = 1; k <= n; k++) {
        if (a[k][j] && a[k][j] > i) {
          f = 1;
        }
        if (a[j][k] && a[j][k] > i) {
          f = 1;
        }
      }
      if (!f) {
        res[j] = i;
        used[j] = 1;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (res[i] ? res[i] : n) << " ";
  }
  return 0;
}