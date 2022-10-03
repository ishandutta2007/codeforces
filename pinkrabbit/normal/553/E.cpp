#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

typedef double real;
struct cp {
	real x, y;
	cp(real _x = 0, real _y = 0) : x(_x), y(_y) {}
	friend cp operator + (const cp &a, const cp &b) { return cp(a.x + b.x, a.y + b.y); }
	friend cp operator - (const cp &a, const cp &b) { return cp(a.x - b.x, a.y - b.y); }
	friend cp operator * (const cp &a, const cp &b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
};
const real PI = acos(-1);

const int MS = 1 << 16;

int Sz, R[MS];

inline int getB(int N) { int Bt = 0; while (1 << Bt < N) ++Bt; return Bt; }

inline void InitFFT(int N) {
	int Bt = getB(N);
	if (Sz == (1 << Bt)) return ;
	Sz = 1 << Bt;
	for (int i = 1; i < Sz; ++i) R[i] = R[i >> 1] >> 1 | (i & 1) << (Bt - 1);
}

inline void FFT(cp *A, int Ty) {
	for (int i = 0; i < Sz; ++i) if (R[i] < i) std::swap(A[R[i]], A[i]);
	for (int j = 1, j2 = 2; j < Sz; j <<= 1, j2 <<= 1) {
		cp wn(cos(PI / j), Ty * sin(PI / j)), w, X, Y;
		for (int i = 0, k; i < Sz; i += j2) {
			for (k = 0, w = cp(1); k < j; ++k, w = w * wn) {
				X = A[i + k], Y = w * A[i + j + k];
				A[i + k] = X + Y;
				A[i + j + k] = X - Y;
			}
		}
	}
	if (!~Ty) for (int i = 0; i < Sz; ++i) A[i].x /= Sz, A[i].y /= Sz;
}

inline void PolyConv(real *_A, int N, real *_B, int M, real *_C) {
	static cp A[MS], B[MS];
	InitFFT(N + M - 1);
	for (int i = 0; i < N; ++i) A[i] = cp(_A[i], 0);
	for (int i = N; i < Sz; ++i) A[i] = cp(0, 0);
	for (int i = 0; i < M; ++i) B[i] = cp(_B[i], 0);
	for (int i = M; i < Sz; ++i) B[i] = cp(0, 0);
	FFT(A, 1), FFT(B, 1);
	for (int i = 0; i < Sz; ++i) A[i] = A[i] * B[i];
	FFT(A, -1);
	for (int i = 0; i < N + M - 1; ++i) _C[i] = A[i].x;
}

const int MT = 40005, MN = 55, MM = 105;

int N, M, T, X;
std::vector<int> G[MN];
int to[MM], cost[MM]; real p[MM][MT];
int dist[MN];
real f[MN][MT], g[MM][MT];

void Floyd() {
	static int A[MN][MN];
	for (int u = 1; u <= N; ++u)
		for (int v = 1; v <= N; ++v)
			A[u][v] = 0x3f3f3f3f;
	for (int u = 1; u <= N; ++u) {
		A[u][u] = 0;
		for (auto e : G[u])
			A[u][to[e]] = cost[e];
	}
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (A[i][j] > A[i][k] + A[k][j])
					A[i][j] = A[i][k] + A[k][j];
	for (int u = 1; u <= N; ++u)
		dist[u] = A[u][N];
}

inline void Trans(int lb, int mid, int rb) {
	for (int u = 1; u < N; ++u) {
		for (auto e : G[u]) {
			int v = to[e];
			int n1 = std::min(rb - lb - 1, T), n2 = rb - mid;
			static real a1[MT], a2[MT];
			for (int i = 0; i < n1; ++i) a1[i] = p[e][n1 - i];
			for (int i = 0; i < n2; ++i) a2[i] = f[v][mid + i];
			PolyConv(a1, n1, a2, n2, a1);
			for (int i = lb; i < mid; ++i) g[e][i] += a1[i + n1 - mid];
		}
	}
}

inline void Solve(int lb, int rb) {
	if (rb - lb == 1) {
		for (int u = 1; u < N; ++u) {
			real now = 1e99;
			for (auto e : G[u]) now = std::min(now, cost[e] + g[e][lb]);
			f[u][lb] = now;
		}
		return ;
	}
	int mid = (lb + rb) / 2;
	Solve(mid, rb);
	Trans(lb, mid, rb);
	Solve(lb, mid);
}

int main() {
	scanf("%d%d%d%d", &N, &M, &T, &X);
	for (int i = 1; i <= M; ++i) {
		int x;
		scanf("%d%d%d", &x, &to[i], &cost[i]);
		G[x].push_back(i);
		for (int j = 1; j <= T; ++j)
			scanf("%lf", &p[i][j]), p[i][j] /= 100000;
	}
	Floyd();
	for (int i = T; i < T + T; ++i)
		for (int u = 1; u <= N; ++u)
			f[u][i] = dist[u] + X;
	for (int i = 0; i <= T; ++i) f[N][i] = 0;
	Trans(0, T, T + T);
	Solve(0, T);
	printf("%.10f\n", f[1][0]);
	return 0;
}