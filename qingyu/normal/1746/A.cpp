#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 1) ok = true;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	}
	return 0;
}