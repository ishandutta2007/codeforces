#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int best = 0;
  int one = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        one++;
      }
      if (i + 1 < n && a[i][j] == '0' && a[i + 1][j] == '0') {
        best = 1;
      }
      if (j + 1 < m && a[i][j] == '0' && a[i][j + 1] == '0') {
        best = 1;
      }
      if (i + 1 < n && j + 1 < m && a[i][j] == '0' && a[i + 1][j + 1] == '0') {
        best = 1;
      }
      if (i + 1 < n && j - 1 >= 0 && a[i][j] == '0' && a[i + 1][j - 1] == '0') {
        best = 1;
      }
    }
  }
  if (best) {
    cout << one << '\n';
  } else if (one == n * m) {
    cout << one - 2 << '\n';
  } else {
    cout << one - 1 << '\n';
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
}