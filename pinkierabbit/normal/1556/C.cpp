#include <cstdio>
#include <climits>
#include <algorithm>

typedef long long LL;
const int MN = 1005;

int N, C[MN];
LL Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &C[i]);
	for (int i = 1; i <= N; i += 2) {
		LL min = LLONG_MAX, now = 0;
		for (int j = i + 1; j <= N; j += 2) {
			now += C[j - 1];
			min = std::min(min, now);
			now -= C[j];
			if (min >= std::max(now, 0ll)) {
				Ans += min - std::max(now, 0ll) + 1;
				if (j == i + 1) --Ans;
//				printf("[%d - %d] : %lld\n", i, j, min - std::max(now, 0ll) + (j != i + 1));
			}
			min = std::min(min, now);
		}
	}
	printf("%lld\n", Ans);
	return 0;
}