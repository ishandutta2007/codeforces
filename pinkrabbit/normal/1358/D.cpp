#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005;

int N;
LL x, a[MN * 2], s[MN * 2], s2[MN * 2], ans;

int main() {
	scanf("%d%lld", &N, &x);
	for (int i = 1; i <= N; ++i) scanf("%lld", &a[i]), a[N + i] = a[i];
	for (int i = 1; i <= 2 * N; ++i)
		s[i] = s[i - 1] + a[i],
		s2[i] = s2[i - 1] + a[i] * (a[i] + 1) / 2;
	int j = 0;
	for (int i = 1; i <= 2 * N; ++i) {
		while (s[i] - s[j] > x) ++j;
		if (i > N) {
			LL val = s2[i] - s2[j];
			LL left = x - (s[i] - s[j]);
			val += (a[j] - left + 1 + a[j]) * left / 2;
			ans = std::max(ans, val);
		}
	}
	printf("%lld\n", ans);
	return 0;
}