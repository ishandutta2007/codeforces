#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, prev = 0, mx = 0; cin >> n; stack<int> s;
      while (cin >> n) {
            mx = max(mx, n);
            if (s.empty() || s.top() != n) {s.push(n); prev = 0;}
            else if (s.top() == n) {
                  if (n >= prev) {
                        s.pop(); prev = n;
                  } else {
                        cout << "NO"; return 0;
                  }
            }
      }
      if (s.empty()) {cout << "YES"; return 0;}
      if (s.size() == 1) {
            cout << (s.top() == mx ? "YES" : "NO");
      } else {
            cout << "NO";
      }

	return 0;
}