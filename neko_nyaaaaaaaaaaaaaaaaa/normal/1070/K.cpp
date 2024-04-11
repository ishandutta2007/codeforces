#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, k, s = 0; cin >> n >> k;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {cin >> a[i]; s += a[i];}

      if (s % k) {cout << "No"; return 0;}

      vector<int> ans;
      int t = s/k;
      int cur = 0;
      int b = 0;
      for (int i = 0; i < n; i++) {
            cur += a[i]; b++;
            if (cur > t) {cout << "No"; return 0;}
            if (cur == t) {ans.push_back(b); b = 0; cur = 0;}
      }
      if (cur) {cout << "No"; return 0;}
      cout << "Yes\n";
      for (int i: ans) cout << i << ' ';

      return 0;
}