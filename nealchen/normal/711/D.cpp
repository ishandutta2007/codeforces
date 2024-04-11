#include <stdio.h>
#define N 200001
#define M 1000000007
long long p2(int x) {
	long long a = 2, s = 1;
	for(; x; a = a * a % M, x >>= 1) if(x & 1) s = s * a % M;
	return s;
}
int n, a[N], ans = 1, f[N], w[N], s[N], mark[N];
int find(int u) {
	if(f[u] == u) return u;
	int v = find(f[u]);
	w[u] += w[f[u]];
	return f[u] = v;
}
int main() {
	int i, x, y;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) f[i] = i, s[i] = 1;
	for(i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		x = find(i);
		y = find(a[i]);
		if(x == y) mark[x] += w[i] + w[a[i]] + 1;
		else f[x] = y, w[x] = 1 + w[a[i]] - w[i], s[y] += s[x], mark[y] += mark[x];
	}
	for(i = 1; i <= n; ++i) if(find(i) == i) {
		if(mark[i]) ans = (ans * p2(s[i] - mark[i]) % M * (p2(mark[i]) - 2) % M) % M;
		else ans = ans * p2(s[i]) % M;
	}
	printf("%d", (ans + M) % M);
	return 0;
}