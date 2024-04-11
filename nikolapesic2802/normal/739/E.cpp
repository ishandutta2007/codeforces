#include"bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

int n, a, b;
long double penp, penu;
long double p[100001];
long double u[100001];
long double up[100001];

long double dp[100001];
int cp[100001], cu[100001];

long double rec (signed i) {
	if (i == n) return 0;
	if (dp[i] != -1) return dp[i];
	long double R = rec(i + 1);
	long double A = R + p[i] - penp;
	long double B = R + u[i] - penu;
	long double C = R + up[i] - penp - penu;
	long double D = R;
	long double Z = max({A, B, C, D});
	dp[i] = Z;

	if (C == Z) {
		cp[i] = cp[i + 1] + 1;
		cu[i] = cu[i + 1] + 1;
	} else if (B == Z) {
		cp[i] = cp[i + 1];
		cu[i] = cu[i + 1] + 1;
	} else if (A == Z) {
		cp[i] = cp[i + 1] + 1;
		cu[i] = cu[i + 1];
	} else {
		cp[i] = cp[i + 1];
		cu[i] = cu[i + 1];
	}
	return dp[i];
}

signed main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;
	for (signed i = 0 ; i < n ; i++) cin >> p[i];
	for (signed i = 0 ; i < n ; i++) cin >> u[i];
	for (signed i = 0 ; i < n ; i++) {
		long double x = 1 - p[i];
		long double y = 1 - u[i];
		long double z = x * y;
		up[i] = 1 - z;
	}

	long double l1 = -1, r1 = 1;
	int it = 25;

	while (it--) {
		long double m1 = (r1 + l1) / 2;

		penp = m1;

		long double l2 = -1, r2 = 1;
		int it2 = 25;
		while (it2--) {
			long double m2 = (r2 + l2) / 2;

			penu = m2;
			for (auto& i : dp) i = -1;

			rec(0);

			if (cu[0] > b) l2 = m2;
			else r2 = m2;
		}
		penu = r2;
		for (auto& i : dp) i = -1;
		rec(0);

		if (cp[0] > a) l1 = m1;
		else r1 = m1;
	}
	penp = r1;
	long double l2 = -1, r2 = 1;
	int it2 = 25;
	while (it2--) {
		long double m2 = (r2 + l2) / 2;
		penu = m2;
		for (auto& i : dp) i = -1;
		rec(0);
		if (cu[0] > b) l2 = m2;
		else r2 = m2;
	}

	penu = r2;
	for (auto& i : dp) i = -1;

	rec(0);

	// cout << penp << " " << penu << endl;

	long double ans = (long double)(dp[0] + (long double)(penp * (long double)a + penu * (long double)b));

	cout << setprecision(7) << fixed << (ans) << endl;

}