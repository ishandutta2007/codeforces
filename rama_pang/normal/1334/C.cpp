#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<lint> a(n), b(n);
    lint ans = 0, suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
      b[i] = min(a[(i + 1) % n], b[i]);

    }
    for (int i = 0; i < n; i++) {
      suma += a[i];
      sumb += b[i];
    }
    ans = 1e18;
    for (int fs = 0; fs < n; fs++) {
      lint cost = suma - sumb + b[(fs - 1 + n) % n];
      ans = min(ans, cost);
    }

    cout << ans << "\n";

  }
}