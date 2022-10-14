#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto Valid = [&](int x, int y) {
      if (x >= n || y >= n) return true;
      return a[x][y] == '1';
    };
    int valid = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '1') {
          if (Valid(i + 1, j) || Valid(i, j + 1)) {
            continue;
          } else {
            valid = 0;
          }
        }
      }
    }
    if (valid) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}