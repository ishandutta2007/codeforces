#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto b = a;
    sort(begin(b), end(b));
    b.resize(unique(begin(b), end(b)) - begin(b));
    if (b.size() == 1) {
      cout << "NO\n";
      continue;
    }
    int f = -1, g = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[0]) {
        f = i;
      }
      if (a[i] == b[1]) {
        g = i;
      }
    }
    cout << "YES\n";
    cout << f + 1 << " " << g + 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (i != f && i != g) {
        if (a[i] != a[f]) {
          cout << i + 1 << " " << f + 1 << "\n";
        } else {
          cout << i + 1 << " " << g + 1 << "\n";
        }
      }
    }
  }
  return 0; 
}