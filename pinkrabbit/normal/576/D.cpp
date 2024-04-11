#include <cstdio>
#include <bitset>
#include <algorithm>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;

typedef std::bitset<150> bt; int BN;
struct Mat {
	bt A[150];
	inline bt & operator [] (const int &i) { return A[i]; }
	inline const bt & operator [] (const int &i) const { return A[i]; }
} A;
inline bt operator * (const Mat &B, const bt &A) {
	static bt C;
	for (int i = 0; i < BN; ++i) C[i] = (A & B[i]).any();
	return C;
}
inline Mat operator * (const Mat &A, const Mat &B) {
	static Mat C;
	for (int i = 0; i < BN; ++i) C[i].reset();
	for (int i = 0; i < BN; ++i)
		for (int j = 0; j < BN; ++j)
			if (A[i][j]) C[i] |= B[j];
	return C;
}
inline void Muls(bt &A, Mat B, int e) {
	for (; e; e >>= 1, (e ? B = B * B, 0 : 0)) if (e & 1) A = B * A;
}

const int MN = 155, MM = 155;

int N, M; LL Ans;
int u[MM], v[MM], w[MM], p[MM];
int que[MN], l, r; LL dis[MN];
bt V;

int main() {
	scanf("%d%d", &N, &M), BN = N, Ans = Infll;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		--u[i], --v[i], p[i] = i;
	}
	std::sort(p + 1, p + M + 1, [](int i, int j) { return w[i] < w[j]; });
	V[0] = 1;
	int tim = 0;
	for (int id = 1; id <= M; ++id) {
		int i = p[id], dt = w[i] - tim;
		if (w[i] >= Ans) break;
		if (dt) Muls(V, A, dt);
		A[v[i]][u[i]] = 1;
		tim = w[i];
		l = 1, r = 0;
		for (int j = 0; j < N; ++j)
			if (V[j]) que[++r] = j, dis[j] = 0;
			else dis[j] = Infll;
		while (l <= r) {
			int u = que[l++];
			for (int j = 0; j < N; ++j)
				if (A[j][u] && dis[j] == Infll)
					dis[j] = dis[u] + 1,
					que[++r] = j;
		}
		Ans = std::min(Ans, tim + dis[N - 1]);
	}
	if (Ans == Infll) puts("Impossible");
	else printf("%lld\n", Ans);
	return 0;
}