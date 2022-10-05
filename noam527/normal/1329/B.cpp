#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int d, m;

void solve() {
	cin >> d >> m;
	vector<ll> a;
	int lo = 1, hi = 2;
	while (lo <= d) {
		a.push_back(min(d + 1, hi) - lo);
		lo *= 2, hi *= 2;
	}
	ll ans = 1;
	for (auto &i : a)
		ans = (ans * (1 + i)) % m;
	ans = (ans - 1 + m) % m;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}