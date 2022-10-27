#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    if ((n + m) & 1) {
      cout << -1 << endl;
      continue;
    }
    if (n == 0 && m == 0) {
      cout << 0 << endl;
      continue;
    }
    cout << 1 + (n != m) << endl;
  }
}