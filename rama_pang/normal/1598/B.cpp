#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      a[i] |= x << j;
    }
  }
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      if (x != y) {
        int l = 0, r = 0, m = 0;
        for (int i = 0; i < n; i++) {
          int bx = (a[i] >> x) & 1;
          int by = (a[i] >> y) & 1;
          if (bx && by) m++;
          else if (bx) l++;
          else if (by) r++;
          else {
            l = r = -1;
            break;
          }
        }
        if (l != -1 && n % 2 == 0 && min(l, r) + m >= max(l, r)) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
  return;
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