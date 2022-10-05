#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

int n, k;
vector<ll> a;

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll cur = 0, ans = 0;
	sort(a.begin(), a.end());
	while (a.size() && cur >= 0) {
		ans += cur;
		cur += a.back();
		a.pop_back();
	}
	if (k == 0) {
		while (a.size()) {
			ans += cur;
			cur += a.back();
			a.pop_back();
		}
	}
	if (!a.size()) {
		cout << ans << '\n';
		return;
	}
	k++;
	cur = -cur;
	for (auto &i : a) i = -i;
	while (a.size() % k != 0) {
		a.push_back(0);
	}
	n = a.size();

	if (OO) {
		cout << "ans " << ans << '\n';
		cout << "k cur " << k << " " << cur << '\n';
		for (const auto &i : a) cout << i << " "; cout << '\n';
	}

	vector<ll> pref(n, inf), suf(n);
	vector<ll> sums = a;
	for (int i = n - 2; i >= 0; i--) sums[i] += sums[i + 1];
	
	for (int i = k - 1; i < n; i += k) {
		ll add = sums[i - (k - 1)];
		if (i + 1 < n) add -= sums[i + 1];
		pref[i] = (i / k) * add;
		if (i - k >= 0) pref[i] += pref[i - k];
	}

	for (int i = n - 1; i >= 0; i--) {
		suf[i] = 0;
		if (i + k - 1 >= n) continue;
		suf[i] = suf[i + k - 1] + sums[i + k - 1];
	}
	
	if (OO) {
		cout << "pref suf:\n";
		for (const auto &i : pref) cout << i << " "; cout << '\n';
		for (const auto &i : suf) cout << i << " "; cout << '\n';
	}

	ll mn = inf;
	for (int use = 0; use < n; use++) {
		ll i = k * use - 1;
		if (i >= n) break;
		ll res = 0;
		res += cur * use;
		if (i >= 0) res += pref[i];
		if (i + 1 < n) res += suf[i + 1] + (ll)use * sums[i + 1];
		mn = min(mn, res);
	}
	cout << ans - mn << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}