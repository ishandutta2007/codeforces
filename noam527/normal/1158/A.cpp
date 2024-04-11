#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<ll> a, b;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.back() > b[0]) finish(-1);
	if (a.back() == b[0]) {
		ll ans = 0;
		for (auto &i : b) ans += i;
		for (int i = 0; i < n - 1; i++)
			ans += a[i] * m;
		finish(ans);
	}
	if (n == 1) finish(-1);
	ll ans = 0;
	for (auto &i : b) ans += i;
	ans -= b[0];
	ans += a.back();
	ans += b[0];
	ans += a[n - 2] * (m - 1);
	for (int i = 0; i < n - 2; i++)
		ans += a[i] * m;
	finish(ans);
}