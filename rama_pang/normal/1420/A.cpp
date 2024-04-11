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
    bool cant = true;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] <= a[i + 1]) {
        cant = false;
      }
    }
    if (cant) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}