#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> ok(n, 1);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;
    ok[b] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (ok[i]) {
      for (int j = 0; j < n; j++) if (i != j) {
        cout << i + 1 << ' ' << j + 1 << '\n';
      }
      return;
    }
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