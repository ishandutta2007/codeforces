#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for (int &x: a) cin >> x;

	int lo = a[0], hi = a[0];
	for (int i = 1; i < n; i++) {
		lo = max(lo-(k-1), a[i]);
		hi = min(hi, a[i]) + (k-1);
		if (lo > hi) return false;
	}
	return a[n-1] == lo;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}
}