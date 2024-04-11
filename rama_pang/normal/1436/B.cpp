#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
      a[i][i] = 1;
      a[i][n - i - 1] = 1;
    }
    if (n & 1) {
      int m = n / 2;
      a[m][m] = 0;
      a[m][m - 1] = 1;
      a[m][m + 1] = 1;
      a[m - 1][m] = 1;
      a[m + 1][m] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j] << " \n"[j + 1 == n];
      }
    }
  }
  return 0;
}