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
    int three = 0, two = 0;
    while (n > 1) {
      if (n % 2 == 0) {
        two++;
        n /= 2;
      } else if (n % 3 == 0) {
        three++;
        n /= 3;
      } else {
        two = three = -1;
        break;
      }
    }
    if (two == -1) {
      cout << -1 << "\n";
    } else if (two <= three) {
      cout << three + three - two << "\n";
    } else {
      cout << -1 << "\n";
    }
  }  
}