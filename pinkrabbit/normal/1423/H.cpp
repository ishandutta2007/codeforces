#include <cstdio>
#include <vector>
#include <map>

const int MN = 100005, MQ = 500005, MS = 1 << 20 | 7;

int N, Q, K, D;
int op[MQ], qx[MQ], qy[MQ], rb[MQ];

int pa[MN], rk[MN], stk[MN], top;
inline int fp(int x) {
	while (pa[x]) x = pa[x];
	return x;
}
inline void Merge(int x, int y) {
	x = fp(x), y = fp(y);
	if (x == y) return ;
	if (rk[x] < rk[y]) pa[x] = y, rk[y] += rk[x], stk[++top] = x;
	else pa[y] = x, rk[x] += rk[y], stk[++top] = y;
}
inline void Undo() {
	int x = stk[top--];
	rk[pa[x]] -= rk[x], pa[x] = 0;
}
inline void Undok(int cnt) {
	while (top > cnt) Undo();
}

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
std::vector<int> V[MS];
void Insert(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return V[i].push_back(x);
	Insert(ls, a, b, x), Insert(rs, a, b, x);
}
void DFS(int i, int l, int r) {
	int cnt = top;
	for (int x : V[i]) Merge(qx[x], qy[x]);
	if (l == r && op[l] == 2) printf("%d\n", rk[fp(qx[l])]);
	if (l != r) DFS(ls), DFS(rs);
	Undok(cnt);
}

int main() {
	scanf("%d%d%d", &N, &Q, &K), D = 1;
	for (int i = 1; i <= N; ++i) rk[i] = 1;
	for (int i = 1; i <= Q; ++i) {
		scanf("%d", &op[i]);
		if (op[i] == 1) scanf("%d%d", &qx[i], &qy[i]);
		if (op[i] == 2) scanf("%d", &qx[i]);
		if (op[i] == 3) rb[D++] = i - 1;
	}
	rb[D] = Q;
	int d = 1;
	for (int i = 1; i <= Q; ++i) {
		if (op[i] == 1) Insert(1, 1, Q, i, d + K - 1 <= D ? rb[d + K - 1] : Q, i);
		if (op[i] == 3) ++d;
	}
	DFS(1, 1, Q);
	return 0;
}