#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5000 + 5;

int n, m, s[N], f[N], h[N], lft[N], rght[N];
vector<int> sw[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < m; i++) {
		cin >> f[i] >> h[i];
		sw[f[i]].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int cur = h[i];
		for (int j = 0; j < n; j++) {
			if (s[j] == f[i]) {
				cur--;
			}
			if (cur == 0) {
				lft[i] = j;
				break;
			}
		}
		if (cur) {
			lft[i] = n;
		}

		cur = h[i];
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] == f[i]) {
				cur--;
			}
			if (cur == 0) {
				rght[i] = j;
				break;
			}
		}
		if (cur) {
			rght[i] = -1;
		}
	}

	int ans1 = 0, ans2 = 1;
	for (int i = 0; i < n; i++) {
		int mx = 0, ways = 1;
		int pos = -1;
		for (int j = 0; j < m; j++) {
			if (rght[j] == i) {
				pos = j;
			}
		}
		if (pos == -1) continue;
		for (int sw_val = 1; sw_val <= n; sw_val++) {
			int l = 0, r = 0, both = 0;
			for (int x : sw[sw_val]) {
				if (lft[x] < i && rght[x] >= i) {
					both++;
				} else {
					l += lft[x] < i;
					r += rght[x] >= i;
				}
			}
			if (f[pos] == sw_val) {
				if (lft[pos] < i) {
					both--;
				}
				r = 1;
				l += both;
				both = 0;
			}
			int temp = min(2, min(1, l) + min(1, r) + min(2, both));
			if (temp == 2) {
				ways = (ll)ways * (l * r + l * both + r * both + both * both - both) % mod;
			} else if (temp == 1) {
				ways = (ll)ways * (l + r + 2 * both) % mod;
			}
			mx += temp;
		}
		if (mx > ans1) {
			ans1 = mx;
			ans2 = ways;
		} else if (mx == ans1) {
			ans2 = (ans2 + ways) % mod;
		}
	}

	int mx = 0, ways = 1;
	for (int sw_val = 1; sw_val <= n; sw_val++) {
		int l = 0;
		for (int x : sw[sw_val]) {
			l += lft[x] < n;
		}
		if (l) {
			mx++;
			ways = (ll) ways * l % mod;
		}
	}

	if (mx > ans1) {
		ans1 = mx;
		ans2 = ways;
	} else if (mx == ans1) {
		ans2 = (ans2 + ways) % mod;
	}

	if (ans1 == 0) {
		ans2 = 1;
	}

	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}