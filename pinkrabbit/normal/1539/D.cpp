#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

struct dat {
	LL a, b;
};

int N;
dat t[MN];
LL sum;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld%lld", &t[i].a, &t[i].b);
		sum += t[i].a;
	}
	std::sort(t + 1, t + N + 1, [](dat p, dat q) {
		return p.b < q.b;
	});
	LL ans = 0, now = 0;
	for (int i = 1; i <= N; ++i) {
		now = std::max(now, t[i].b);
		if (now + t[i].a >= sum) {
			ans += std::max(sum - now, 0ll);
			break;
		}
		ans += t[i].a;
		now += t[i].a;
	}
	printf("%lld\n", sum * 2 - ans);
	return 0;
}