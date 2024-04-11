#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

int n;
vector<ll> a;
vector<int> nxt;

void update() {
	if (a[n - 1] == 1) nxt[n - 1] = n;
	else nxt[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == 1) nxt[i] = nxt[i + 1];
		else nxt[i] = i;
	}
}

void walk(int i, bool &found) {
	i = nxt[i];
	found = false;
	while (i < n) {
		int prev = a[i];
		if (a[i] >= 2)
			a[i]--;
		if (a[i] == 1) found = true;
		i += prev;
		if (i < n) i = nxt[i];
	}
}

void solve() {
	cin >> n;
	a.resize(n);
	nxt.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < n; i++) nxt[i] = i;

	update();
	bool found;
	ll ans = 0;
	while (nxt[0] < n) {
		if (OO) {
			cout << "ans " << ans << '\n';
			for (const auto &i : a) cout << i << " "; cout << '\n';
			for (const auto &i : nxt) cout << i << " "; cout << '\n';
		}
		int i = nxt[0];
		if (a[i] > n) {
			ans += a[i] - n;
			a[i] = n;
			if (n == 1) update();
			continue;
		}
		walk(i, found);
		ans++;
		if (found) update();
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}