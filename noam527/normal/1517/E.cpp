#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

int n;
vector<ll> a;
vector<ll> suf;

int atmost(int i, int Clast) {
	if (!Clast) return (n - i) / 2;
	if (i >= n - 2)
		return (n - i) / 2;
	return (n - i - 1) / 2;
}
ll sum(int i, int len) {
	if (i + 2 * len >= n) return suf[i];
	return suf[i] - suf[i + 2 * len];
}
int length(ll can, int i, int Clast) {
	if (a[i] > can) return 0;
	int lo = 1, hi = atmost(i, Clast), mid;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		if (sum(i, mid) <= can) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}



int bruteforce() {
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> c, p;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) c.push_back(j);
			else p.push_back(j);
		}
		int good = 1;
		for (int j = 1; j + 1 < c.size() && good; j++) {
			if (c[j] - c[j - 1] > c[j + 1] - c[j])
				good = 0;
		}
		for (int j = 1; j + 1 < p.size() && good; j++) {
			if (p[j] - p[j - 1] < p[j + 1] - p[j]) {
				good = 0;
			}
		}
		if (!good) continue;
		ll C = 0, P = 0;
		for (auto &j : c) C += a[j];
		for (auto &j : p) P += a[j];
		if (C < P) {
			ans++;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) cout << "C";
				else cout << "P";
			}
			cout << '\n';
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	a.resize(n);
	ll total = 0;
	for (auto &i : a) cin >> i, total += i;
	if (n == 1) {
		cout << "1\n";
		return;
	}
	if (n == 2) {
		if (a[0] == a[1]) cout << "1\n";
		else cout << "2\n";
		return;
	}

	suf.resize(n);
	suf[n - 1] = 0;
	suf[n - 2] = a[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		suf[i] = a[i] + suf[i + 2];
	}

	ll ans = 0;
	// PP
	ll cur = 0;
	for (int i = 1; i <= n - 2; i++) {
		// last C on i
		ll can = (total - 1) / 2 - cur;
		if (can < 0) break;
		if (OO) cout << "a " << i << " " << length(can, i, 0) << '\n';
		ans += length(can, i, 0);
		cur += a[i];
	}
	// PC
	cur = 0;

	// this is also for CP
	for (int i = n - 1; i >= 0; i--) {
		cur += a[i];
		if (2 * cur != total) ans++;
	}

	cur = a[n - 1];
	for (int i = 1; i <= n - 3; i++) {
		// last C on i
		ll can = (total - 1) / 2 - cur;
		if (can < 0) break;
		if (OO) cout << "b " << i << " " << length(can, i, 1) << '\n';
		ans += length(can, i, 1);
		cur += a[i];
	}

	// CP
	cur = 0;
	for (int i = 0; i <= n - 2; i++) {
		// last C on i
		ll can = (total - 1) / 2 - cur;
		if (can < 0) break;
		
		ans += max(length(can, i, 0) - 1, 0);
		cur += a[i];
	}
	
	// CC
	cur = a[n - 1];
	for (int i = 0; i <= n - 3; i++) {
		// last C on i
		ll can = (total - 1) / 2 - cur;
		if (can < 0) break;

		ans += max(length(can, i, 1), 0);
		cur += a[i];
	}
	
	cout << ans % md << '\n';
	//cout << bruteforce() << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}