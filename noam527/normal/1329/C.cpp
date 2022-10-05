#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<int> a;

bool can(int x) {
	if (x > m) {
		if (a[x] == 0) return false;
		return true;
	}
	if (a[2 * x] > a[2 * x + 1])
		return can(2 * x);
	return can(2 * x + 1);
}
void work(int x) {
	if (a[x] == 0) return;
	if (x > n / 2) {
		a[x] = 0;
		return;
	}
	if (a[2 * x] > a[2 * x + 1]) {
		a[x] = a[2 * x];
		work(2 * x);
	}
	else {
		a[x] = a[2 * x + 1];
		work(2 * x + 1);
	}
}

void solve() {
	cin >> n >> m;
	n = (1 << n) - 1, m = (1 << m) - 1;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> op;
	for (int i = 1; i <= n; i++) {
		while (can(i)) {
			work(i);
			op.push_back(i);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans += a[i];
	cout << ans << endl;
	for (const auto &i : op) cout << i << " "; cout << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}