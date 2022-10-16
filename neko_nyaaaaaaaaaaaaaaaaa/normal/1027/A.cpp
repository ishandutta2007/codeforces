#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string a, b, c;
	cin >> c;
	a = c; b = c;
	for (int i = 0; i < n; i++) {
		if (c[i] == 'a') {
			a[i] = 'b'; b[i] = 'b';
		} else if (c[i] == 'z') {
			a[i] = 'y'; b[i] = 'y';
		} else {
			a[i] = c[i] - 1;
			b[i] = c[i] + 1;
		}
	}
	
	for (int i = 0, j = n-1; i < j; i++, j--) {
		if (a[i] == b[j] || a[i] == a[j] || a[j] == b[i] || b[i] == b[j]) continue;
		cout << "NO\n"; return;
	}
	
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}