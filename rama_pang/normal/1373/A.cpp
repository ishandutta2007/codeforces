#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < c) {
      cout << 1;
    } else {
      cout << -1;
    }
    cout << " ";
    if (1ll * a * b > c) {
      cout << b;
    } else {
      cout << -1;
    }
    cout << "\n";
  }
}