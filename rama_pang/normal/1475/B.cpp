#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int d = n / 2020;
    n %= 2020;
    if (n <= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }


  }
  return 0;
}