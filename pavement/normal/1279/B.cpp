#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], p[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, s;
	cin >> t;
	while (t--) {
		int maxans = -1, skp = 0;
		cin >> n >> s;
		for (int i = 0; i < n; i++) cin >> a[i];
		p[0] = a[0];
		for (int i = 1; i < n; i++)
			p[i] = a[i] + p[i - 1];
		if (p[n - 1] <= s) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (p[i] <= s) maxans = i + 1;
		}
		for (int i = 0; i < n; i++) {
			int lo = i + 1, hi = n - 1, ans = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (p[mid] - a[i] <= s) ans = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			if (ans > maxans) maxans = ans, skp = i + 1;
		}
		cout << skp << '\n';
	}
}