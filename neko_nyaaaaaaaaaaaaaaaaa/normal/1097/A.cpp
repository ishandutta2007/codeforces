#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      string s; cin >> s;
      string t;
      int k = 5;
      while (k--) {
            cin >> t;
            if (t[0] == s[0] || t[1] == s[1]) {cout << "YES"; return 0;}
      }
      cout << "NO";

      return 0;
}