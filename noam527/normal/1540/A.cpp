#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<ll> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	ll ans = 0;
	ll cur = 0;
	for (int i = 1; i < n; i++) {
		cur += a[i - 1];
		ans -= (ll)i * a[i] - cur;
	}
	cout << ans + a.back() << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}