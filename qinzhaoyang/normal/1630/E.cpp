#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, P = 998244353;

inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
inline int mul(int x, int y) {return 1ll * x * y % P;}
inline void inc(int &x, int y) {x = add(x, y);}
inline void upd(int &x, int y) {x = mul(x, y);}
inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
int gcd(int x, int y) {return y == 0 ? x : gcd(y, x % y);}

int T, n, a[N], c[N], fac[N], t1[N], t2[N];
vector <int> v;

int main() {
	fac[0] = 1;
	for (int i = 1; i <= (int)1e6; i++)
		fac[i] = mul(fac[i - 1], i);
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n), v.clear();
		for (int i = 1; i <= n; i++) c[i] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[a[i]]++;
		for (int i = 1; i <= n; i++) if (c[i]) v.push_back(c[i]);
		int g = 0;
		for (int x : v) g = gcd(g, x);
		if (g == n) {printf("%d\n", 1); continue;}
		for (int i = 1; i <= g; i++) if (g % i == 0) {
			int s1 = 1, s2 = 0, s3 = 0;
			for (int x : v) {
				upd(s1, fac[x / i]);
				inc(s3, mul(s2, x / i));
				inc(s2, x / i);
			}
			s1 = Pow(s1, P - 2);
			t2[i] = mul(s1, fac[n / i]);
			t1[i] = mul(n, mul(mul(s1, fac[n / i - 2]), mul(2, s3)));
		}
		int a1 = 0, a2 = 0;
		for (int i = 1; i <= n; i++) {
			int t = n / gcd(n, i);
			if (g % t == 0) {
				inc(a1, t1[t]);
				inc(a2, t2[t]);
			}
		}
		printf("%d\n", mul(a1, Pow(a2, P - 2)));
	}
	return 0;
}