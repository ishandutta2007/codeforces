#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2 - 1; i++) {
      cout << i * 2 + 2 << ' ' << i * 2 + 1 << ' ';
    }
    cout << n - 1 << ' ' << n << '\n';
  } else {
    for (int i = 0; i < n / 2 - 2; i++) {
      cout << i * 2 + 5 << ' ' << i * 2 + 4 << ' ';
    }
    cout << "1 2 3 ";
    cout << n - 1 << ' ' << n << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}