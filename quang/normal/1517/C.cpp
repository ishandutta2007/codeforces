#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n;
int a[N];
int res[N][N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    res[i][i] = a[i];
  }
  for (int sub = 0; sub + 1 < n; sub++) {
    int pos = 0;
    for (int i = sub + 1; i <= n; i++) {
      if (!pos || res[i][i - sub] < res[pos][pos - sub]) {
        pos = i;
      }
    }
    for (int i = sub + 1; i < pos; i++) {
      res[i + 1][i - sub] = res[i][i - sub];
    }
    for (int i = pos + 1; i <= n; i++) {
      res[i][i - sub - 1] = res[i][i - sub];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}