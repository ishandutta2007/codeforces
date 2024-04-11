#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int ch = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      ch++;
    }
  }
  cout << a * n + max(n * b, (ch / 2 + 1) * b) << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}