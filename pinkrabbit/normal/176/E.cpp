#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

typedef long long LL;
const int MN = 100005;

int N, uv[MN], w[MN];
std::vector<int> G[MN];
int dfn[MN], idf[MN], faz[MN], siz[MN], dep[MN], son[MN], top[MN], dfc;
LL dis[MN];
void DFS1(int u, int fz) {
	faz[u] = fz, siz[u] = 1;
	for (auto i : G[u]) {
		int v = u ^ uv[i];
		if (v == fz) continue;
		dis[v] = dis[u] + w[i];
		dep[v] = dep[u] + 1;
		DFS1(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void DFS2(int u, int t) {
	top[u] = t;
	idf[dfn[u] = ++dfc] = u;
	if (son[u]) DFS2(son[u], t);
	for (auto i : G[u]) {
		int v = u ^ uv[i];
		if (v == faz[u] || v == son[u]) continue;
		DFS2(v, v);
	}
}
inline LL dist(int u, int v) {
	LL s = dis[u] + dis[v];
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
		u = faz[top[u]];
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	return s - 2 * dis[u];
}

int Q;
LL Ans;
std::set<int> st;

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		uv[i] = x ^ y, w[i] = z;
		G[x].push_back(i);
		G[y].push_back(i);
	}
	DFS1(1, 0), DFS2(1, 1);
	scanf("%d", &Q);
	while (Q--) {
		char s[3];
		int u;
		scanf("%s", s);
		if (*s == '?') printf("%lld\n", Ans / 2);
		else {
			scanf("%d", &u);
			int d = dfn[u];
			auto it = st.begin(), tmp = it;
			if (*s == '+') it = st.insert(d).first;
			else it = st.find(d);
			int lst, nxt;
			lst = idf[d == *st.begin() ? *st.rbegin() : *--(tmp = it)];
			nxt = idf[d == *st.rbegin() ? *st.begin() : *++(tmp = it)];
			Ans += (*s == '+' ? 1 : -1) * (dist(u, lst) + dist(u, nxt) - dist(lst, nxt));
			if (*s == '-') st.erase(d);
		}
	}
	return 0;
}