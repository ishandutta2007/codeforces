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
    vector<int> a(n), b(n);
    for (auto &i : a) {
      cin >> i;
    }
    for (auto &i : b) {
      cin >> i;
    }
    int augment = 2e9;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] > b[i]) {
        if (augment < a[i] - b[i] || b[n - 1] < a[i] - b[i]) {
          goto NO;
        }
        augment -= a[i] - b[i];
        b[n - 1] -= a[i] - b[i];
        a[i] = b[i];
      }
      b[i] -= a[i];
      if (b[i] > a[i + 1]) {
        a[i + 1] = 0;
      } else {
        a[i + 1] -= b[i];
      }
      augment = min(augment, a[i]);
    }
    if (a[n - 1] > b[n - 1]) goto NO;

    cout << "YES\n";
    continue;
    NO: cout << "NO\n";
  }    
}