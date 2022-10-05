#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, p, k;
ll x, y;
vector<int> a;

void solve() {
	cin >> n >> p >> k;
	a.resize(n);
	for (auto &i : a) {
		char c;
		cin >> c;
		i = c - '0';
	}
	cin >> x >> y;
	ll ans = inf;
	vector<int> cnt(n, 0);
	for (int i = n - 1; i >= p - 1; i--) {
		cnt[i] = 1 - a[i];
		if (i + k < n) cnt[i] += cnt[i + k];
		ll cur = x * cnt[i];
		cur += max(0, i - (p - 1)) * y;
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}