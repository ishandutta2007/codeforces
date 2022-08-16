#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, d;
		cin >> n >> d;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int g = __gcd(d, n), ans = 0;

		vector<bool> visited(n);
		for (int i = 0; i < g; i++) {
			vector<int> v; v.reserve(n / g);
			for (int j = i; !visited[j]; j = (j + d) % n) {
				visited[j] = true;
				v.push_back(a[j]);
			}
			reverse(v.begin(), v.end());
			if (count(v.begin(), v.end(), 1) == n / g) {
				ans = -1;
				break;
			}

			vector<int> dist(n / g, n + 1);
			int mn = n + 1;

			for (int j = 0, k = 0; k < 2 * (n / g); j++, k++) {
				if (j == n / g) j = 0;
				if (v[j] == 0) {
					mn = 0;
				} else {
					mn += 1;
				}
				dist[j] = min(dist[j], mn);
			}

			ans = max(ans, *max_element(dist.begin(), dist.end()));
		}
		cout << ans << '\n';
	}
	return 0;
}