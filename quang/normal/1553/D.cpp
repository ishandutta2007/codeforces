#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  string s, t;
  cin >> s >> t;
  int cur = (int)s.size() - 1;
  for (int i = (int)t.size() - 1; i >= 0; i--) {
    while (cur >= 0 && s[cur] != t[i]) cur -= 2;
    if (cur < 0) {
      cout << "NO\n";
      return;
    }
    cur--;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}