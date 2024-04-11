#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

ll pw(ll b, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}
ll inv(ll x) {
	return pw(x, md - 2);
}

ll calc(int c1, int c2) {
	ll res = 1;
	ll x = 1, y = 1;
	for (int k = 1; k <= c1 + 1 && k <= c2 + 1; k++) {
		x = x * (c1 + 2 - k) % md * inv(k) % md;
		y = y * (c2 + 2 - k) % md * inv(k) % md;
		res += x * y;
		res %= md;
	}
	return res;
}

int n;
vector<ll> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	if (n == 1) {
		cout << "1\n";
		return;
	}
	if (n == 2) {
		if (a[0] == a[1]) cout << "2\n";
		else cout << "1\n";
		return;
	}
	if (*max_element(a.begin(), a.end()) == 0) {
		cout << pw(2, n - 1) << '\n';
		return;
	}
	int l = 0, r = n - 1;
	ll lsum = a[0], rsum = a.back();
	ll ans = 1;
	while (1) {
		if (lsum == rsum) {
			if (l + 1 == r) {
				ans = 2 * ans % md;
				break;
			}
			if (a[l + 1] > 0 && a[r - 1] > 0) {
				ans = 2 * ans % md;
			}
			else if (a[l + 1] == 0 && a[r - 1] == 0) {
				int cntl = 0, cntr = 0;
				while (l + 1 < r && a[l + 1] == 0) {
					l++;
					cntl++;
				}
				if (l + 1 == r) {
					ans = ans * pw(2, cntl + 1) % md;
					break;
				}
				while (l + 1 < r && a[r - 1] == 0) {
					r--;
					cntr++;
				}
				ans = ans * calc(cntl, cntr) % md;
			}
			else {
				int cnt = 0;
				while (a[l + 1] == 0) {
					cnt++;
					l++;
				}
				while (a[r - 1] == 0) {
					cnt++;
					r--;
				}
				ans = (2 + cnt) * ans % md;
			}
			l++, r--;
			if (l == r) {
				break;
			}
			lsum = a[l];
			rsum = a[r];
			continue;
		}
		if (l + 1 == r) {
			break;
		}
		if (lsum < rsum) {
			l++;
			lsum += a[l];
		}
		else {
			r--;
			rsum += a[r];
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}