#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int c : {'R', 'W'}) {
    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i].assign(m, '.');
      for (int j = 0; j < m; j++) {
        if ((i + j) & 1) {
          ans[i][j] = c;
        } else {
          ans[i][j] = c ^ 'R' ^ 'W';
        }
      }
    }
    bool bad = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') continue;
        if (a[i][j] != ans[i][j]) {
          bad = true;
        }
      }
    }
    if (!bad) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) cout << ans[i] << '\n';
      return;
    }
  }
  cout << "NO\n";
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