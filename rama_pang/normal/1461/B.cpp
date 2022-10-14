#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> p(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      p[i][j] = a[i - 1][j - 1] == '*';
      p[i][j] += p[i - 1][j];
      p[i][j] += p[i][j - 1];
      p[i][j] -= p[i - 1][j - 1];
    }
  }
  const auto Sum = [&](int r1, int c1, int r2, int c2) {
    return p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1];
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; i + k - 1 <= n; k++) {
        if (Sum(i + k - 1, j - k + 1, i + k - 1, j + k - 1) != 2 * k - 1) {
          break;
        }
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}