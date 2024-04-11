#include <cstdio>
#include <algorithm>

const int MN = 300005;

int N, M, A[MN * 2], vis[MN];
int lstpos[MN];
int Ans[MN];

int b[MN * 2];
inline void Add(int i, int x) { for (; i <= N + M; i += i & -i) b[i] += x; }
inline int Qur(int i) { int a = 0; for (; i; i -= i & -i) a += b[i]; return a; }

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) A[i] = N - i + 1;
	for (int i = 1; i <= M; ++i) scanf("%d", &A[N + i]), vis[A[N + i]] = 1;
//	for (int i = 1; i <= N + M; ++i) printf("%d, ", A[i]); puts("");
	for (int i = 1; i <= N + M; ++i) {
		if (!lstpos[A[i]]) Add(i, 1);
		else {
			Ans[A[i]] = std::max(Ans[A[i]], Qur(i - 1) - Qur(lstpos[A[i]]) + 1);
			Add(lstpos[A[i]], -1);
			Add(i, 1);
		}
		lstpos[A[i]] = i;
	}
	for (int i = 1; i <= N; ++i) Ans[i] = std::max(Ans[i], Qur(N + M) - Qur(lstpos[i]) + 1);
	for (int i = 1; i <= N; ++i) printf("%d %d\n", vis[i] ? 1 : i, Ans[i]);
	return 0;
}