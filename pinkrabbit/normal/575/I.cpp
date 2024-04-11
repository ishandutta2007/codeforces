#include <cstdio>

const int MN = 10005, MQ = 100005;

int N, Q;
int op[MQ], dir[MQ], x[MQ], y[MQ], c[MQ], Ans[MQ];

int Nx, Ny, bit[MN][MN], stkx[MQ], stky[MQ], stkz[MQ], tp;
inline void Add(int x, int y, int z) {
	++tp, stkx[tp] = x, stky[tp] = y, stkz[tp] = z;
	for (int i = x; i <= Nx; i += i & -i)
		for (int j = y; j <= Ny; j += j & -j)
			bit[i][j] += z;
}
inline int Qur(int x, int y) {
	int a = 0;
	for (int i = x; i; i -= i & -i)
		for (int j = y; j; j -= j & -j)
			a += bit[i][j];
	return a;
}
inline void clear() {
	while (tp) Add(stkx[tp], stky[tp], -stkz[tp]), tp -= 2;
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= Q; ++i) {
		scanf("%d", &op[i]);
		if (op[i] == 1) scanf("%d%d%d%d", &dir[i], &x[i], &y[i], &c[i]);
		else scanf("%d%d", &x[i], &y[i]);
	}
	Nx = N, Ny = N;
	for (int i = 1; i <= Q; ++i) {
		if (op[i] == 1) {
			if (dir[i] == 1) Add(x[i], y[i], 1);
			if (dir[i] == 2) Add(x[i], y[i] + 1, -1);
			if (dir[i] == 3) Add(x[i] + 1, y[i], -1);
			if (dir[i] == 4) Add(x[i] + 1, y[i] + 1, 1);
		} else Ans[i] += Qur(x[i], y[i]);
	} clear();
	Nx = N + N, Ny = N;
	for (int i = 1; i <= Q; ++i) {
		if (op[i] == 1) {
			if (dir[i] == 1) Add(x[i] + y[i] + c[i] + 1, y[i], -1);
			if (dir[i] == 4) Add(x[i] + y[i] - c[i], y[i] + 1, -1);
		} else Ans[i] += Qur(x[i] + y[i], y[i]);
	} clear();
	Nx = N, Ny = N + N;
	for (int i = 1; i <= Q; ++i) {
		if (op[i] == 1) {
			if (dir[i] == 1) Add(N - x[i] + 2, x[i] + y[i] + c[i] + 1, 1);
			if (dir[i] == 4) Add(N - x[i] + 1, x[i] + y[i] - c[i], 1);
		} else Ans[i] += Qur(N - x[i] + 1, x[i] + y[i]);
	} clear();
	Nx = N + N, Ny = N;
	for (int i = 1; i <= Q; ++i) {
		if (op[i] == 1) {
			if (dir[i] == 2) Add(N + x[i] - y[i] + c[i] + 2, y[i] + 1, 1);
			if (dir[i] == 3) Add(N + x[i] - y[i] - c[i] + 1, y[i], 1);
		} else Ans[i] += Qur(N + x[i] - y[i] + 1, y[i]);
	} clear();
	Nx = N, Ny = N + N;
	for (int i = 1; i <= Q; ++i) {
		if (op[i] == 1) {
			if (dir[i] == 2) Add(x[i], N - x[i] + y[i] - c[i] + 1, 1);
			if (dir[i] == 3) Add(x[i] + 1, N - x[i] + y[i] + c[i] + 2, 1);
		} else Ans[i] += Qur(x[i], N - x[i] + y[i] + 1);
	} clear();
	for (int i = 1; i <= Q; ++i) if (op[i] == 2) printf("%d\n", Ans[i]);
	return 0;
}