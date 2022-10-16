#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, s; cin >> n >> s;
      vector<int> a(n), b(n);
      for (int i = 0; i < n; i++) cin >> a[i];
      for (int i = 0; i < n; i++) cin >> b[i];

      if (a[0] == 0) {cout << "NO\n"; return 0;}
      if (a[s-1] == 1) {cout << "YES\n"; return 0;}

      if (b[s-1] == 0) {cout << "NO"; return 0;}
      for (int i = s; i < n; i++) {
            if (a[i] && b[i]) {cout << "YES"; return 0;}
      }
      cout << "NO";

      return 0;
}