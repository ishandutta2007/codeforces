
#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, t;
	cin >> t;
	while (t--) {
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0 ; i < n ; i++) {
      cin >> a[i];
    }

    int x = 0;
    for (int i = 0; i < n-1; ++i) {
      x ^= a[i];
    }
    if (a[n - 1] == x) {
      cout << "YES" << endl;
    }
    else {
      vector<int> pref(n+1);
      for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i]^a[i];
      }

      bool yes = 0;
      for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          int x = pref[i], y = pref[j] ^ pref[i], z = pref[n] ^ pref[j];
          if (x == y && y == z) {
            yes = 1; break;
          }
        }
        if (yes) break;
      }

      if (yes) cout << "YES\n";
      else cout << "NO\n";
    }
	}
	return 0;
}