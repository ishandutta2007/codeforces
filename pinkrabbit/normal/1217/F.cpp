#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

typedef std::pair<int, int> pii;
const int MN = 200005, MQ = 200005, MS = 524288;

int N, Q;
int op[MQ], qu[MQ], qv[MQ], nxp0[MQ], nxp1[MQ];

inline void Prework() {
	std::map<pii, int> Edg;
	for(int i = Q; i >= 1; i--) {
		if(op[i] == 2) continue;
		int u0 = qu[i], v0 = qv[i], u1 = u0 % N + 1, v1 = v0 % N + 1;
		if (u0 > v0) std::swap(u0, v0);
		if (u1 > v1) std::swap(u1, v1);
		pii e0(u0, v0), e1(u1, v1);
		nxp0[i] = Edg.find(e0) != Edg.end() ? Edg[e0] : 2 * Q + 2;
		nxp1[i] = Edg.find(e1) != Edg.end() ? Edg[e1] : 2 * Q + 2;
		Edg[e0] = i << 1, Edg[e1] = i << 1 | 1;
	}
}

int fa[MN], rnk[MN];
int ff(int x) { return fa[x] ? ff(fa[x]) : x; }
int stk[MQ], top;
inline void merge(int u, int v) {
	u = ff(u), v = ff(v);
	if (u == v) return ;
	if (rnk[u] < rnk[v]) std::swap(u, v);
	fa[v] = u, rnk[u] += rnk[v];
	stk[++top] = v;
}

int lastans;
std::vector<pii> V[MS];
bool lsp0[MQ], lsp1[MQ];

void Insert(int i, int l, int r, int a, int b, pii x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) { V[i].push_back(x); return ; }
	int mid = (l + r) >> 1;
	Insert(i << 1, l, mid, a, b, x);
	Insert(i << 1 | 1, mid + 1, r, a, b, x);
}

void Solve(int rt, int l, int r) {
	int nowtop = top;
	for (auto e : V[rt]) merge(e.first, e.second);
	if (l == r) {
		int u0 = qu[l], v0 = qv[l];
		int u1 = u0 % N + 1, v1 = v0 % N + 1;
		if (lastans) std::swap(u0, u1), std::swap(v0, v1);
		if (op[l] == 1) {
			bool l0 = lsp0[l], l1 = lsp1[l];
			if (lastans) std::swap(l0, l1);
			if (!l0) {
				int nxt = (lastans ? nxp1 : nxp0)[l], pos = nxt >> 1;
				(nxt & 1 ? lsp1 : lsp0)[pos] = 1;
				if (pos >= l + 2) Insert(1, 1, Q, l + 1, pos - 1, pii(u0, v0));
			}
			if (l1) {
				int nxt = (lastans ? nxp0 : nxp1)[l], pos = nxt >> 1;
				(nxt & 1 ? lsp1 : lsp0)[pos] = 1;
				if (pos >= l + 2) Insert(1, 1, Q, l + 1, pos - 1, pii(u1, v1));
			}
		}
		else putchar('0' + (lastans = ff(u0) == ff(v0)));
	}
	else {
		int mid = (l + r) >> 1;
		Solve(rt << 1, l, mid);
		Solve(rt << 1 | 1, mid + 1, r);
	}
	for (int v; top > nowtop; --top)
		v = stk[top], rnk[fa[v]] -= rnk[v], fa[v] = 0;
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= Q; ++i) scanf("%d%d%d", &op[i], &qu[i], &qv[i]);
	if (N == 2) {
		int a = 0;
		for (int i = 1; i <= Q; ++i)
			if (op[i] == 1) a ^= 1;
			else putchar(a ? '1' : '0');
		return 0;
	}
	Prework();
	for (int i = 1; i <= N; ++i) rnk[i] = 1;
	Solve(1, 1, Q);
	return 0;
}