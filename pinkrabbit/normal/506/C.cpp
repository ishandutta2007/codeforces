#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;
const int MM = 5005;

int N, M, K;
LL P, h[MN], a[MN], mxv;

inline bool chk(LL x) {
	static int cnt[MM];
	LL tot = 0;
	for (int i = 1; i <= M; ++i) cnt[i] = 0;
	for (int i = 1; i <= N; ++i) {
		if (h[i] <= x) continue;
		LL t = (h[i] - x - 1 + P) / P;
		if ((tot += t) > M * K || a[i] > x) return 0;
		for (int j = t; j >= 1; --j)
			++cnt[std::max(1ll, M - (x + (t - j) * P) / a[i] + 1)];
			// (x + (t - j) * P) / a[i] := minimum number of days that [(a[i]*days)>(x+(t-j)*p)], minus one
			// M - days + 1 := must have (t-j+1) beats after (M-days+1)'th day
	}
	int left = 0;
	for (int i = 1; i <= M; ++i)
		left = std::max(left + cnt[i] - K, 0);
	return left == 0;
}

int main() {
	scanf("%d%d%d%lld", &N, &M, &K, &P);
	for (int i = 1; i <= N; ++i)
		scanf("%lld%lld", &h[i], &a[i]),
		mxv = std::max(mxv, h[i] += M * a[i]);
	LL lb = 0, rb = mxv, mid, ans = -1;
	while (lb <= rb) {
		mid = (lb + rb) >> 1;
		if (chk(mid)) ans = mid, rb = mid - 1;
		else lb = mid + 1;
	} printf("%lld\n", ans);
	return 0;
}