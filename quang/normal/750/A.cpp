#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int tot = 4 * 60 - k;
  for (int i = 1; i <= n; i++) {
    if (tot - i * 5 < 0) {
      cout << i - 1 << endl;
      return 0;
    }
    tot -= i * 5;
  }
  cout << n << endl;
  return 0;
}