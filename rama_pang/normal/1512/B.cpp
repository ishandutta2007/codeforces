#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &i : a) cin >> i;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '*') {
        p.emplace_back(i, j);
      }
    }
  }
  int r1, r2, c1, c2;
  if (p[0].first != p[1].first) {
    r1 = p[0].first;
    r2 = p[1].first;
  } else {
    r1 = p[0].first;
    r2 = p[0].first == 0 ? 1 : 0;
  }
  if (p[0].second != p[1].second) {
    c1 = p[0].second;
    c2 = p[1].second;
  } else {
    c1 = p[0].second;
    c2 = p[0].second == 0 ? 1 : 0;
  }

  a[r1][c1] = a[r2][c1] = a[r1][c2] = a[r2][c2] = '*';
  for (int i = 0; i < n; i++) {
    cout << a[i] << '\n';
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