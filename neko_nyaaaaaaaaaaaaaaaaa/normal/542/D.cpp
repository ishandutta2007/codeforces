#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 2 == 0 || n % 3 == 0) {
		return n - 2 < 2;
	}
	ull s = __builtin_ctzll(n - 1), d = n >> s; // counts trailing zeros
	for (auto a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ull p = modpow(a, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--) {
			p = modpow(p, 2, n);
		}
		if (p != n - 1 && i != s) {
			return 0;
		}
	}
	return 1;
}

#define int long long

const int MAX = 1000001;

map<int, int> pr;
void init() {
	bitset<MAX> s;
	for (int i = 2; i <= MAX; i++) {
		if (!s[i]) {
			for (int j = i*i; j <= MAX; j += i) {
				s[j] = 1;
			}
			for (int j = i; j <= MAX*MAX; j *= i) {
				pr[j] = i;
			}
		}
	}
}

int primePower(int n) {
	if (n <= 1) {
		return 0;
	} else if (pr.find(n) != pr.end()) {
		return pr[n];
	} else {
		if (isPrime(n)) return n;
		else return 0;
	}
}

__int128 ONE = 1;

signed main() { 
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int a; cin >> a;
	map<int, vector<int>> p;
	for (int i = 1; i*i <= a; i++) {
		if (a % i) continue;

		int d = i; int pw = primePower(d-1);
		if (pw) {
			p[pw].push_back(d);
		}

		d = a/i; pw = primePower(d-1);
		if (d != i && pw) {
			p[pw].push_back(d);
		}
	}

	map<int, int> dp;
	dp[1] = 1; // dp only contain divisors of a

	for (auto [pr, pw]: p) {
		map<int, int> nxt;
		for (int i: pw) {
			for (auto [v, val]: dp) {
				if (a % (ONE*i*v) == 0) {
					nxt[i*v] += val;
				}
			}
		}
		for (auto [v, val]: nxt) {
			dp[v] += val;
		}
	}

	cout << dp[a] << '\n';

	return 0;
}