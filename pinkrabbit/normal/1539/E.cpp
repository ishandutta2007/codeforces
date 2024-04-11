#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, M;
int k[MN], al[MN], bl[MN], ar[MN], br[MN];
int lb[MN][2], rb[MN][2];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d%d%d%d", &k[i], &al[i], &bl[i], &ar[i], &br[i]);
	lb[N + 1][0] = 0, rb[N + 1][0] = M;
	lb[N + 1][1] = 0, rb[N + 1][1] = M;
	for (int i = N; i >= 1; --i) {
		if (al[i] <= k[i] && k[i] <= bl[i]) {
			lb[i][0] = ar[i], rb[i][0] = br[i];
			if (k[i] < lb[i + 1][1] || rb[i + 1][1] < k[i])
				lb[i][0] = std::max(lb[i][0], lb[i + 1][0]),
				rb[i][0] = std::min(rb[i][0], rb[i + 1][0]);
		} else
			lb[i][0] = M, rb[i][0] = 0;
		if (ar[i] <= k[i] && k[i] <= br[i]) {
			lb[i][1] = al[i], rb[i][1] = bl[i];
			if (k[i] < lb[i + 1][0] || rb[i + 1][0] < k[i])
				lb[i][1] = std::max(lb[i][1], lb[i + 1][1]),
				rb[i][1] = std::min(rb[i][1], rb[i + 1][1]);
		} else
			lb[i][1] = M, rb[i][1] = 0;
//		printf("[%d - %d] [%d - %d]\n", lb[i][0], rb[i][0], lb[i][1], rb[i][1]);
	}
	if (lb[1][0] > 0 && lb[1][1] > 0)
		return puts("No"), 0;
	puts("Yes");
	int lh = 0, rh = 0;
	for (int i = 1; i <= N; ++i) {
		if (lb[i][0] <= rh && rh <= rb[i][0])
			lh = k[i], printf("0%c", " \n"[i == N]);
		else if (lb[i][1] <= lh && lh <= rb[i][1])
			rh = k[i], printf("1%c", " \n"[i == N]);
	}
	return 0;
}