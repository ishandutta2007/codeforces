#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mn = *min_element(begin(a), end(a));
    auto b = a;
    int can = 1;
    sort(begin(b), end(b));
    for (int i = 0; i < n; i++) {
      if (a[i] % mn != 0 && a[i] != b[i]) {
        can = 0;
      }
    }
    if (!can) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}