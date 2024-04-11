#include <bits/stdc++.h>
using namespace std;
using lint = long long;


void Main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m, -1));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] > 4) {
        cout << "NO\n";
        return;
      }
      b[i][j] = 4;
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        b[i][j] = 3;
      }
      if (i == 0 && j == 0) {
        b[i][j] = 2;
      }
      if (i == n - 1 && j == 0) {
        b[i][j] = 2;
      }
      if (i == 0 && j == m - 1) {
        b[i][j] = 2;
      }
      if (i == n - 1 && j == m - 1) {
        b[i][j] = 2;
      }
      if (a[i][j] > b[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << b[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}