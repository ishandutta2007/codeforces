#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, m;
char a[N][N];

void solve(int test) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int it = 0; it < 2; it++) {
    bool f = 0;
    for (int i = 1; i <= n && !f; i++) {
      for (int j = 1; j <= m && !f; j++) {
        if (a[i][j] != '.') {
          int u = ((i + j) % 2) == it;
          if (u != (a[i][j] != 'R')) {
            f = 1;
          }
        }
      }
    }
    if (!f) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          int u = ((i + j) % 2) == it;
          if (u) cout << 'W';
          else cout << 'R';
        }
        cout << '\n';
      }
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) {
    solve(test);  
  }
  return 0;
}