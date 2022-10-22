#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int c1, c2, c3; cin >> c1 >> c2 >> c3;
		int a1, a2, a3, a4, a5; cin >> a1 >> a2 >> a3 >> a4 >> a5;
		if (a1 > c1 || a2 > c2 || a3 > c3) {
			cout << "NO\n";
			continue;
		}
		c1 -= a1, c2 -= a2, c3 -= a3;
		a4 -= c1, a5 -= c2;
		cout << (max(a4, 0) + max(a5, 0) <= c3 ? "YES" : "NO") << "\n";
	}
	return 0;
}