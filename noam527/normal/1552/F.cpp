#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> x, y, s;
vector<ll> D, p;

void solve() {
	cin >> n;
	x.resize(n);
	y.resize(n);
	s.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> s[i];
	}
	D.resize(n);
	p.resize(n);
	D[0] = (x[0] - y[0]) % md;
	p[0] = D[0];
	for (int i = 1; i < n; i++) {
		int j = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
		D[i] = x[j] - y[i] + x[i] - x[j];
		D[i] += p[i - 1];
		if (j > 0) D[i] -= p[j - 1];
		D[i] %= md;
		D[i] += md;
		D[i] %= md;
		p[i] = (p[i - 1] + D[i]) % md;
	}
	ll ans = 0;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + x[i] - cur) % md;
		if (s[i] == 1) ans = (ans + D[i]) % md;
		cur = x[i];
	}
	ans = (ans + 1) % md;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//srand(time(NULL));
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}