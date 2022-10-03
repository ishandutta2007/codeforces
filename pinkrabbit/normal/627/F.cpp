#include <cstdio>
#include <vector>

typedef long long LL;
const int MN = 200005;

int N, su, tu, A[MN], B[MN];
std::vector<int> G[MN];

int stk[MN], top;
int faz[MN], dep[MN], sv[MN];
void DFS0(int u, int fz) {
	dep[u] = dep[faz[u] = fz] + 1;
	for (auto v : G[u]) if (v != fz) DFS0(v, u);
}
int DFSD(int u, int fz, int d, int t, int x) {
	if (u != x) stk[++top] = u;
	if (u == t) return d;
	for (auto v : G[u]) if (v != fz) {
		int ret = DFSD(v, u, d + 1, t, x);
		if (ret != -1) return ret;
	}
	if (u != x) --top;
	return -1;
}
int Dist(int u, int v, int x = 0) { return top = 0, DFSD(u, 0, 0, v, x); }
int Calc(int u, int v) { return Dist(su, u) + Dist(v, tu) + 1; }

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);
	for (int i = 1; i <= N; ++i) {
		if (A[i] == 0) su = i;
		if (B[i] == 0) tu = i;
	}
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS0(tu, 0);
	for (int x = su; x != tu; x = faz[x]) A[x] = A[faz[x]];
	A[tu] = 0;
	int cnt = 0, tp = 0, p = 0;
	static int seq[MN];
	for (int i = 1; i <= N; ++i) if (A[i] != B[i]) {
		++cnt, sv[faz[i]] = 1;
		if (!p || dep[i] <= dep[p]) p = faz[i];
	}
	if (!cnt) return printf("0 %d\n", dep[su] - 1), 0;
	for (int i = 1; i <= N; ++i) if (A[i] != B[i] && !sv[i]) seq[++tp] = i;
	if (tp > 2) return puts("-1"), 0;
	if (tp == 1) seq[2] = p;
	if (Dist(seq[1], seq[2], p) != cnt) return puts("-1"), 0;
	static int iB[MN], shift;
	for (int i = 1; i <= top; ++i) iB[B[stk[i]]] = i;
	if (!iB[A[stk[1]]]) return puts("-1"), 0;
	else shift = iB[A[stk[1]]] - 1;
	for (int i = 2; i <= top; ++i)
		if (!iB[A[stk[i]]] || (iB[A[stk[i]]] - i + cnt) % cnt != shift)
			return puts("-1"), 0;
	int len = cnt + 1;
	LL cycuv = Calc(seq[1], seq[2]) + (LL)(shift - 1) * len;
	LL cycvu = Calc(seq[2], seq[1]) + (LL)(cnt - shift - 1) * len;
	if (seq[1] > seq[2]) std::swap(seq[1], seq[2]);
	printf("%d %d %lld\n", seq[1], seq[2], std::min(cycuv, cycvu));
	return 0;
}