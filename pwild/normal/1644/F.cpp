#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<int m>
struct mod {
	i64 x;
	mod(i64 x = 0): x((m + x%m) % m) { }
	
	mod operator+(const mod &a) const { return mod(x+a.x); }
	mod operator-(const mod &a) const { return mod(x-a.x); }
	mod operator*(const mod &a) const { return mod(x*a.x); }
	mod operator/(const mod &a) const { return *this * (a^(m-2)); }
	
	bool operator==(const mod &a) const { return x == a.x; }

	mod operator^(i64 n) const {
		i64 res = 1, a = x;
		for (; n; n /= 2) {
			if (n%2) res = res*a % m;
			a = a*a % m;
		}
		return mod(res);
	}
};

using num = mod<998'244'353>;

const int N = 2e5 + 10;
num fac[N], inv_fac[N], der[N];
int is_prime[N], mu[N];

void precalc() {
	fac[0] = inv_fac[0] = 1, der[0] = 1, der[1] = 0;
	for (int n = 1; n < N; n++) {
		fac[n] = num(n) * fac[n-1];
		inv_fac[n] = inv_fac[n-1] / num(n);
		if (n >= 2) der[n] = num(n-1) * (der[n-1] + der[n-2]);
	}

	fill(is_prime, is_prime+N, 1);
	mu[1] = 1;
	for (i64 p = 2; p < N; p++) if (is_prime[p]) {
		for (i64 n = p*p; n < N; n += p) is_prime[n] = 0;
		for (i64 n = p*((N-1)/p); n >= p; n -= p) mu[n] -= mu[n/p];
	}
}

num binom(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] * inv_fac[n-k];
}

// Number of sequences of length n over an alphabet of size k, up to permutation of the alphabet
num burnside(int n, int k) {
	k = min(n,k);
	num sum = 0;
	for (int m = 0; m <= k; m++) {
		sum = sum + binom(k,m) * der[k-m] * (num(m)^n);
	}
	return sum * inv_fac[k];
}

int main() {
	precalc();
/*
	for (int n = 1; n <= 20; n++) {
		for (int k = 1; k <= 20; k++) {
			cout << burnside(n,k).x << " \n"[k==20];
		}
	}
*/

	int n, k;
	cin >> n >> k;

	num res = 0;
	for (int m = 1; m < n; m++) {
		res = res + num(mu[m]) * (burnside((n+m-1)/m, k) - 1);
	}

	if (n == 1 || k == 1) res = 1;
	cout << res.x << '\n';
}