#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, o = 0; cin >> n;
      string s; cin >> s;
      for (char c: s) {
            if (c == '(') o++; else o--;
      } //cerr << o << endl;
      if (abs(o) != 2) {cout << 0; return 0;}
      if (o == -2) {
            reverse(s.begin(), s.end());
            for (char &c: s) {
                  if (c == '(') c = ')';
                  else c = '(';
            }
            //cout << s << '\n';
      }

      vector<int> pre(n);
      o = 0; int j = 0;
      for (char c: s) {
            if (c == '(') o++; else o--;
            if (o < 0) {cout << 0; return 0;}
            pre[j++] = o;
      }
      vector<int> mn(n+1, 5000000);
      for (int i = n-1; i >= 0; i--) {
            mn[i] = min(mn[i+1], pre[i]);
      }

      int ans = 0;
      for (int i = 0; i < n; i++) {
            ans += (s[i] == '(' && mn[i] >= 2);
      }
      cout << ans;

      return 0;
}