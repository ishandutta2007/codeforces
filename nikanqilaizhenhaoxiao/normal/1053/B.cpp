#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 3e5 + 10;

int a[maxn], f[maxn][2], n, b[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		long long x;
		scanf("%"LLFORMAT"d", &x);
		a[i] = __builtin_popcountll(x);
		b[i] = b[i - 1] ^ (a[i] & 1);
		f[i][b[i]] = f[i - 1][b[i]] + 1;
		f[i][b[i] ^ 1] = f[i - 1][b[i] ^ 1];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i, sum = a[i], mx = a[i];
		while(j <= i + 200 && j <= n) {
			if(sum - mx >= mx && b[j] == b[i - 1]) ++ans;
			++j; sum += a[j]; mx = max(mx, a[j]);
		}
		if(j <= n) {
			int x = b[i - 1];
			ans += f[n][x] - f[j - 1][x];
		}
	}
	printf("%"LLFORMAT"d\n", ans);
	return 0;
}