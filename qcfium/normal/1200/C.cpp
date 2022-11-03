#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

int64_t gcd(int64_t a, int64_t b) {
	while (a && b) {
		if (a >= b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main() {
	int64_t n = rll(), m = rll();
	int q = ri();
	int64_t gc = gcd(n, m);
	int64_t n_one = n / gc;
	int64_t m_one = m / gc;
	for (int i = 0; i < q; i++) {
		int64_t s1 = rll() - 1, s2 = rll() - 1;
		int64_t g1 = rll() - 1, g2 = rll() - 1;
		int64_t s = s2 / (s1 ? m_one : n_one);
		int64_t g = g2 / (g1 ? m_one : n_one);
		std::cout << (s == g ? "YES" : "NO") << std::endl;
	}
	
	return 0;
}