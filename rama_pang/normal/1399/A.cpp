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
    sort(begin(a), end(a));
    int can = 1;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] + 1 < a[i + 1]) {
        can = 0;
      }
    }
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}