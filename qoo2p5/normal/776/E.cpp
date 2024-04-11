#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = 1e-8;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) x.size()

const int N = 1000;
const int K = 1000;
ll f[N][K];
ll n, k;

ll calcf(ll x, ll tt = -1) {
	if (tt != -1) {
		return x - x / tt;
	}
	
	ll res = 1;
	
	for (ll d = 2; d * d <= x; d++) {
		int p = 0;
		ll q = 1;
		while (x % d == 0) {
			p++;
			x /= d;
			q *= d;
		}
		if (p) {
			res = res * calcf(q, d);
		}
	}
	
	if (x != 1) {
		res = res * calcf(x, x);
	}
	
	return res;
}

ll solve(ll x, ll y) {
	if (y == 1) {
		return calcf(x);
	}
	
	if (x < N && y < K) {
		return f[x][y];
	}
	
	if (x <= 2) {
		return 1;
	}
	
	return solve(calcf(x), y - 1);
}

void run() {
	f[1][1] = 1;
	for (int i = 2; i < N; i++) {
		f[i][1] = calcf(i);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < K; j++) {
			f[i][j] = f[f[i][j - 1]][1];
		}
	}
	
	ll n, k;
	cin >> n >> k;
	if (k % 2 == 0) {
		k--;
	}
	
	cout << solve(n, k / 2 + 1) % MOD << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}