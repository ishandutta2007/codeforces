#include <cstdio>
#include <vector>
#include <map>

typedef long long LL;
const int MN = 100005;

int N, M, _10, Inv10;
int uv[MN], w[MN];
std::vector<int> G[MN];

int vis[MN], siz[MN], tsiz, rsiz, rt;
void GetRoot(int u, int fz) {
	siz[u] = 1;
	int nsiz = 0;
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v] || v == fz) continue;
		GetRoot(v, u), siz[u] += siz[v];
		if (nsiz < siz[v]) nsiz = siz[v];
	}
	if (nsiz < tsiz - siz[u]) nsiz = tsiz - siz[u];
	if (rsiz > nsiz) rt = u, rsiz = nsiz;
}
LL Ans;
std::map<int, int> mp1, mp2;
void DFS0(int u, int fz, int b, int s, std::map<int, int> &mp) {
	++mp[s];
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v] || v == fz) continue;
		DFS0(v, u, (LL)b * _10 % M, (s + (LL)b * w[i]) % M, mp);
	}
}
void DFS1(int u, int fz, int b, int s) {
	int v = s ? (LL)b * (M - s) % M : 0;
	Ans += mp1[v] - mp2[v];
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v] || v == fz) continue;
		DFS1(v, u, (LL)b * Inv10 % M, (s * 10ll + w[i]) % M);
	}
}
void Solve(int u) {
	mp1.clear();
	DFS0(u, 0, 1 % M, 0, mp1);
	Ans += mp1[0];
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v]) continue;
		mp2.clear();
		DFS0(v, u, _10, w[i] % M, mp2);
		DFS1(v, u, Inv10, w[i] % M);
	}
	vis[u] = 1;
	int nsiz = tsiz;
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v]) continue;
		rsiz = tsiz = siz[v] < siz[u] ? siz[v] : nsiz - siz[u];
		GetRoot(v, 0), Solve(rt);
	}
}

int main() {
	scanf("%d%d", &N, &M), _10 = 10 % M;
	if (M % 10 == 1) Inv10 = (M * 9ll + 1) / 10 % M;
	else if (M % 10 == 3) Inv10 = (M * 3ll + 1) / 10 % M;
	else if (M % 10 == 7) Inv10 = (M * 7ll + 1) / 10 % M;
	else Inv10 = (M + 1) / 10 % M;
	for (int i = 1; i < N; ++i) {
		int u, v;
		scanf("%d%d%d", &u, &v, &w[i]);
		uv[i] = ++u ^ ++v;
		G[u].push_back(i);
		G[v].push_back(i);
	}
	rsiz = tsiz = N, GetRoot(1, 0), Solve(rt);
	printf("%lld\n", Ans - N);
	return 0;
}