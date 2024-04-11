#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
ll u, v;

void solve() {
	cin >> n >> u >> v;
	a.resize(n);
	for (auto &i : a) cin >> i;
	bool eq = true;
	bool bad = true;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] != a[i]) eq = false;
		if (abs(a[i - 1] - a[i]) >= 2) bad = false;
	}
	if (!bad) {
		cout << "0\n";
		return;
	}
	if (eq) {
		cout << min(v + v, u + v) << '\n';
	}
	else {
		cout << min(u, v) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}