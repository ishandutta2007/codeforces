#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, d, m;
vector<ll> a, b;

void solve() {
	cin >> n >> d >> m;
	d++;
	a.clear();
	b.clear();
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x > m) a.push_back(x);
		else b.push_back(x);
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
	ll ans = 0;
	ll sum = 0;
	for (int use = 0; use <= b.size(); use++) {
		int left = n - use;
		int can = (left + d - 1) / d;
		if (min((int)a.size() - 1, can - 1) >= 0)
			ans = max(ans, sum + a[min((int)a.size() - 1, can - 1)]);
		else
			ans = max(ans, sum);

		if (use < b.size())
			sum += b[use];
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}