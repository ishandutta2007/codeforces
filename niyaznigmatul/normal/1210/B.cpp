/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<int> bits(n);
	map<long long, int> cn;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bits[i] = __builtin_popcountll(a[i]);
		cn[a[i]]++;
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> was(n);
	long long ans = 0;
	while (true) {
		int mx = -1;
		for (int i = 0; i < n; i++) {
			if (was[i]) continue;
			if (mx < 0 || bits[i] > bits[mx]) mx = i;
		}
		if (mx < 0) break;
		long long x = a[mx];
		if (cn[x] == 1) {
			was[mx] = true;
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (was[i]) continue;
			long long y = a[i];
			if ((x & y) == y) {
				ans += b[i];
				was[i] = true;
			}
		}
	}
	cout << ans << endl;
}