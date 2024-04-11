#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<int> fac(n+1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = i * 1LL * fac[i-1] % MOD;

	vector<int> pf(n+1);
	iota(begin(pf), end(pf), 0);
	for (int i = 2; i <= n; i++) if (pf[i] == i) {
		for (int j = 2*i; j <= n; j += i) pf[j] = min(pf[j], i);
	}

	vector<int> rad(n+1), rad_count(n+1);
	for (int i = 1; i <= n; i++) {
		rad[i] = 1;
		for (int j = i; j > 1; j /= pf[j]) {
			if (pf[j] != pf[j/pf[j]]) rad[i] *= pf[j];
		}
		rad_count[rad[i]]++;
	}

	vector<int> recip(n+1), recip_count(n+1);
	recip[1] = recip_count[1] = 1;
	for (int i = 2; i <= n; i++) if (pf[i] == i) {
		recip[i] = n/i;
		recip_count[n/i]++;
	}

	vector<int> b(n+1), c(n+1);
	for (int i = 1; i <= n; i++) if (a[i] > 0) {
		int x = rad[i], y = rad[a[i]];
		rad_count[x]--;
		do {
			int p = pf[x], q = pf[y];
			if (recip[p] != recip[q]) return 0;
			if (b[p] != 0 && b[p] != q) return 0;
			if (c[q] != 0 && c[q] != p) return 0;
			if (b[p] == 0) recip_count[recip[p]]--;
			b[p] = q, c[q] = p;
			x /= p, y /= q;
		} while (x > 1 || y > 1);
	}

	int res = 1;
	for (int x: rad_count) res = res * 1LL * fac[x] % MOD;
	for (int x: recip_count) res = res * 1LL * fac[x] % MOD;
	return res;
}

int main() {
	cout << solve() << '\n';
}