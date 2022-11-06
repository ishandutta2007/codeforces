#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 20, mod = 1000000007;
int n, a[maxn + 10], p2[maxn + 10];

inline int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
inline int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
inline int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int main() {
	scanf("%d", &n); p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x); ++a[x];
		p2[i] = add(p2[i - 1], p2[i - 1]);
	}
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < maxn; ++j)
			if (j >> i & 1) a[j ^ (1 << i)] = add(a[j ^ (1 << i)], a[j]);
	for (int i = 0; i < maxn; ++i)
		a[i] = p2[a[i]];
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < maxn; ++j)
			if (j >> i & 1) a[j ^ (1 << i)] = dec(a[j ^ (1 << i)], a[j]);
	printf("%d", a[0]);
}