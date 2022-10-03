#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 500005, MQ = 500005;

int N, Q;
LL Ans[MQ];

struct DSU {
	std::vector<int> q1[MN * 2], q2[MN];
	int _ls[MN], _rs[MN], *ls, *rs;
	int fa[MN * 2], siz[MN * 2], cnt;
	int ff(int x) { return fa[x] ? fa[x] = ff(fa[x]) : x; }
	inline void Merge(int x, int y) {
		++cnt, fa[x = ff(x)] = cnt, fa[y = ff(y)] = cnt;
		siz[cnt] = siz[x] + siz[y];
		ls[cnt] = x, rs[cnt] = y;
	}
} f1, f2;

LL b[MQ];
inline void Add(int i, LL x) { for (; i <= Q; i += i & -i) b[i] += x; }
inline LL Qur(int i) { LL a = 0; for (; i; i -= i & -i) a += b[i]; return a; }
inline int BS(LL x) {
	if (x < 0) return -1;
	int i = 0;
	for (int j = 18; j >= 0; --j)
		if ((i | 1 << j) <= Q && b[i | 1 << j] <= x)
			x -= b[i |= 1 << j];
	return i;
}

void DFS2(int u) {
	for (auto x : f2.q1[u]) Add(x, 1);
	if (u > N) DFS2(f2.ls[u]), DFS2(f2.rs[u]);
	else for (auto x : f2.q2[u]) Ans[x] = BS(Qur(x) - 1) + 1;
	for (auto x : f2.q1[u]) Add(x, -1);
}

void DFS1(int u) {
	for (auto x : f1.q1[u]) Add(x, f1.siz[u]);
	if (u > N) DFS1(f1.ls[u]), DFS1(f1.rs[u]);
	else for (auto x : f1.q2[u]) Ans[x] = Qur(x) - Qur(Ans[x]);
	for (auto x : f1.q1[u]) Add(x, -f1.siz[u]);
}

int main() {
	char s[3]; int x, y;
	scanf("%d%d", &N, &Q);
	f1.cnt = N, f1.ls = f1._ls - N, f1.rs = f1._rs - N;
	f2.cnt = N, f2.ls = f2._ls - N, f2.rs = f2._rs - N;
	std::fill(f1.siz + 1, f1.siz + N + 1, 1);
	std::fill(f2.siz + 1, f2.siz + N + 1, 1);
	for (int i = 1; i <= Q; ++i) {
		scanf("%s%d", s, &x);
		if (*s == 'U') scanf("%d", &y), f1.Merge(x, y);
		if (*s == 'M') scanf("%d", &y), f2.Merge(x, y);
		if (*s == 'A') f1.q1[f1.ff(x)].push_back(i);
		if (*s == 'Z') f2.q1[f2.ff(x)].push_back(i);
		if (*s == 'Q') f1.q2[x].push_back(i), f2.q2[x].push_back(i);
		Ans[i] = -1;
	}
	for (int i = 1; i <= f2.cnt; ++i) if (!f2.fa[i]) DFS2(i);
	for (int i = 1; i <= f1.cnt; ++i) if (!f1.fa[i]) DFS1(i);
	for (int i = 1; i <= Q; ++i) if (~Ans[i]) printf("%lld\n", Ans[i]);
	return 0;
}