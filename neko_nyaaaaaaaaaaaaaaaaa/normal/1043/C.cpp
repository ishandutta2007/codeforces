#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      string s; cin >> s; 
      int n = s.size();
      s += 'b';
      for (int i = 0; i < n; i++) {
            cout << (s[i] != s[i+1]) << ' ';
      }

      return 0;
}