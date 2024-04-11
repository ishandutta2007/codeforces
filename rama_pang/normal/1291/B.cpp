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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> ideal(n, n + 1);
    for (int i = 0; i < n; i++) {
      ideal[i] = min(ideal[i], i);
    }
    for (int i = n - 1; i >= 0; i--) {
      ideal[i] = min(ideal[i], n - i - 1);
    }

    int can = 2;
    for (int k = 0; k < 2; k++) {
      if (n % 2 == 0) {
        ideal[n / 2 - 1 + k] ++;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] < ideal[i]) {
          can--;
          break;
        }
      }
      if (n % 2 == 0) {
        ideal[n / 2 - 1 + k]--;
      }
    }

    if (can > 0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}