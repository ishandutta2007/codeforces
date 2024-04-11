#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int a[505][505];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++)
        cin >> a[i][j];
    for (int i = n + 1; i <= 2 * n; i++)
      for (int j = n + 1; j <= 2 * n; j++)
        ans += a[i][j];
    cout << ans + min({a[1][n + 1], a[1][2 * n], a[n][n + 1], a[n][2 * n], a[n + 1][1], a[2 * n][1], a[n + 1][n], a[2 * n][n]}) << '\n';
  }
}