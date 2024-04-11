#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    bool good = false;
    for (int i = 0; i < l; i++) {
      if (s[i] == s[l]) {
        good = true;
      }
    }
    for (int i = r + 1; i < n; i++) {
      if (s[i] == s[r]) {
        good = true;
      }
    }
    if (good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
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