#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int s = 0; s < n; s++) {
      for (int i = 0; i < n; i++) {
        if (k > 0) {
          ans[(i + s) % n][i] = 1;
          k--;
        }
      }
    }
    vector<int> row(n);
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (ans[i][j]) {
          row[i]++;
          col[j]++;
        }
      }
    }
    int r = *max_element(begin(row), end(row)) - *min_element(begin(row), end(row));
    int c = *max_element(begin(col), end(col)) - *min_element(begin(col), end(col));
    cout << 1ll * r * r + 1ll * c * c << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ans[i][j];
      }
      cout << "\n";
    }
  }
}