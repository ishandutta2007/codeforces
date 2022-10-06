#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 300005;

int N, A[MN];
LL S[MN];

void Solve() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]),
		S[i] = A[i] - S[i - 1];
//	for (int i = 1; i <= N; ++i)
//		printf("%lld, ", S[i]);
//	puts("");
	LL ans = 0;
	static int stk1[MN], stk2[MN];
	int tp1 = 0, tp2 = 0;
	for (int i = N; i >= 1; --i) {
		{
			int *stk = i & 1 ? stk1 : stk2;
			int &tp = i & 1 ? tp1 : tp2;
			while (tp && S[stk[tp]] > S[i]) --tp;
			stk[++tp] = i;
		}
		int pos1 = N + 1, pos2 = N + 1;
		// S[p] < ((p - i + 1) & 1 ? -S[i - 1] : S[i - 1])
		{
			LL val = i & 1 ? -S[i - 1] : S[i - 1];
			int lb = 1, rb = tp1;
			while (lb <= rb) {
				int mid = (lb + rb) / 2;
				if (S[stk1[mid]] < val) pos1 = stk1[mid], lb = mid + 1;
				else rb = mid - 1;
			}
		}
		{
			LL val = i & 1 ? S[i - 1] : -S[i - 1];
			int lb = 1, rb = tp2;
			while (lb <= rb) {
				int mid = (lb + rb) / 2;
				if (S[stk2[mid]] < val) pos2 = stk2[mid], lb = mid + 1;
				else rb = mid - 1;
			}
		}
		int p = std::min(pos1, pos2) - 1;
//		printf("[%d : %d]\n", i, p);
		{
			LL val = i & 1 ? -S[i - 1] : S[i - 1];
			int pp1 = tp1 + 1, pp2 = 0;
			int lb = 1, rb = tp1;
			while (lb <= rb) {
				int mid = (lb + rb) / 2;
				if (S[stk1[mid]] >= val && stk1[mid] <= p) pp1 = mid, rb = mid - 1;
				else lb = mid + 1;
			}
			lb = 1, rb = tp1;
			while (lb <= rb) {
				int mid = (lb + rb) / 2;
				if (S[stk1[mid]] <= val) pp2 = mid, lb = mid + 1;
				else rb = mid - 1;
			}
			ans += std::max(pp2 - pp1 + 1, 0);
		}
		{
			LL val = i & 1 ? S[i - 1] : -S[i - 1];
			int pp1 = tp2 + 1, pp2 = 0;
			int lb = 1, rb = tp2;
			while (lb <= rb) {
				int mid = (lb + rb) / 2;
				if (S[stk2[mid]] >= val && stk2[mid] <= p) pp1 = mid, rb = mid - 1;
				else lb = mid + 1;
			}
			lb = 1, rb = tp2;
			while (lb <= rb) {
				int mid = (lb + rb) / 2;
				if (S[stk2[mid]] <= val) pp2 = mid, lb = mid + 1;
				else rb = mid - 1;
			}
			ans += std::max(pp2 - pp1 + 1, 0);
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--)
		Solve();
	return 0;
}