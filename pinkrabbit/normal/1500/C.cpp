#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::vector<int> VI;
const int MN = 1505, MM = 1505;

int N, M, A[MN][MM], B[MN][MM];
int C[MM], vis[MM], Ans[MM], tAns;

int lb[MN], rb[MN], Cnt;

int per[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &A[i][j]);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &B[i][j]);
	Cnt = 1, lb[Cnt] = 1, rb[Cnt] = N;
	for (int j = 1; j <= M; ++j)
		for (int i = 2; i <= N; ++i)
			C[j] += B[i - 1][j] > B[i][j];
//	for (int j = 1; j <= M; ++j) printf("%c%d%s", "[ "[j > 1], C[j], j < M ? "," : "]\n");
	while (1) {
		int p = 0;
		for (int j = 1; j <= M; ++j) {
			if (vis[j]) continue;
			if (!C[j]) { p = j; break; }
		}
		if (!p) break;
//		printf("p = %d\n", p);
		Ans[vis[p] = ++tAns] = p;
		int oCnt = Cnt;
		for (int i = 1; i <= oCnt; ++i) {
			int l = lb[i], r = rb[i];
			int id = i;
			for (int k = l + 1; k <= r; ++k) if (B[k - 1][p] < B[k][p]) {
				rb[id] = k - 1;
				for (int j = 1; j <= M; ++j)
					C[j] -= B[k - 1][j] > B[k][j];
				++Cnt, lb[Cnt] = k, rb[Cnt] = r;
				id = Cnt;
			}
		}
//		for (int j = 1; j <= M; ++j) printf("%c%d%s", "[ "[j > 1], C[j], j < M ? "," : "]\n");
	}
	for (int i = 1; i <= N; ++i) per[i] = i;
	std::sort(per + 1, per + N + 1, [](int i, int j) {
		for (int k = 1; k <= tAns; ++k) {
			int p = Ans[k];
			if (A[i][p] != A[j][p])
				return A[i][p] < A[j][p];
		}
		return i < j;
	});
	int ok = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (A[per[i]][j] != B[i][j])
				ok = 0;
	if (!ok) return puts("-1"), 0;
	printf("%d\n", tAns);
	for (int i = tAns; i >= 1; --i) printf("%d%c", Ans[i], " \n"[i == 1]);
	return 0;
}