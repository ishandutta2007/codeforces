#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n; stack<int> s;
      while (cin >> n) {
            n %= 2;
            if (s.empty() || s.top() != n) s.push(n);
            else s.pop();
      }
      cout << (s.size() <= 1 ? "YES" : "NO");

	return 0;
}