#include <bits/stdc++.h>

long long n, p, k;
long long a[310000];
std::map <long long, long long> map;

long long fix (long long x) { return (x % p + p) % p; }

int main () {
	scanf ("%lld%lld%lld", &n, &p, &k);
	for (int i = 0; i < n; ++i) {
		scanf ("%lld", &a[i]);
		++map[fix (a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p)];
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res += map[fix (a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p)] - 1;
	}
	printf ("%lld\n", res / 2);
}