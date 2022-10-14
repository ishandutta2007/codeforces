#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> zero(n + m);
    vector<int> ones(n + m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (i + j != n + m - i - j - 2) {
          zero[i + j] += a[i][j] == 0;
          ones[i + j] += a[i][j] == 1;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i + 1 < n + m; i++) {
      ans += min(zero[i] + zero[n + m - 2 - i], ones[i] + ones[n + m - 2 - i]);
    }
    ans /= 2;
    cout << ans << "\n";
  }
}