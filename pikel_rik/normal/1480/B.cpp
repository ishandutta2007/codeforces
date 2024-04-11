#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long A, B; int n;
		cin >> A >> B >> n;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		for (int i = 0; i < n; i++) {
			int times = (b[i] + A - 1) / A;
			B -= (long long)times * a[i];
		}

		cout << (B > -*max_element(a.begin(), a.end()) ? "YES" : "NO") << '\n';
	}
	return 0;
}