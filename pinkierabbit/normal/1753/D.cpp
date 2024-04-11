#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <iostream>
#include <queue>
#include <functional>
using std::scanf, std::printf;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

void Solve();
int main() {
	int tests = 1;
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int Mod = 998244353;

const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MN = 300005;

int n, m;
LL p, q;
std::string S[MN];

int Id(int i, int j) {
	if (i < 1 || i > n || j < 1 || j > m)
		return -1;
	return (i - 1) * m + j;
}

bool block[MN];

std::vector<std::pair<int, LL>> G[MN];
void Ins(int u, int v, LL w, bool rv = false) {
	if (u == -1 || v == -1) return ;
	if (rv)
		std::swap(u, v);
	if (!u) u = n * m + 1;
	if (!v) v = n * m + 2;
	if (block[u] || block[v]) return ;
	G[u].push_back({v, w});
}

LL dis[MN];
void Dijkstra() {
	using info = std::pair<LL, int>;
	std::priority_queue<info, std::vector<info>, std::greater<info>> pq;
	static bool vis[MN];
	F(i, 1, n * m + 2)
		dis[i] = InfLL,
		vis[i] = false;
	int s = n * m + 1;
	dis[s] = 0ll;
	pq.push({0ll, s});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
//		printf("(u, d) = (%d, %lld)\n", u, d);
		for (const auto &[v, w] : G[u])
			if (dis[v] > d + w)
				dis[v] = d + w,
				pq.push({dis[v], v});
	}
}

void Solve() {
	scanf("%d%d", &n, &m);
	scanf("%lld%lld", &p, &q);
	F(i, 1, n)
		std::cin >> S[i],
		S[i] = " " + S[i];
	F(i, 1, n)
		F(j, 1, m)
			if (S[i][j] == '#')
				block[Id(i, j)] = true;
	F(i, 1, n)
		F(j, 1, m) if (!block[Id(i, j)]) {
			int pr = (i ^ j) & 1;
			if (S[i][j] == '.')
				Ins(0, Id(i, j), 0ll, pr);
			if (!pr) {
				Ins(Id(i, j), Id(i - 1, j), 0ll);
				Ins(Id(i, j), Id(i, j - 1), 0ll);
				Ins(Id(i, j), Id(i + 1, j), 0ll);
				Ins(Id(i, j), Id(i, j + 1), 0ll);
			}
			if (S[i][j] == 'L')
				Ins(Id(i, j + 2), Id(i, j), q, pr),
				Ins(Id(i - 1, j + 1), Id(i, j), p, pr),
				Ins(Id(i + 1, j + 1), Id(i, j), p, pr);
			if (S[i][j] == 'R')
				Ins(Id(i, j - 2), Id(i, j), q, pr),
				Ins(Id(i - 1, j - 1), Id(i, j), p, pr),
				Ins(Id(i + 1, j - 1), Id(i, j), p, pr);
			if (S[i][j] == 'U')
				Ins(Id(i + 2, j), Id(i, j), q, pr),
				Ins(Id(i + 1, j - 1), Id(i, j), p, pr),
				Ins(Id(i + 1, j + 1), Id(i, j), p, pr);
			if (S[i][j] == 'D')
				Ins(Id(i - 2, j), Id(i, j), q, pr),
				Ins(Id(i - 1, j - 1), Id(i, j), p, pr),
				Ins(Id(i - 1, j + 1), Id(i, j), p, pr);
		}
	Dijkstra();
	int t = n * m + 2;
	if (dis[t] == InfLL)
		puts("-1");
	else
		printf("%lld\n", dis[t]);
}