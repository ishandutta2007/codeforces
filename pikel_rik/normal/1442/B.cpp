#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n), b(k);
		for (auto &i : a) cin >> i, --i;
		for (auto &i : b) cin >> i, --i;

		vector<int> pos(n), posb(n, -1);
		for (int i = 0; i < n; i++) {
			pos[a[i]] = i;
		}
		for (int i = 0; i < k; i++) {
			posb[b[i]] = i;
		}

		ll ans = 1;
		for (int i = 0; i < n; i++) {
			if (posb[a[i]] == -1) continue;
			if ((i == 0 || posb[a[i - 1]] > posb[a[i]]) && (i + 1 == n || posb[a[i + 1]] > posb[a[i]])) {
				ans = 0;
				break;
			}
			if (i > 0 && posb[a[i - 1]] < posb[a[i]] && i + 1 < n && posb[a[i + 1]] < posb[a[i]]) {
				ans = ans * 2 % mod;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}