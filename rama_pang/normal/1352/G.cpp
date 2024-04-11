#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n <= 3) {
      cout << -1 << "\n";
    } else if (n == 4) {
      cout << "3 1 4 2\n";
    } else {
      int x = 1;
      while (x <= n) {
        cout << x << " ";
        x += 2;
      }
      x -= 2;

      if (x == n) {
        x -= 3;
        cout << x << " ";
        x += 2;
        cout << x << " ";
        x -= 4;
      } else if (x + 1 == n) {
        x -= 3;
        cout << x << " ";
        x += 4;
        cout << x << " ";
        x -= 2;
        cout << x << " ";
        x -= 4;
      }
      while (x >= 2) {
        cout << x << " ";
        x -= 2;
      }

      cout << "\n";
    }
  }  
}