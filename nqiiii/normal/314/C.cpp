#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, maxn = 1000000;
int n, a[maxn + 10], c[maxn + 10];

int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}

void modify(int p, int v) {
	for (; p <= maxn; p += p & -p) c[p] = add(c[p], v);
}
int query(int p) {
	int ans = 0;
	for (; p; p -= p & -p) ans = add(ans, c[p]);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		int v = mul(x, add(query(x), 1));
		modify(x, dec(v, a[x])); a[x] = v;
	}
	printf("%d", query(maxn));
}