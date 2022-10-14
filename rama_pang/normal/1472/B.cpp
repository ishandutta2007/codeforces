#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  int one = 0, two = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1) one++;
    else two++;
  }
  for (int i = 0; i <= one; i++) {
    for (int j = 0; j <= two; j++) {
      if (i + 2 * j == (one - i) + 2 * (two - j)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
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