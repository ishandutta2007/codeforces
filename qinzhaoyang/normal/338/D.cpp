#include <stdio.h>
#include <bits/stdc++.h>
#define int long long
#define GG puts("NO"),exit(0)

using namespace std;

const int K = 10010;

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

void exgcd(int a, int b, int &x, int &y) {
	if (!b) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= (a / b) * x;
}

int Inv(int a, int b) {
	int x, y; exgcd(a, b, x, y);
	return (x % b + b) % b;
}

void check(int x, int y, int n) {
	int r = 0, flag = 0;
	while (y) {
		if (y & 1) {
			if (flag || r + x > n) GG;
			r += x;
		}
		x <<= 1; if (x > n) flag = 1;
		y >>= 1;
	}
}

int Mul(int x, int y, int p) {
	int r = 0;
	while (y) {
		if (y & 1) r = (r + x) % p;
		x = (x << 1) % p, y >>= 1;
	}
	return r;
}

pair <int,int> excrt(pair <int,int> f1, pair <int,int> f2) {
	int m1 = f1.first, c1 = f1.second,
		m2 = f2.first, c2 = f2.second;
	if (c1 > c2) swap(m1, m2), swap(c1, c2);
	int g = gcd(m1, m2);
	if ((c2 - c1) % g) GG;
	int m = m1 / g * m2;
	int c = Mul(Inv(m1 / g, m2 / g), (c2 - c1) / g, m2 / g) * m1 + c1;
	c = (c % m + m) % m;
	return make_pair(m, c);
}

int n, m, k, a[K], x = 1, y;

signed main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &a[i]);
		int g = gcd(x, a[i]);
		check(x / g, a[i], n);
		x = x / g * a[i];
	}
	pair <int,int> crt = make_pair(a[1], 0);
	for (int i = 2; i <= k; i++) {
		pair <int,int> tmp = make_pair(a[i], ((a[i] - i + 1) % a[i] + a[i]) % a[i]);
		crt = excrt(crt, tmp);
	}
	y = crt.second; if (y == 0) y = x;
	if (!(1 <= x && x <= n && 1 <= y && y + k - 1 <= m)) GG;
	for (int i = 1; i <= k; i++)
		if (gcd(x, y + i - 1) != a[i]) GG;
	puts("YES");
	return 0;
}