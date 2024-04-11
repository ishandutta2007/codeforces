#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<string> b(n, string(m, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') continue;
      int d = 0;
      while (true) {
        if (i - d - 1 >= 0 && j - d - 1 >= 0 && j + d + 1 < m && a[i - d - 1][j - d - 1] == '*' && a[i - d - 1][j + d + 1] == '*') {
          d += 1;
        } else {
          break;
        }
      }
      if (d >= k) {
        for (int x = 0; x <= d; x++) {
          b[i - x][j - x] = b[i - x][j + x] = '*';
        }        
      }
    }
  }
  if (a == b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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