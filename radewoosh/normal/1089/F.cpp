#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )

int n;

int rozloz(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return i;
	}
	return x;
}

int potmod(long long x, int m, int mod) {
	long long res = 1;
	while (m > 0) {
		if (m & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		m /= 2;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	int on = n;
	int p = rozloz(n);
	while (n % p == 0) n /= p;
	if (n == 1) {
		printf("NO\n");
		return 0;
	}
	int q = rozloz(n);
	n = on;
	
	int a = 1ll * (q - 1) * potmod(p, q - 2, q) % q;
	int b = ((n - 1) - a * p) / q;
	
	assert (a > 0 && b > 0);
	
	printf("YES\n2\n");
	printf("%d %d\n", a, n / p);
	printf("%d %d\n", b, n / q);
}