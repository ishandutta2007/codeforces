#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

const int N = 100005, L = 17, M = 20;

int lg2[N];
int mn[L][N], mx[L][N];

int n, q;
vector<int> a;

pair<int, int> up[M][L][N];

void split(int l, int r, int &b, int &i1, int &i2) {
	b = lg2[r - l + 1];
	i1 = l;
	i2 = r - (1 << b) + 1;
}

void query(int l, int r, int &l2, int &r2) {
	int b, i1, i2;
	split(l, r, b, i1, i2);
	l2 = min(mn[b][i1], mn[b][i2]);
	r2 = max(mx[b][i1], mx[b][i2]);
}

void prep() {
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;

	int found = 0;
	for (auto &i : a) {
		if (i == 0) found |= 1;
		if (i == n - 1) found |= 2;
	}
	if (found != 3) {
		while (q--) {
			int l, r;
			cin >> l >> r;
			if (l == 1 && r == n) {
				cout << "0\n";
			}
			else {
				cout << "-1\n";
			}
		}
		exit(0);
	}

	lg2[1] = 0;
	for (int i = 2; i < N; i++) lg2[i] = 1 + lg2[i / 2];
	for (int i = 0; i < n; i++) {
		mn[0][i] = mx[0][i] = a[i];
	}
	for (int b = 1, len = 2; len <= n; b++, len *= 2) {
		for (int i = 0; i + len <= n; i++) {
			mn[b][i] = min(mn[b - 1][i], mn[b - 1][i + len / 2]);
			mx[b][i] = max(mx[b - 1][i], mx[b - 1][i + len / 2]);
		}
	}
	int l, r, b, i1, i2;
	for (int i = 0, len = 1; len <= n; i++, len *= 2) for (int j = 0; j + len <= n; j++) {
		query(j, j + len - 1, l, r);
		up[0][i][j] = { l, r };
		if (OO) cout << i << " " << j << " to " << l << " " << r << '\n';
	}
	for (int k = 1; k < M; k++) {
		for (int i = 0, len = 1; len <= n; i++, len *= 2) for (int j = 0; j + len <= n; j++) {
			if (OO) cout << "process " << k << " " << i << " " << j << '\n';
			int l3, r3, l4, r4;
			l = up[k - 1][i][j].first, r = up[k - 1][i][j].second;
			if (OO) cout << "l r " << l << " " << r << '\n';
			split(l, r, b, i1, i2);
			l3 = up[k - 1][b][i1].first, r3 = up[k - 1][b][i1].second;
			l4 = up[k - 1][b][i2].first, r4 = up[k - 1][b][i2].second;
			up[k][i][j] = { min(l3, l4), max(r3, r4) };
		}
	}
}

ll query(int l, int r) {
	if (l == 0 && r == n - 1) return 0;
	ll cur = 0;
	int l2, r2, l3, r3;
	for (int i = M - 1; i >= 0; i--) {
		if (OO) cout << "starting " << l << " " << r << '\n';
		int b, i1, i2;
		split(l, r, b, i1, i2);
		l2 = up[i][b][i1].first;
		r2 = up[i][b][i1].second;
		l3 = up[i][b][i2].first;
		r3 = up[i][b][i2].second;
		l2 = min(l2, l3);
		r2 = max(r2, r3);
		if (OO) cout << "in " << (1 << i) << " steps we reach " << l2 << " " << r2 << '\n';
		if (l2 != 0 || r2 != n - 1) {
			cur += (1LL << (ll)i);
			l = l2, r = r2;
		}
	}
	return cur + 1;
}

void solve() {
	prep();
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		ll res = query(l, r);
		if (res == (1 << M)) cout << "-1\n";
		else cout << res << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}