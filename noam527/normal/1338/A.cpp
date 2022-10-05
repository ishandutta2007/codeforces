#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;

int calc(int x) {
	if (x == 0) return 0;
	return 1 + calc(x / 2);
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int mx = a[0], ans = 0;
	for (int i = 1; i < n; i++) {
		if (mx > a[i]) ans = max(ans, calc(mx - a[i]));
		else mx = a[i];
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) solve();
}