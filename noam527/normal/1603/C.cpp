#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int bestsplit(int n, int upto) {
	return (n + upto - 1) / upto;
}
int cel(int n, int x) {
	return (n + x - 1) / x;
}
int flr(int n, int x) {
	return n / x;
}

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll ans = 0;
	vector<int> splits(n, 1);
	ll cursum = 0;
	ll curadd = 0;
	for (int i = 0; i < n; i++) {
		curadd = (curadd + (ll)(i + 1) * splits[i]) % md;
		cursum += splits[i];
		cursum %= md;
		for (int j = i - 1; j >= 0; j--) {
			if (cel(a[j], splits[j]) > flr(a[j + 1], splits[j + 1])) {
				int x = flr(a[j + 1], splits[j + 1]);
				int m = bestsplit(a[j], x);
				cursum += (m - splits[j]);
				curadd += ll(j + 1) * ll(m - splits[j]);
				cursum %= md;
				if (cursum < 0) cursum += md;
				curadd %= md;
				if (curadd < 0) curadd += md;

				splits[j] = m;
			}
			else
				break;
		}
		if (!OO) {
			cout << "at " << i << '\n';
			for (int j = 0; j <= i; j++) cout << splits[j] << " "; cout << '\n';
			cout << curadd << '\n';
		}
		ans = (ans + curadd) % md;
	}
	ans -= (ll)n * (n + 1) * (n + 2) / 6;
	ans %= md;
	if (ans < 0) ans += md;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}