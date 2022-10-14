#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  if (m < n) {
    cout << "No\n";
    return;
  }
  if (m % n == 0) {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      cout << m / n << ' ';
    }
    cout << '\n';
    return;
  }
  if (n % 2 == 1) {
    cout << "Yes\n";
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << ' ';
    }
    cout << m - (n - 1);
    cout << '\n';
    return;
  }
  if (m % 2 == 0) {
    cout << "Yes\n";
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n / 2 - 1; i++) {
        cout << 1 << ' ';
      }
      cout << m / 2 - (n / 2 - 1) << ' ';
    }
    cout << '\n';
    return;
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}