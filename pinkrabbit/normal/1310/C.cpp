#include <cstdio>
#include <algorithm>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 1005;

inline void Add(LL &x, LL y) { x = (x += y) >= Infll ? Infll : x; }

LL K;
int N, M, C, lcp[MN][MN];
char str[MN];
struct dat { int s, l; } seq[500505];

LL f[MN], g[MN];
LL Solve(dat now) {
	int st = now.s, len = now.l;
	f[N + 1] = 1;
	for (int i = 1; i <= N; ++i) f[i] = 0;
	for (int t = 1; t <= M; ++t) {
		for (int i = 1; i <= N + 1; ++i) g[i] = 0;
		for (int i = N; i >= 1; --i) Add(f[i], f[i + 1]);
		for (int i = 1; i <= N; ++i) {
			int d = lcp[i][st];
			if (d < len) {
				if (str[i + d] > str[st + d])
					g[i] = f[i + d + 1];
			} else g[i] = f[i + len];
		}
		std::swap(f, g);
	}
	return f[1];
}

int main() {
	scanf("%d%d%lld%s", &N, &M, &K, str + 1);
	for (int i = N; i >= 1; --i)
		for (int j = N; j >= 1; --j)
			lcp[i][j] = str[i] == str[j] ? lcp[i + 1][j + 1] + 1 : 0;
	for (int i = 1; i <= N; ++i)
		for (int j = i; j <= N; ++j)
			seq[++C].s = i, seq[C].l = j - i + 1;
	std::sort(seq + 1, seq + C + 1, [](dat i, dat j) {
		int d = lcp[i.s][j.s];
		if (std::min(i.l, j.l) > d) return str[i.s + d] < str[j.s + d];
		return i.l < j.l;
	});
	C = std::unique(seq + 1, seq + C + 1, [](dat i, dat j) {
		return i.l == j.l && lcp[i.s][j.s] >= i.l;
	}) - seq - 1;
	int l = 1, r = C, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (Solve(seq[mid]) >= K) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	str[seq[ans].s + seq[ans].l] = '\0';
	printf("%s\n", str + seq[ans].s);
	return 0;
}