#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 200005, MM = 300005, MQ = 500005;

int N, M, Q, p[MN], ip[MN];
int eu[MM], ev[MM], dt[MM];
int op[MQ], qv[MQ];

int pa[MN * 2], w[MN * 2], cnt;
int fp(int x) { return pa[x] ? pa[x] = fp(pa[x]) : x; }
std::vector<int> Tr[MN * 2];

int dep[MN * 2], par[18][MN * 2], ldf[MN * 2], rdf[MN * 2], idf[MN], dfc;
void DFS(int u, int pv) {
//	printf("DFS(%d, %d)\n", u, pv);
	dep[u] = dep[par[0][u] = pv] + 1;
	for (int j = 0; 2 << j < dep[u]; ++j)
		par[j + 1][u] = par[j][par[j][u]];
	if (u <= N) ++dfc, ldf[u] = dfc, rdf[u] = dfc, idf[dfc] = u;
	else ldf[u] = N + 1, rdf[u] = 0;
	for (int v : Tr[u]) {
		DFS(v, u);
		ldf[u] = std::min(ldf[u], ldf[v]);
		rdf[u] = std::max(rdf[u], rdf[v]);
	}
}

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
const int MS = 1 << 19 | 7;
int mx[MS];
void Build(int i, int l, int r) {
	if (l == r) return mx[i] = p[idf[l]], void();
	Build(ls), Build(rs);
	mx[i] = std::max(mx[li], mx[ri]);
}
void Mdf(int i, int l, int r, int pos) {
	if (l == r) return mx[i] = 0, void();
	pos <= mid ? Mdf(ls, pos) : Mdf(rs, pos);
	mx[i] = std::max(mx[li], mx[ri]);
}
int Qur(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return -1;
	if (a <= l && r <= b) return mx[i];
	return std::max(Qur(ls, a, b), Qur(rs, a, b));
}

int main() {
	scanf("%d%d%d", &N, &M, &Q), cnt = N;
	for (int i = 1; i <= N; ++i) scanf("%d", &p[i]), ip[p[i]] = i;
	for (int i = 1; i <= M; ++i) scanf("%d%d", &eu[i], &ev[i]);
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d", &op[i], &qv[i]);
		if (op[i] == 2) dt[qv[i]] = i;
	}
	for (int e = 1; e <= M; ++e) if (!dt[e]) {
		int u = eu[e], v = ev[e];
		u = fp(u), v = fp(v);
		if (u == v) continue;
		++cnt;
		pa[u] = cnt;
		pa[v] = cnt;
		Tr[cnt].push_back(u);
		Tr[cnt].push_back(v);
		w[cnt] = Q + 1;
	}
	for (int i = Q; i >= 1; --i) if (op[i] == 2) {
		int u = eu[qv[i]], v = ev[qv[i]];
		u = fp(u), v = fp(v);
		if (u == v) continue;
		++cnt;
		pa[u] = cnt;
		pa[v] = cnt;
		Tr[cnt].push_back(u);
		Tr[cnt].push_back(v);
		w[cnt] = i;
	}
	for (int i = 1; i <= cnt; ++i) if (!pa[i]) DFS(i, 0);
	Build(1, 1, N);
	for (int i = 1; i <= Q; ++i) if (op[i] == 1) {
		int u = qv[i];
		for (int j = 17; j >= 0; --j)
			if (par[j][u] && w[par[j][u]] > i)
				u = par[j][u];
		int ans = Qur(1, 1, N, ldf[u], rdf[u]);
		printf("%d\n", ans);
		if (ans) Mdf(1, 1, N, ldf[ip[ans]]);
	}
	return 0;
}