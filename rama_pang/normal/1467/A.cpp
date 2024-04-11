#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int TT = 1;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "9\n";
    } else if (n == 2) {
      cout << "98\n";
    } else {
      cout << "98";
      int cur = 9;
      for (int i = 0; i + 2 < n; i++) {
        cout << cur;
        cur++;
        cur %= 10;
      }
      cout << '\n';
    }
  }
  return 0;
}