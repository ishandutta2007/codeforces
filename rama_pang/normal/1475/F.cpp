#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    auto tmp = a;
    for (auto &i : a) for (auto &j : i) {
      char c;
      cin >> c;
      j = c - '0';
    }
    for (auto &i : tmp) for (auto &j : i) {
      char c;
      cin >> c;
      j = c - '0';
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] ^= tmp[i][j];
      }
    }
    

    {
      auto b = a;
      for (int j = 0; j < n; j++) {
        if (b[0][j] == 0) {
          for (int i = 0; i < n; i++) {
            b[i][j] ^= 1;
          }
        }
      }
      int can = 1;
      for (int i = 0; i < n; i++) {
        int s = accumulate(begin(b[i]), end(b[i]), 0);
        if (s != 0 && s != n) {
          can = 0;
        }
      }
      if (can) {
        cout << "YES\n";
        continue;
      }
    }
    {
      auto b = a;
      for (int j = 0; j < n; j++) {
        if (b[0][j] == 1) {
          for (int i = 0; i < n; i++) {
            b[i][j] ^= 1;
          }
        }
      }
      int can = 1;
      for (int i = 0; i < n; i++) {
        int s = accumulate(begin(b[i]), end(b[i]), 0);
        if (s != 0 && s != n) {
          can = 0;
        }
      }
      if (can) {
        cout << "YES\n";
        continue;
      }
    }
    cout << "NO\n";

  }
  return 0;
}