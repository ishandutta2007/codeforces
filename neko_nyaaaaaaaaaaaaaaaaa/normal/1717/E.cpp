#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9+7;
const int MAX = 200000;

int phi[MAX + 1];

void init() {
	for (int i = 1; i <= MAX; i++) {
		if (i % 2) phi[i] = i;
		else phi[i] = i/2;
	}
	for (int i = 3; i <= MAX; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= MAX; j += i) {
				phi[j] = phi[j]/i * (i-1);
			}
		}
	}
	phi[1] = 0;
}

int lcm(int a, int b) {
	return (a*b)/__gcd(a, b);
}

void solve(int &ans, int C, int sumAB, int d) {
	int ph = phi[sumAB/d];
	int lc = lcm(C, d);
	ans = (ans + lc*ph) % M;

	//cout << C << ' ' << sumAB << ' ' << d << ' ' << ph << ' ' << lc << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int n; cin >> n;
	int ans = 0;
	for (int C = 1; C < n; C++) {
		int sumAB = n-C;

		// for each divisor of sumAB
		for (int d = 1; d*d <= sumAB; d++) {
			if (sumAB % d == 0) {
				int d1 = d;
				int d2 = sumAB/d;

				solve(ans, C, sumAB, d1);
				if (d2 == n) continue;
				if (d1 == d2) continue;
				solve(ans, C, sumAB, d2);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}