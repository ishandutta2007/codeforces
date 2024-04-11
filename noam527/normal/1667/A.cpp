#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<ll> a, b;

ll calc1(int i) {
	ll cur = 0, ans = 0;
	for (int j = i; j >= 0; j--) {
		ans += cur / a[j] + 1;
		cur = a[j] * (cur / a[j] + 1);
	}
	return ans;
}
ll calc2(int i) {
	ll cur = 0, ans = 0;
	for (int j = i; j < n; j++) {
		ans += cur / a[j] + 1;
		cur = a[j] * (cur / a[j] + 1);
	}
	return ans;
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll ans = inf;
	for (int i = 0; i < n; i++) {
		ans = min(ans, calc1(i - 1) + calc2(i + 1));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}