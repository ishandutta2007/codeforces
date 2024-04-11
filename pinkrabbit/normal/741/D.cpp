#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int nInf = 0xc0c0c0c0;
const int MN = 500005;
const int Sig = 22;

int N;
int par[MN], val[MN];
int dep[MN], siz[MN];
std::vector<int> G[MN];
int Ans[MN];

int f[1 << Sig];
int seq[MN], len;
inline int Check(int x) {
	int ret = f[x];
	for (int j = 0; j < Sig; ++j)
		ret = std::max(ret, f[x ^ 1 << j]);
	return ret;
}
inline int Solve() {
	int ret = nInf;
	for (int i = 1; i <= len; ++i)
		ret = std::max(ret, Check(val[seq[i]]) + dep[seq[i]]);
	for (int i = 1; i <= len; ++i)
		f[val[seq[i]]] = std::max(f[val[seq[i]]], dep[seq[i]]);
	return ret;
}
void DFS_extract(int u) {
	seq[++len] = u;
	for (int v : G[u])
		DFS_extract(v);
}
void DFS_clear(int u) {
	f[val[u]] = nInf;
	for (int v : G[u])
		DFS_clear(v);
}
void DFS(int u) {
	int pref = 0;
	for (int v : G[u])
		if (siz[v] > siz[pref])
			pref = v;
	for (int v : G[u]) if (v != pref)
		DFS(v), DFS_clear(v);
	if (pref) DFS(pref);
	int ans = 2 * dep[u];
	seq[len = 1] = u;
	ans = std::max(ans, Solve());
	for (int v : G[u]) if (v != pref) {
		len = 0, DFS_extract(v);
		ans = std::max(ans, Solve());
	}
	ans -= 2 * dep[u];
	for (int v : G[u])
		ans = std::max(ans, Ans[v]);
	Ans[u] = ans;
}

int main() {
	scanf("%d", &N);
	dep[1] = 1;
	for (int i = 2; i <= N; ++i) {
		char str[3];
		scanf("%d%s", &par[i], str);
		val[i] = 1 << (*str - 'a');
		G[par[i]].push_back(i);
		val[i] ^= val[par[i]];
		dep[i] = dep[par[i]] + 1;
	}
	for (int i = N; i >= 1; --i)
		siz[par[i]] += ++siz[i];
	siz[0] = 0;
	memset(f, 0xc0, sizeof f);
	DFS(1);
	for (int i = 1; i <= N; ++i)
		printf("%d%c", Ans[i], " \n"[i == N]);
	return 0;
}