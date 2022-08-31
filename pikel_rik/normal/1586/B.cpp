#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(m), b(m), c(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i] >> b[i] >> c[i];
			--a[i], --b[i], --c[i];
		}

		vector<bool> there(n);
		for (int i = 0; i < m; i++) {
			there[b[i]] = true;
		}

		int centre = find(there.begin(), there.end(), false) - there.begin();

		for (int u = 0; u < n; u++) {
			if (u != centre) {
				cout << u + 1 << ' ' << centre + 1 << '\n';
			}
		}
	}
	return 0;
}