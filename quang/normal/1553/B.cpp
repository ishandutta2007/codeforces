#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  string s, t;
  cin >> s;
  cin >> t;

  auto Cmp = [&](int l, int r, int ll, int rr, int rev = 0) {
    if (ll < 0 || l < 0) return 0;
    if (rr - ll != r - l) return 0;
    if (!rev) { 
      for (int i = 0; i <= rr - ll; i++) {
        if (s[l + i] != t[ll + i]) return 0;
      }
    } else {
      for (int i = 0; i <= rr - ll; i++) {
        if (s[l + i] != t[rr - i]) return 0;
      }
    }

    return 1;
  };

  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < t.size(); j++) {
      if (Cmp(i - j, i, 0, j) && Cmp(i - (int)t.size() + j + 1, i, j, (int)t.size() - 1, 1)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}