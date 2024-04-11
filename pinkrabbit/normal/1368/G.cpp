#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 200005, MS = 1 << 18 | 7;

LL Ans;
int N, M, pid[MN];
inline int Id(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M) return N * M + 1 + ((x ^ y) & 1);
	return (x - 1) * M + y;
}
std::vector<int> G[MN];

int ldf[MN], rdf[MN], dfc;
void DFS0(int u) {
	ldf[u] = ++dfc;
	for (int v : G[u]) DFS0(v);
	rdf[u] = dfc;
}

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
int mnv[MS], cnt[MS], tag[MS];
inline void P(int i, int x) { mnv[i] += x, tag[i] += x; }
inline void Pushdown(int i) { if (tag[i]) P(li, tag[i]), P(ri, tag[i]), tag[i] = 0; }
void Build(int i, int l, int r) {
	mnv[i] = 0, cnt[i] = r - l + 1;
	if (l == r) return ;
	Build(ls), Build(rs);
}
void Mdf(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	Pushdown(i), Mdf(ls, a, b, x), Mdf(rs, a, b, x);
	mnv[i] = std::min(mnv[li], mnv[ri]), cnt[i] = 0;
	if (mnv[li] == mnv[i]) cnt[i] += cnt[li];
	if (mnv[ri] == mnv[i]) cnt[i] += cnt[ri];
}

void DFS1(int u) {
	if (u != N * M + 2) {
		Mdf(1, 1, dfc, ldf[pid[u]], rdf[pid[u]], 1);
		Ans += cnt[1] - 1;
	}
	for (int v : G[u]) DFS1(v);
	if (u != N * M + 2) Mdf(1, 1, dfc, ldf[pid[u]], rdf[pid[u]], -1);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		static char s[MN];
		scanf("%s", s + 1);
		for (int j = 1; j <= M; ++j) {
			int v = Id(i, j);
			if (s[j] == 'U') G[Id(i + 2, j)].push_back(v), pid[v] = Id(i + 1, j);
			if (s[j] == 'D') G[Id(i - 2, j)].push_back(v), pid[v] = Id(i - 1, j);
			if (s[j] == 'L') G[Id(i, j + 2)].push_back(v), pid[v] = Id(i, j + 1);
			if (s[j] == 'R') G[Id(i, j - 2)].push_back(v), pid[v] = Id(i, j - 1);
		}
	}
	DFS0(N * M + 1);
	Build(1, 1, dfc);
	DFS1(N * M + 2);
	printf("%lld\n", (LL)N * N * M * M / 4 - Ans);
	return 0;
}