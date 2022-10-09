#include <bits/stdc++.h>

using namespace std; // i don't like it anyway...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n), r(n, 0);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int rem = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] <= rem)
				r[i] = 1;
			else if (rem < q)
				r[i] = 1, ++rem;
		}
		for (int i = 0; i < n; ++i) cout << r[i];
		cout << '\n';
	}
}