#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2025;
int t, n, a[N];
inline int findpos(int x) { return find(a + 1, a + n + 1, x) - a; }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if ((i + a[i]) & 1) ok = 0;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    cout << n / 2 * 5 << endl;
    while (n > 1) {
      int p = findpos(n);
      cout << p << ' ', reverse(a + 1, a + p + 1);
      p = findpos(n - 1) - 1;
      cout << p << ' ', reverse(a + 1, a + p + 1);
      cout << n << ' ', reverse(a + 1, a + n + 1);
      p = findpos(n);
      cout << p << ' ', reverse(a + 1, a + p + 1);
      cout << n << " \n"[n == 3], reverse(a + 1, a + n + 1);
      n -= 2;
    }
  }
}