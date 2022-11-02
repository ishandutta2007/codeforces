#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

const int maxn = 2e5 + 10, fuck[] = {-1000000000, -1000000000, 1000000000, 1000000000};

int n, a[maxn], b[maxn], c[maxn], d[maxn];
int l[maxn][4], r[maxn][4];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
	memcpy(l[0], fuck, sizeof fuck);
	memcpy(r[n + 1], fuck, sizeof fuck);
	for (int i = 1; i <= n; ++i) {
		l[i][0] = max(l[i - 1][0], a[i]);
		l[i][1] = max(l[i - 1][1], b[i]);
		l[i][2] = min(l[i - 1][2], c[i]);
		l[i][3] = min(l[i - 1][3], d[i]);
	}
	for (int i = n; i; --i) {
		r[i][0] = max(r[i + 1][0], a[i]);
		r[i][1] = max(r[i + 1][1], b[i]);
		r[i][2] = min(r[i + 1][2], c[i]);
		r[i][3] = min(r[i + 1][3], d[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int a = max(l[i - 1][0], r[i + 1][0]);
		int b = max(l[i - 1][1], r[i + 1][1]);
		int c = min(l[i - 1][2], r[i + 1][2]);
		int d = min(l[i - 1][3], r[i + 1][3]);
		if(a <= c && b <= d) { printf("%d %d\n", a, b); return 0; }
	}
	return 0;
}