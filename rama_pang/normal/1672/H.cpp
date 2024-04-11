#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n), b(n);
  for (int i = 0; i + 1 < n; i++) {
    a[i + 1] = s[i] == s[i + 1] && s[i] == '0';
    b[i + 1] = s[i] == s[i + 1] && s[i] == '1';
    a[i + 1] += a[i];
    b[i + 1] += b[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int mx = max({a[r] - a[l], b[r] - b[l], (a[r] - a[l] + b[r] - b[l] + 1) / 2});
    cout << mx + 1 << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}