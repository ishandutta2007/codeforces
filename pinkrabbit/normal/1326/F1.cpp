#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define pcnt(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
typedef long long LL;
const int MN = 18;

int N, Adj[MN][MN];
std::vector<int> G[1 << MN];
LL f[1 << MN][MN], g[MN + 1][1 << MN];

void Mul(LL *A, LL *B, LL *C) {
	for (int S = 0; S < 1 << N; ++S) C[S] = A[S] * B[S];
}
void FWT(LL *A, int L, void (*T)(LL &x, LL &y)) {
	for (int i = 1; i < L; i <<= 1)
		for (int S = 0; S < L; ++S) if (S & i)
			T(A[S ^ i], A[S]);
}

int Cnt;
std::vector<int> V;
std::map<std::vector<int>, LL> Z;
LL T[MN + 1][1 << MN];
void DFS(int sum, int mx) {
	++Cnt;
	if (sum == 0) {
		LL Sum = 0;
		for (int S = 0; S < 1 << N; ++S)
			Sum += parity(S) ^ (N & 1) ? -T[0][S] : T[0][S];
		Z[V] = Sum;
		return ;
	}
	for (int i = mx; i <= sum - i; ++i)
		Mul(T[sum], g[i], T[sum - i]), V.push_back(i), DFS(sum - i, i), V.pop_back();
	Mul(T[sum], g[sum], T[0]), V.push_back(sum), DFS(0, sum), V.pop_back();
}

LL Ans[1 << (MN - 1)];
inline LL Calc(int S) {
	std::vector<int> U;
	int j = -1;
	for (int i = 0; i < N; ++i)
		if (~S >> i & 1) U.push_back(i - j), j = i;
	std::sort(U.begin(), U.end());
	return Z[U];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &Adj[i][j]);
	for (int S = 1; S < 1 << N; ++S)
		for (int i = 0; i < N; ++i)
			if (S >> i & 1) G[S].push_back(i);
	for (int i = 0; i < N; ++i) f[1 << i][i] = 1;
	for (int S = 3; S < 1 << N; ++S) if (pcnt(S) >= 2)
		for (int i : G[S]) for (int j : G[S ^ 1 << i])
			if (Adj[i][j]) f[S][i] += f[S ^ 1 << i][j];
	for (int S = 1; S < 1 << N; ++S)
		for (int i : G[S]) g[pcnt(S)][S] += f[S][i];
	for (int i = 1; i <= N; ++i) FWT(g[i], 1 << N, [](LL &x, LL &y) { y += x; });
	for (int S = 0; S < 1 << N; ++S) T[N][S] = 1;
	DFS(N, 1);
	for (int S = 0; S < 1 << (N - 1); ++S) Ans[S] = Calc(S);
	FWT(Ans, 1 << (N - 1), [](LL &x, LL &y) { x -= y; });
	for (int S = 0; S < 1 << (N - 1); ++S) printf("%lld ", Ans[S]);
	return 0;
}