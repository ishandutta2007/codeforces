#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &u : a) {
      cin >> u;
    }
    cout << 6 * n / 2 << '\n';
    for (int i = 1; i <= n; i += 2) {
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
    }
  }
  return 0;
}