#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int f = -1, s = -1;
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] == a[i + 1]) {
      f = i;
      break;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == a[i - 1]) {
      s = i;
      break;
    }
  }
  int len = s - f + 1;
  if (len <= 2) {
    cout << "0\n";
  } else if (len == 3) {
    cout << "1\n";
  } else {
    cout << len - 3 << '\n';
  }
  // f(2) = 0
  // f(3) = 1
  // f(4) = 1
  // f(5) = 2
  // f(6) = 3
  // f(7) = 4
  // cout << s - f << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}