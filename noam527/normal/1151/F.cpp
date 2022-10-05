#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
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

struct matrix {
	int n, m;
	vector<vector<ll>> a;
	matrix() {}
	matrix(int nn, int mm) {
		n = nn;
		m = mm;
		a.resize(n, vector<ll>(m, 0));
	}
	vector<ll>& operator [](int i) {
		return a[i];
	}
	matrix operator * (matrix &b) const {
		matrix rtn(n, b.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < b.m; j++)
			for (int k = 0; k < m; k++)
				rtn[i][j] = (rtn[i][j] + a[i][k] * b[k][j]) % md;
		return rtn;
	}
};

int c2(int x) {
	return x * (x - 1) / 2;
}

int n, k, X = 0, Y = 0;
vector<int> a;
ll I;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		if (i == 0) X++;
		else Y++;
	}
	int mis = 0, mx = min(X, Y);
	for (int i = X; i < n; i++)
		if (a[i] == 0) mis++;
	I = inv(n * (n - 1) / 2);

	matrix ans(1, mx + 1);
	ans[0][mis] = 1;
	matrix b(mx + 1, mx + 1);
	for (int i = 0; i <= mx; i++) {
		// l: (X - i, i)
		// r: (i, Y - i)
		b[i][i] = (b[i][i] + (c2(X) + c2(Y)) * I) % md;
		b[i][i] = (b[i][i] + (X - i) * i * I) % md;
		if (i < mx) b[i][i + 1] = (b[i][i + 1] + (X - i) * (Y - i) * I) % md;
		if (0 < i) b[i][i - 1] = (b[i][i - 1] + i * i * I) % md;
		b[i][i] = (b[i][i] + i * (Y - i) * I) % md;
	}
	while (k) {
		if (k & 1) ans = ans * b;
		b = b * b, k /= 2;
	}
	cout << ans[0][0] << '\n';
}