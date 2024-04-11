#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 31607;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

ll pw(ll b, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}
ll inv(ll x) {
	return pw(x, md - 2);
}

int f(int x) {
	return x & 1;
}
int g(int x) {
	return x & 2;
}

const int B = 21;
const int L = 1 << B;

int lg2[L], cnt[L];

int n;
int a[B][B];
int rows[4][B];
short int cols[4][B][L];
int D1 = 1, D2 = 1, D12 = 1;

int col_work(int t, int mask) {
	mask ^= ((1 << n) - 1);
	int res = 0;
	int prod = 1;
	for (int j = 0; j < n; j++) {
		res = (res + prod * (int)cols[t][j][mask]) % md;
		prod = (prod * (1 - (int)cols[t][j][mask]) % md + md) % md;
	}
	return res;
}

void solve() {
	for (int i = 0; i < B; i++)
		lg2[1 << i] = i;
	for (int i = 1; i < L; i++)
		cnt[i] = 1 + cnt[i ^ (i & -i)];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] = a[i][j] * inv(10000) % md;
		}
	}

	for (int i = 0; i < n; i++)
		D1 = D1 * a[i][i] % md;
	for (int i = 0; i < n; i++)
		D2 = D2 * a[n - 1 - i][i] % md;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j || i + j == n - 1)
			D12 = D12 * a[i][j] % md;
	}
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < n; i++) {
			rows[t][i] = 1;
			for (int j = 0; j < n; j++) {
				if ((f(t) && i == j) || (g(t) && i + j == n - 1))
					continue;
				rows[t][i] = rows[t][i] * a[i][j] % md;
			}
			if (OO) {
				cout << "rows " << t << " " << i << ": " << rows[t][i] << '\n';
			}
		}
	}

	for (int t = 0; t < 4; t++) {
		for (int j = 0; j < n; j++) {
			cols[t][j][0] = 1;
			for (int mask = 1; mask < (1 << n); mask++) {
				int prod = 1;
				int b = mask & -mask;
				int i = lg2[b];
				if (!((f(t) && i == j) || (g(t) && i + j == n - 1))) {
					prod = a[i][j];
				}
				cols[t][j][mask] = (int)cols[t][j][mask ^ b] * prod % md;

				if (OO) {
					cout << "cols " << t << " " << j << " " << mask << ": " << cols[t][j][mask] << '\n';
				}
			}
		}
	}

	ll ans = 0;
	for (int t = 0; t < 4; t++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			int sum = 0, prod = 1;
			if (t == 3) {
				sum = 2;
				prod = D12;
			}
			else if (f(t)) {
				sum++;
				prod = prod * D1 % md;
			}
			else if (g(t)) {
				sum++;
				prod = prod * D2 % md;
			}

			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) prod = prod * rows[t][i] % md, sum++;
			}
			if (sum & 1) ans -= col_work(t, mask) * prod % md;
			else ans += col_work(t, mask) * prod % md;

			if (sum & 1) ans += prod % md;
			else ans -= prod % md;

			if (OO) {
				cout << "t mask ans: " << t << " " << mask << " " << ans << '\n';
			}
		}
	}
	cout << ((ans + 1) % md + md) % md << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}