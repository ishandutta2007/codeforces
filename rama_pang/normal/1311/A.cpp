#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a == b) {
      ans = 0;
    } else if (a < b) {
      if (a % 2 == b % 2) {
        ans = 2;
      } else {
        ans = 1;
      }
    } else if (a > b) {
      if (a % 2 == b % 2) {
        ans = 1;
      } else {
        ans = 2;
      }
    }

    cout << ans << "\n";

  }
}