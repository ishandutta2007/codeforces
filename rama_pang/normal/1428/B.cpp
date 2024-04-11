#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = 0;
  for (auto i : s) {
    if (i == '>') {
      r++;
    }
    if (i == '<') {
      l++;
    }
  }
  if (l == 0 || r == 0) {
    cout << n << '\n';
  } else {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '-' || s[(i - 1 + n) % n] == '-') {
        ans++;
      }
    }
    cout << ans << '\n';
  }
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