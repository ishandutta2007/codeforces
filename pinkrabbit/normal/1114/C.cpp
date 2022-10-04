#include <cstdio>
#include <algorithm>
// lg
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL N, b;
LL p[25]; int e[25], cnt;
LL Ans = INF;

int main() {
	scanf("%lld%lld", &N, &b);
	for (LL i = 2; i * i <= b; ++i) if (b % i == 0) {
		p[++cnt] = i, e[cnt] = 0;
		while (b % i == 0) b /= i, ++e[cnt];
	} if (b > 1) p[++cnt] = b, e[cnt] = 1;
	for (int i = 1; i <= cnt; ++i) {
		LL num = 0, m = N;
		while (m) num += m / p[i], m /= p[i];
		Ans = std::min(Ans, num / e[i]);
	}
	printf("%lld\n", Ans);
	return 0;
}