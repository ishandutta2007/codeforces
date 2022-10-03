#include <cstdio>
#include <vector>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 100005;

int N, L, R, Ans = -1, AnsU, AnsV;
int uv[MN], w[MN];
std::vector<int> G[MN];
int dw[MN], M;

int vis[MN], siz[MN], tsiz, rsiz, Root;
void GetRoot(int u, int fz) {
	siz[u] = 1;
	int nsiz = 0;
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (v == fz || vis[v]) continue;
		GetRoot(v, u), siz[u] += siz[v];
		if (nsiz < siz[v]) nsiz = siz[v];
	}
	if (nsiz < tsiz - siz[u]) nsiz = tsiz - siz[u];
	if (rsiz > nsiz) rsiz = nsiz, Root = u;
}
int stk[MN], tp, _U;
inline bool cmp(int i, int j) {
	return siz[uv[i] ^ _U] < siz[uv[j] ^ _U];
}
int seq[MN], sequ[MN], odep, tmp[MN], tmpu[MN], ndep;
void DFS(int u, int fz, int d, int x, int y) {
	if (tmp[d] < x) tmp[d] = x, tmpu[d] = u;
	if (ndep < d) ndep = d;
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (v == fz || vis[v]) continue;
		DFS(v, u, d + 1, x + (w[i] >= y ? 1 : -1), y);
	}
}
int ucal, vcal;
bool Calc(int u, int x) {
	static int que[MN];
	seq[odep = 0] = 0, sequ[0] = u;
	for (int i = 1; i <= tp; ++i) {
		int v = uv[stk[i]] ^ u;
		for (int j = 1; j <= siz[v]; ++j) tmp[j] = -Inf;
		ndep = 0, DFS(v, u, 1, w[stk[i]] >= x ? 1 : -1, x);
		int l = 1, r = 0, lb = odep, rb = odep + 1;
		for (int j = 1; j <= ndep; ++j) {
			while (rb > 0 && rb > L - j) {
				--rb;
				while (l <= r && seq[que[r]] < seq[rb]) --r;
				que[++r] = rb;
			}
			while (lb >= 0 && lb > R - j) {
				--lb;
				while (l <= r && que[l] > lb) ++l;
			}
			if (l <= r && seq[que[l]] + tmp[j] >= 0) {
				ucal = sequ[que[l]], vcal = tmpu[j];
				return 1;
			}
		}
		while (odep < ndep) seq[++odep] = -Inf;
		for (int j = 1; j <= ndep; ++j)
			if (seq[j] < tmp[j])
				seq[j] = tmp[j], sequ[j] = tmpu[j];
	}
	return 0;
}
void Solve(int u) {
	int nsiz = tsiz;
	tp = 0;
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v]) continue;
		siz[v] = siz[v] > siz[u] ? nsiz - siz[u] : siz[v];
		stk[++tp] = i;
	}
	_U = u, std::sort(stk + 1, stk + tp + 1, cmp);
	int lb = 1, rb = M, mid, ans = 0, ansu = 0, ansv = 0;
	while (lb <= rb) {
		mid = (lb + rb) >> 1;
		if (Calc(u, dw[mid])) {
			ans = mid;
			ansu = ucal, ansv = vcal;
			lb = mid + 1;
		}
		else rb = mid - 1;
	}
	if (Ans < dw[ans]) {
		Ans = dw[ans];
		AnsU = ansu, AnsV = ansv;
	}
	vis[u] = 1;
	for (auto i : G[u]) {
		int v = uv[i] ^ u;
		if (vis[v]) continue;
		rsiz = tsiz = siz[v], GetRoot(v, 0), Solve(Root);
	}
}

int main() {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 1; i < N; ++i) {
		int x, y;
		scanf("%d%d%d", &x, &y, &w[i]);
		uv[i] = x ^ y;
		G[x].push_back(i);
		G[y].push_back(i);
		dw[i] = w[i];
	}
	std::sort(dw + 1, dw + N);
	M = std::unique(dw + 1, dw + N) - dw - 1;
	rsiz = tsiz = N, GetRoot(1, 0), Solve(Root);
	printf("%d %d\n", AnsU, AnsV);
	return 0;
}