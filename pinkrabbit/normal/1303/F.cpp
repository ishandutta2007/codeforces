#include <cstdio>
#include <algorithm>
#include <vector>

#define fi first
#define se second
typedef std::pair<int, int> pii;
const int MN = 305, MC = 2000005;

int N, M, Q, C;
inline int Id(int x, int y) { return (x - 1) * M + y; }
int pa[MN * MN]; int fp(int x) { return pa[x] ? pa[x] = fp(pa[x]) : x ; }
inline int Merge(int x, int y) { return (x = fp(x)) == (y = fp(y)) ? 0 : (pa[y] = x, 1); }
int A[MN][MN];
std::vector<pii> V[MC];
int stk[MC];
int Ans[MC];

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= Q; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		V[C = c].push_back({x, y});
	}
	int Pre = 1;
	for (int c = 1; c <= C; ++c) {
		for (int i = 1; i <= N * M; ++i) pa[i] = 0;
		int sz = V[c].size(), Num = 0;
		for (int i = 0; i < sz; ++i) {
			int x = V[c][i].fi, y = V[c][i].se;
			stk[i] = A[x][y];
			A[x][y] = c;
			if (stk[i] == c) { Ans[Pre + i] = Num; continue; }
			++Num;
			if (x > 1 && A[x - 1][y] == c) Num -= Merge(Id(x - 1, y), Id(x, y));
			if (x < N && A[x + 1][y] == c) Num -= Merge(Id(x + 1, y), Id(x, y));
			if (y > 1 && A[x][y - 1] == c) Num -= Merge(Id(x, y - 1), Id(x, y));
			if (y < M && A[x][y + 1] == c) Num -= Merge(Id(x, y + 1), Id(x, y));
			Ans[Pre + i] = Num;
		}
		Num = 0;
		for (int x = 1; x <= N; ++x)
			for (int y = 1; y <= M; ++y) {
				if (A[x][y] == c) continue;
				++Num;
				if (x < N && A[x + 1][y] == A[x][y]) Num -= Merge(Id(x + 1, y), Id(x, y));
				if (y < M && A[x][y + 1] == A[x][y]) Num -= Merge(Id(x, y + 1), Id(x, y));
			}
		for (int i = sz - 1; i >= 0; --i) {
			int x = V[c][i].fi, y = V[c][i].se;
			Ans[Pre + i] += Num;
			if (stk[i] == c) continue;
			++Num;
			A[x][y] = stk[i];
			pa[Id(x, y)] = 0;
			if (x > 1 && A[x - 1][y] == A[x][y]) Num -= Merge(Id(x - 1, y), Id(x, y));
			if (x < N && A[x + 1][y] == A[x][y]) Num -= Merge(Id(x + 1, y), Id(x, y));
			if (y > 1 && A[x][y - 1] == A[x][y]) Num -= Merge(Id(x, y - 1), Id(x, y));
			if (y < M && A[x][y + 1] == A[x][y]) Num -= Merge(Id(x, y + 1), Id(x, y));
		}
		for (int i = 0; i < sz; ++i) {
			int x = V[c][i].fi, y = V[c][i].se;
			A[x][y] = c;
		}
		Pre += sz;
	}
	for (int i = 1; i <= Q; ++i) printf("%d\n", Ans[i]);
	return 0;
}