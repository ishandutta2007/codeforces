#include <bits/stdc++.h>

using namespace std; // I don't like this anyway...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m, 1);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			--x;
			x = min(x, m - 1 - x);
			if (a[x] == 1) a[x] = 0;
			else a[m - 1 - x] = 0;
		}
		for (int i = 0; i < m; ++i)
			cout << (a[i] == 1 ? 'B' : 'A');
		cout << '\n';
	}
}