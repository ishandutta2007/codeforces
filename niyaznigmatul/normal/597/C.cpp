#include <cstdio>

int const N = 123456;

void add(long long * f, int x, long long y) {
	for (int i = x; i < N; i |= i + 1) f[i] += y;
}

long long get(long long * f, int x) {
	long long ret = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
		ret += f[i];
	}
	return ret;
}

long long f[12][N];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	add(f[0], 0, 1);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = k + 1; j > 0; j--) {
			long long got = get(f[j - 1], x - 1);
			add(f[j], x, got);
		}
	}
	printf("%lld\n", get(f[k + 1], N - 1));
}