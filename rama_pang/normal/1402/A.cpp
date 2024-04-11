#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 3) {
    for (int i = 0; i < max(3, n); i++) {
      if (i < n) {
        cout << i + 1 << " " << i + 1 << "\n " << -a[i] << "\n";
      } else {
        cout << 1 << " " << 1 << "\n " << 0 << "\n";
      }
    }
  } else {
    cout << 1 << " " << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (i + 1 == n) {
        cout << "\n" << n << " " << n << "\n " << -a[i] << "\n";
        a[i] = 0;
      } else {
        int md = (a[i] % n + n) % n;
        cout << 1ll * md * (n - 1) << " ";
        a[i] += 1ll * md * (n - 1);
      }
    }
    cout << 1 << " " << n << "\n";
    for (int i = 0; i < n; i++) {
      assert(a[i] % n == 0);
      cout << -a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}