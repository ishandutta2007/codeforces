#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

ll pw(ll b, ll e) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}

ll inv(ll x) {
	return pw(x, md - 2);
}

const int N = 14, L = 1 << N;

int n;
vector<ll> a;
ll prob[15][15];

int p[L];
int exists[L][N];

vector<int> subs[L];
int bitcnt[L];
int lg2[L];

ll calc(int st) {
	//cout << "calc " << st << '\n';
	for (int mask = 0; mask < (1 << n); mask++) {
		if (((1 << st) & mask) == 0) continue;
		if ((1 << st) == mask) {
			p[mask] = 1;
			continue;
		}
		//cout << "calculating " << mask << '\n';
		p[mask] = 0;
		int mm = mask ^ (1 << st);
		for (auto &sub : subs[mm]) {
			if (!sub) continue;
			//cout << "subset " << sub << '\n';
			int cur = 1;
			int cursub = sub;
			while (cursub) {
				cur = (ll)cur * exists[mask ^ sub][lg2[cursub & -cursub]] % md;
				cursub ^= (cursub & -cursub);
			}
			//cout << "prob of exist " << cur << '\n';
			if (bitcnt[sub] & 1) {
				p[mask] = ((ll)p[mask] + (ll)p[mask ^ sub] * cur) % md;
			}
			else {
				p[mask] = ((ll)p[mask] - (ll)p[mask ^ sub] * cur) % md;
				if (p[mask] < 0) p[mask] += md;
			}
		}
	}
	return p[(1 << n) - 1];
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			prob[i][j] = a[i] * inv(a[i] + a[j]) % md;
		}
	}

	for (int mask = 1; mask < (1 << n); mask++) {
		for (int v = 0; v < n; v++) {
			if (mask & (1 << v)) continue;
			exists[mask][v] = 1;
			for (int u = 0; u < n; u++) {
				if (mask & (1 << u))
					exists[mask][v] = (ll)exists[mask][v] * prob[v][u] % md;
			}
			exists[mask][v] = (1 - exists[mask][v] + md) % md;
		}
	}
	//cout << exists[1][2] << '\n';
	bitcnt[0] = 0;
	lg2[0] = -1;
	for (int mask = 1; mask < (1 << n); mask++) {
		bitcnt[mask] = 1 + bitcnt[mask ^ (mask & -mask)];
		lg2[mask] = 1 + lg2[mask / 2];
	}
	subs[0] = { 0 };
	for (int mask = 1; mask < (1 << n); mask++) {
		int b = (mask & -mask);
		subs[mask].reserve(2 * (int)subs[mask ^ b].size());
		for (auto &x : subs[mask ^ b]) {
			subs[mask].push_back(x), subs[mask].push_back(x | b);
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + calc(i)) % md;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}