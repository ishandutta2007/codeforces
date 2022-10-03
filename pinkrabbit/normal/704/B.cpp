#include <cstdio>
#include <algorithm>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 5005;

int N, S, E;
LL x[MN], a[MN], b[MN], c[MN], d[MN];
LL f[MN], g[MN];

void chkmn(LL &x, const LL &y) { x = std::min(x, y); }

int main() {
	scanf("%d%d%d", &N, &S, &E);
	for (int i = 1; i <= N; ++i) scanf("%lld", &x[i]);
	for (int i = 1; i <= N; ++i) scanf("%lld", &a[i]), a[i] += x[i];
	for (int i = 1; i <= N; ++i) scanf("%lld", &b[i]), b[i] -= x[i];
	for (int i = 1; i <= N; ++i) scanf("%lld", &c[i]), c[i] += x[i];
	for (int i = 1; i <= N; ++i) scanf("%lld", &d[i]), d[i] -= x[i];
	for (int i = 0; i <= N; ++i) f[i] = Infll;
	f[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) g[j] = Infll;
		if (i == N) {
			if (i == S) g[0] = f[0] + c[i];
			else if (i == E) g[0] = f[0] + a[i];
			else g[0] = f[0] + a[i] + c[i];
		} else {
			if (i == S) {
				for (int j = 0; j <= N; ++j) chkmn(g[j], f[j] + d[i]);
				for (int j = 1; j <= N; ++j) chkmn(g[j - 1], f[j] + c[i]);
			} else if (i == E) {
				for (int j = 0; j <= N; ++j) chkmn(g[j], f[j] + b[i]);
				for (int j = 1; j <= N; ++j) chkmn(g[j - 1], f[j] + a[i]);
			} else {
				for (int j = 0; j < N; ++j) chkmn(g[j + 1], f[j] + b[i] + d[i]);
				for (int j = 1 - (S < i); j <= N; ++j) chkmn(g[j], f[j] + a[i] + d[i]);
				for (int j = 1 - (E < i); j <= N; ++j) chkmn(g[j], f[j] + b[i] + c[i]);
				for (int j = 2 - (S < i || E < i); j <= N; ++j) chkmn(g[j - 1], f[j] + a[i] + c[i]);
			}
		}
		std::swap(f, g);
	}
	printf("%lld\n", f[0]);
	return 0;
}