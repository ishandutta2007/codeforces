#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

ll n, k;
vector<ll> a, ps;

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ps.resize(n);
	ps[0] = a[0];
	for (int i = 1; i < n; i++)
		ps[i] = ps[i - 1] + a[i];
	if (k >= n) {
		cout << ps.back() + k * n - n * (n + 1) / 2 << '\n';
		return;
	}
	ll best = ps[k - 1];
	for (int i = k; i < n; i++)
		best = max(best, ps[i] - ps[i - k]);
	cout << best + k * (k - 1) / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}