#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;

void solve() {
	cin >> n;
	vector<int> t(n), p(n);
	for (auto &i : t) cin >> i;
	for (auto &i : p) cin >> i;

	vector<int> c0, c1;
	ll ans = 0, sum = 0;
	for (auto &i : p) sum += i;

	for (int i = 0; i < n; i++) {
		if (t[i] == 0) c0.push_back(p[i]);
		else c1.push_back(p[i]);
	}
	sort(c0.rbegin(), c0.rend());
	sort(c1.rbegin(), c1.rend());
	if (c0.size() != c1.size()) {
		ans = sum;
		if (c0.size() < c1.size()) swap(c0, c1);
		for (int i = 0; i < c1.size(); i++) {
			ans += c0[i];
			ans += c1[i];
		}
		cout << ans << '\n';
		return;
	}
	ans = 2 * sum - min(c0.back(), c1.back());
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}