#include <bits/stdc++.h>
using namespace std;

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		n = (n*n) % MOD; k >>= 1;
	}
	return ans;
}

const int MAX = 2000001;
const long long M = 998244353;

long long ft[MAX];
long long ftinv[MAX];
long long expected = 1;

void init(int n, int m) {
	ft[0] = 1;
	for (int i = 1; i < MAX; i++) {
		ft[i] = (ft[i-1]*i) % M;
	}
	ftinv[MAX - 1] = modpow(ft[MAX - 1], M-2, M);

	for (int i = MAX - 2; i >= 0; i--) {
		ftinv[i] = (ftinv[i+1]*(i+1)) % M;
	}

	long long prob = 1;
	for (int i = n; i ; i--) {
		long long pr = 1LL*i*modpow(i+m, M-2, M) % M; // i/(i+m)
		prob = (prob * pr) % M;
		expected = (expected + prob) % M;
	}
}

long long nCk(int n, int k) {
	if (k == 0 || k == n) return 1;
	if (k < 0 || k > n) return 0;
	return ft[n] * (ftinv[k] * ftinv[n-k] % M) % M; 
}

long long calc(int n, int m, int k) {
	// n cards, m jokers, k good cards
	// good cards: doesn't do anything
	// probability that joker gets hit before bad cards
	// m/(cnt+m)
	return 1LL*m*modpow(m+k, M-2, M) % M;
}

long long solve(int n, int m, int k) {
	// number of choices pick a subset of k cards
	long long p1 = nCk(n, k);

	// expected size of subset
	long long ex = expected;

	// probability that a bad subset is picked
	long long b = calc(n, m, k);

	// probability that a good subset is picked = 1 - bad
	long long p = (1 + M - b) % M;

	// return p1 * ex * (expected number of iterations before good)
	// expected number of iterations before good
	// (1 + b + b^2 + b^3 + ...)
	// = 1/(1 - b)

	long long exp_turns = modpow((1 + M - b), M-2, M) % M;

	//cout << n << ' ' << m << ' ' << k << '\n';
	//cout << p1 << ' ' << ex << ' ' << p << ' ' << b << ' ' << exp_turns << '\n';

	long long ret = p1;
	ret = (ret * ex) % M;
	ret = (ret * exp_turns) % M;

	return ret;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	init(n, m);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long tmp = solve(n, m, i);
		if (i % 2) ans += tmp;
		else ans -= tmp;

		ans %= M;
	}
	if (ans < 0) ans += M;
	cout << ans << '\n';

	return 0;
}