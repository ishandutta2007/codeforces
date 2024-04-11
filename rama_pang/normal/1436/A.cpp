#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (accumulate(begin(a), end(a), 0ll) == m) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}