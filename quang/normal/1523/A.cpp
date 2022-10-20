#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    string a;
    cin >> a;
    while (m--) {
      string b = a;
      for (int i = 0; i < n; i++) {
        if (a[i] == '1') b[i] = a[i];
        else {
          int cnt = 0;
          if (i > 0) cnt += a[i - 1] == '1';
          if (i + 1 < n) cnt += a[i + 1] == '1';
          b[i] = (cnt == 1) + '0';
        }
      }
      a.swap(b);
      if (a == b) break;
    }
    cout << a << '\n';
  }
  return 0;
}