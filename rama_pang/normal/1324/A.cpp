#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        odd = 1;
      } else {
        even = 1;
      }
    }
    if (odd && even) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}