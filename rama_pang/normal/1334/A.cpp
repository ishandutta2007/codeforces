#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i] >> c[i];
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      int dp = p[i] - p[i - 1];
      int dc = c[i] - c[i - 1];
      if (dp < 0 || dc < 0) ok = false;
      if (dc > dp) ok = false;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
}