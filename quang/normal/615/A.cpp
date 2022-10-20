#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  bool f[110];
  memset(f, 0, sizeof f);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= x; j++) {
      int u;
      cin >> u;
      f[u] = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!f[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}