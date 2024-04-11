#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	bool res = false;
	for (int b = a[0]-1; b <= a[0]+1; b++) {
		bool cur = true;
		for (int i = 0; i < n; i++) {
			if (abs(a[i]-(b+i)) > 1) cur = false;
		}
		if (cur) res = true;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}