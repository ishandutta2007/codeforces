#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main() {
	long long n, m, k, on;
	cin >> n >> m >> k;
	on = n;
	long long d;
	d = gcd(n, k); n /= d; k /= d;
	d = gcd(m, k); m /= d; k /= d;
	if(k != 2) {
		k *= 2;
		if(n == on) m *= 2;
		else n *= 2;
	}
	if(k != 2) puts("NO");
	else {
		puts("YES");
		printf("0 0\n0 %"LLFORMAT"d\n%"LLFORMAT"d 0\n", m, n);
	}
	return 0;
}