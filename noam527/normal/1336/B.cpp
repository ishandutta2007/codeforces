#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 6e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n[3];
vector<ll> a[3];

int least(int i, ll v) {
	return lower_bound(a[i].begin(), a[i].end(), v) - a[i].begin();
}
int more(int i, ll v) {
	return upper_bound(a[i].begin(), a[i].end(), v) - a[i].begin();
}
int upto(int i, ll v) {
	return more(i, v) - 1;
}
int less(int i, ll v) {
	return least(i, v) - 1;
}
ll sqr(ll x) {
	return x * x;
}
ll sum(ll x, ll y, ll z) {
	return sqr(x - y) + sqr(x - z) + sqr(y - z);
}

void solve() {
	cin >> n[0] >> n[1] >> n[2];
	for (int i = 0; i < 3; i++) {
		a[i].resize(n[i]);
		for (auto &j : a[i]) cin >> j;
		sort(a[i].begin(), a[i].end());
	}
	vector<pair<ll, int>> v;
	for (int i = 0; i < 3; i++) {
		for (auto &j : a[i])
			v.emplace_back(j, i);
	}
	sort(v.begin(), v.end());
	if (OO) {
		cout << "v:\n";
		for (const auto &i : v) cout << i.first << " " << i.second << endl;
	}
	ll ans = inf;
	for (int i = 2; i < v.size(); i++) {
		int u1, u2;
		int j = (v[i].second + 1) % 3, k = (v[i].second + 2) % 3;
		u1 = upto(j, v[i].first), u2 = upto(k, v[i].first);
		if (u1 == -1 || u2 == -1) continue;
		
		ll x = (a[j][u1] + v[i].first) / 2;
		int i1 = upto(k, x), i2 = more(k, x);
		if (0 <= i1 && i1 < a[k].size())
			ans = min(ans, sum(a[k][i1], a[j][u1], v[i].first));
		if (0 <= i2 && i2 < a[k].size())
			ans = min(ans, sum(a[k][i2], a[j][u1], v[i].first));

		x = (a[k][u2] + v[i].first) / 2;
		i1 = upto(j, x), i2 = more(j, x);
		if (0 <= i1 && i1 < a[j].size())
			ans = min(ans, sum(a[j][i1], a[k][u2], v[i].first));
		if (0 <= i2 && i2 < a[j].size())
			ans = min(ans, sum(a[j][i2], a[k][u2], v[i].first));
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) solve();
}