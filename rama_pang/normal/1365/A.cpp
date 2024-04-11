#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int r = 0, c = 0;
    for (int i = 0; i < n; i++) {
      int can = 1;
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1) can = 0;
      }
      if (can) r++;
    }

    for (int i = 0; i < m; i++) {
      int can = 1;
      for (int j = 0; j < n; j++) {
        if (a[j][i] == 1) can = 0;
      }
      if (can) c++;
    }

    if (min(r, c) & 1) {
      cout << "Ashish\n";
    } else {
      cout << "Vivek\n";
    }
  }
}