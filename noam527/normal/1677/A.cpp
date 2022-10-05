#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a, ps;

void solve() {
	cin >> n;
	a.resize(n);
	ps.resize(n + 1);
	for (auto &i : a) cin >> i;
	ll ans = 0;
	for (int c = 2; c + 1 < n; c++) {
		for (auto &i : ps) i = 0;
		for (int j = c + 1; j < n; j++)
			ps[a[j]]++;
		for (int j = 1; j <= n; j++)
			ps[j] += ps[j - 1];
		ll cur = 0;
		for (int st = c - 2; st >= 0; st--) {
			int x = a[st + 1];
			cur += ps[x];
			if (a[st] < a[c])
				ans += cur;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}