#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

typedef long long LL;
const int Mod = 1518500213, B = 31, iB = 1224596946;
const int MN = 300005, MZ = 45;

int N, Q; char S[MN];
std::vector<int> G[MN];

int faz[MN], dep[MN], siz[MN], son[MN], top[MN], dfn[MN], idf[MN], dfc;
int c[MN], ic[MN], val1[MN], val2[MN];
void DFS0(int u, int f) {
	dep[u] = dep[faz[u] = f] + 1, siz[u] = 1;
	val1[u] = ((LL)val1[f] * B + S[u] - 'a' + 1) % Mod;
	val2[u] = (val2[f] + (LL)c[dep[u] - 1] * (S[u] - 'a' + 1)) % Mod;
	for (auto v : G[u]) if (v != f) {
		DFS0(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void DFS1(int u, int t) {
	idf[dfn[u] = ++dfc] = u, top[u] = t;
	if (son[u]) DFS1(son[u], t);
	for (auto v : G[u]) if (v != faz[u] && v != son[u]) DFS1(v, v);
}
inline int gval(int u, int v) {
	if (dep[u] > dep[v]) return (val1[u] + (LL)val1[faz[v]] * (Mod - c[dep[u] - dep[v] + 1])) % Mod;
	return ((LL)val2[v] - val2[faz[u]] + Mod) * ic[dep[u] - 1] % Mod;
}
inline int calc(int u, int v, int k) {
	if (k == 1) return S[u] - 'a' + 1;
	if (dep[u] > dep[v]) v = idf[dfn[u] - k + 1];
	else v = idf[dfn[u] + k - 1];
	return gval(u, v);
}
inline int Splitz(int u, int v, int *st, int *ed) {
	static int uCh[MZ], vCh[MZ];
	int uT = 0, vT = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			uCh[++uT] = u;
			u = faz[top[u]];
		} else {
			vCh[++vT] = v;
			v = faz[top[v]];
		}
	}
	for (int i = 1; i <= uT; ++i) st[i] = uCh[i], ed[i] = top[uCh[i]];
	st[uT + 1] = u, ed[uT + 1] = v;
	for (int i = 1; i <= vT; ++i) st[uT + vT - i + 2] = top[vCh[i]], ed[uT + vT - i + 2] = vCh[i];
	st[uT + vT + 2] = ed[uT + vT + 2] = 0;
	return uT + vT + 1;
}

int main() {
	scanf("%d%s", &N, S + 1), ic[0] = c[0] = 1;
	for (int i = 1; i <= N; ++i) c[i] = (LL)c[i - 1] * B % Mod;
	for (int i = 1; i <= N; ++i) ic[i] = (LL)ic[i - 1] * iB % Mod;
	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	DFS0(1, 0), DFS1(1, 1);
	scanf("%d", &Q);
	for (int q = 1; q <= Q; ++q) {
		static int a, b, c, d, st1[MZ], ed1[MZ], st2[MZ], ed2[MZ], l1, l2;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		l1 = Splitz(a, b, st1, ed1);
		l2 = Splitz(c, d, st2, ed2);
		int na = a, nb = c, i = 1, j = 1, ans = 0;
		while (i <= l1 && j <= l2) {
			int len1 = std::abs(dep[na] - dep[ed1[i]]) + 1;
			int len2 = std::abs(dep[nb] - dep[ed2[j]]) + 1;
			int clen = std::min(len1, len2);
			int val1 = calc(na, ed1[i], clen);
			int val2 = calc(nb, ed2[j], clen);
			if (val1 == val2) {
				ans += clen;
				if (clen == len1) na = st1[++i];
				else na = idf[dfn[na] + (dep[ed1[i]] < dep[na] ? -clen : clen)];
				if (clen == len2) nb = st2[++j];
				else nb = idf[dfn[nb] + (dep[ed2[j]] < dep[nb] ? -clen : clen)];
			}
			else {
				int l = 1, r = clen - 1, mid, z = 0;
				while (l <= r) {
					mid = (l + r) >> 1;
					if (calc(na, ed1[i], mid) != calc(nb, ed2[j], mid)) r = mid - 1;
					else z = mid, l = mid + 1;
				}
				ans += z;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}