#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;
const int HashMod = 981173233;
const int HashBase = 114514;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((LL)b * b % HashMod))
		if (e & 1) a = (int)((LL)a * b % HashMod);
	return a;
}
inline int gInv(int b) { return qPow(b, HashMod - 2); }

const int MLEN = 200005;
int arr_pws[MLEN * 2], *pws = arr_pws + MLEN;
void InitPws(int len) {
	pws[0] = 1;
	int invBase = gInv(HashBase);
	for (int i = 1; i <= len; ++i)
		pws[i] = (int)((LL)pws[i - 1] * HashBase % HashMod),
		pws[-i] = (int)((LL)pws[1 - i] * invBase % HashMod);
}

struct hsh {
	int len, val;
	hsh() : len(0), val(0) {}
	hsh(int x) : len(1), val(x) {}
	hsh(int l, int v) : len(l), val(v) {}
	friend hsh operator + (const hsh &p, const hsh &q) {
		return hsh(p.len + q.len, (int)(((LL)p.val * pws[q.len] + q.val) % HashMod));
	}
	friend hsh operator - (const hsh &p, const hsh &q) {
		return hsh(p.len - q.len, (int)((LL)(p.val - q.val + HashMod) * pws[-q.len] % HashMod));
	}
	friend hsh operator / (const hsh &p, const hsh &q) {
		return hsh(p.len - q.len, (int)((p.val + (LL)(HashMod - q.val) * pws[p.len - q.len]) % HashMod));
	}
	friend bool operator == (const hsh &p, const hsh &q) {
		return p.val == q.val && p.len == q.len;
	}
};

int totlen;
char str[MLEN];
hsh vv[MLEN];
int bel[MLEN];
inline hsh interval(int lb, int rb) {
	return vv[rb] / vv[lb - 1];
}

struct SuffixArray {
	int N, Str[MLEN], SA[MLEN], rk[MLEN], SA2[MLEN];
	int Sig, Buk[MLEN], Tmp[MLEN];
	int Height[MLEN];
	
	inline void RSort() {
		for (int i = 1; i <= Sig; ++i) Buk[i] = 0;
		for (int i = 1; i <= N; ++i) ++Buk[rk[i]];
		for (int i = 1; i <= Sig; ++i) Buk[i] += Buk[i - 1];
		for (int i = N; i >= 1; --i) SA[Buk[rk[SA2[i]]]--] = SA2[i];
	}
	inline void BuildSA() {
		/* Init Str */
		for (int i = 1; i <= N; ++i) rk[i] = Str[i], SA2[i] = i;
		rk[N + 1] = 0;
		Sig = 27 /* maximum letter in Str */, RSort();
		for (int j = 1; j < N; j <<= 1) {
			int P = 0;
			for (int i = 1; i <= j; ++i) SA2[++P] = N - j + i;
			for (int i = 1; i <= N; ++i) if (SA[i] > j) SA2[++P] = SA[i] - j;
			RSort();
			Tmp[SA[1]] = P = 1;
			for (int i = 2; i <= N; ++i) {
				if (rk[SA[i]] != rk[SA[i - 1]] || rk[SA[i] + j] != rk[SA[i - 1] + j]) ++P;
				Tmp[SA[i]] = P;
			}
			for (int i = 1; i <= N; ++i) rk[i] = Tmp[i];
			Sig = P;
			if (Sig == N) break;
		}
	}
	inline void GetHeight() {
		int k = 0;
		for (int i = 1; i <= N; ++i) {
			if (rk[i] == 1) k = Height[1] = 0;
			else {
				if (k) --k;
				int j = SA[rk[i] - 1];
				while (i + k <= N && j + k <= N && Str[i + k] == Str[j + k]) ++k;
				Height[rk[i]] = k;
			}
		}
	}
	
	int BLCP[18][MLEN];
	inline void InitST() {
		for (int i = 1; i <= N; ++i) BLCP[0][i] = Height[i];
		for (int j = 0; 2 << j <= N; ++j)
			for (int i = 2 << j; i <= N; ++i)
				BLCP[j + 1][i] = std::min(BLCP[j][i], BLCP[j][i - (1 << j)]);
	}
	inline int LCP(int x, int y) {
		if (x == y) return N + 1;
		x = rk[x], y = rk[y];
		if (x > y) std::swap(x, y);
		int j = 31 - __builtin_clz(y - x);
		return std::min(BLCP[j][y], BLCP[j][x + (1 << j)]);
	}
	inline void GetRange(int pos, int k, int &lb, int &rb) {
		int lj = 0;
		while (pos > 1 << lj && BLCP[lj][pos] >= k) ++lj;
		for (--lj, lb = pos; lj >= 0; --lj)
			if (lb > 1 << lj && BLCP[lj][lb] >= k)
				lb -= 1 << lj;
		int rj = 0;
		while (N - pos >= 1 << rj && BLCP[rj][pos + (1 << rj)] >= k) ++rj;
		for (--rj, rb = pos; rj >= 0; --rj)
			if (N - rb >= 1 << rj && BLCP[rj][rb + (1 << rj)] >= k)
				rb += 1 << rj;
	}
} SA;

const int MN = 100005;
int N;
struct edg { int v, w; };
std::vector<edg> G[MN];
inline void AddEdge(int u, int v, int c) {
	G[u].push_back(edg{v, c});
	G[v].push_back(edg{u, c});
}

int dep[MN], par[17][MN], wgh[MN];
hsh up[MN], dn[MN];
int hit[MN], pref[MN];
void DFS(int u, int p) {
	dep[u] = dep[par[0][u] = p] + 1;
	for (int j = 0; 2 << j < dep[u]; ++j)
		par[j + 1][u] = par[j][par[j][u]];
	hit[u] = 1;
	for (edg &e : G[u]) if (e.v != p) {
		wgh[e.v] = e.w;
		up[e.v] = e.w + up[u];
		dn[e.v] = dn[u] + e.w;
		DFS(e.v, u);
		hit[u] = std::max(hit[u], hit[e.v] + 1);
		if (hit[pref[u]] < hit[e.v])
			pref[u] = e.v;
	}
}
inline int LCA(int x, int y) {
	if (dep[x] < dep[y])
		std::swap(x, y);
	for (int d = dep[x] - dep[y], j = 0; d; d >>= 1, ++j)
		if (d & 1) x = par[j][x];
	if (x == y) return x;
	for (int j = 16; j >= 0; --j)
		if (par[j][x] != par[j][y])
			x = par[j][x],
			y = par[j][y];
	return par[0][x];
}
int top[MN], dfn[MN], idf[MN], dfc;
std::vector<int> chain[MN];
void DFS2(int u, int t) {
	top[u] = t;
	idf[dfn[u] = ++dfc] = u;
	if (u == t) {
		for (int i = 0, x = u; i <= hit[u]; ++i, x = par[0][x])
			chain[u].push_back(x);
	}
	if (pref[u]) DFS2(pref[u], t);
	for (edg &e : G[u])
		if (e.v != par[0][u] && e.v != pref[u])
			DFS2(e.v, e.v);
}
inline int kpar(int x, int k) { // TODO : long chain decomp (v)
	if (!k) return x;
	int j = 31 - __builtin_clz(k);
	x = par[j][x], k -= 1 << j;
	k -= dep[x] - dep[top[x]];
	return k >= 0 ? chain[top[x]][k] : idf[dfn[top[x]] - k];
}
inline int kthchar(int x, int y, int lca, int k) {
	if (k <= dep[x] - dep[lca])
		return wgh[kpar(x, k - 1)];
	return wgh[kpar(y, dep[x] + dep[y] - 2 * dep[lca] - k)];
}
inline hsh extract(int x, int y, int lca, int k) {
	if (k <= dep[x] - dep[lca])
		return up[x] - up[kpar(x, k)];
	return (up[x] - up[lca]) + (dn[kpar(y, dep[x] + dep[y] - 2 * dep[lca] - k)] / dn[lca]);
}

const int MM = 100005;
int M, bit[MM];

inline void Add(int i) {
	for (; i <= M; i += i & -i)
		++bit[i];
}
inline int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[i];
	return s;
}

const int MQ = 100005;
int qL[MQ], qR[MQ], Ans[MQ];
std::vector<int> qG[MLEN];

int main() {
	int Q;
	InitPws(200000);
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= N - 1; ++i) {
		int x, y;
		scanf("%d%d%s", &x, &y, str);
		AddEdge(x, y, str[0] - 'a' + 1);
	}
	DFS(1, 0);
	DFS2(1, 1);
	for (int i = 1; i <= M; ++i) {
		char *s = str + totlen;
		scanf("%s", s + 1);
		int len = (int)std::strlen(s + 1);
		for (int j = 1; j <= len; ++j)
			SA.Str[totlen + j] = s[j] - 'a' + 1,
			bel[totlen + j] = i;
		totlen += len;
		if (i != M)
			SA.Str[++totlen] = 27,
			str[totlen] = '{';
	}
	for (int i = 1; i <= totlen; ++i)
		vv[i] = vv[i - 1] + SA.Str[i];
	SA.N = totlen, SA.BuildSA(), SA.GetHeight(), SA.InitST();
	for (int q = 1; q <= Q; ++q) {
		int x, y, lca, len;
		scanf("%d%d%d%d", &x, &y, &qL[q], &qR[q]);
		lca = LCA(x, y);
		len = dep[x] + dep[y] - 2 * dep[lca];
		int lb = 1, rb = totlen - (M - 1), ans = -1;
		while (lb <= rb) {
			int mid = (lb + rb) / 2;
			int pos = SA.SA[mid];
			int lb2 = 1, rb2 = len, ans2 = 0;
			while (lb2 <= rb2) {
				int mid2 = (lb2 + rb2) / 2;
				if (pos + mid2 - 1 <= totlen && extract(x, y, lca, mid2) == interval(pos, pos + mid2 - 1)) ans2 = mid2, lb2 = mid2 + 1;
				else rb2 = mid2 - 1;
			}
			if (ans2 == len) {
				ans = mid;
				break;
			}
			if (kthchar(x, y, lca, ans2 + 1) < SA.Str[pos + ans2]) rb = mid - 1;
			else lb = mid + 1;
		}
		if (ans == -1) {
			Ans[q] = 0;
			continue;
		}
		int l, r;
		SA.GetRange(ans, len, l, r);
		qG[r].push_back(q);
		qG[l - 1].push_back(-q);
	}
	for (int i = 1; i <= totlen - (M - 1); ++i) {
		Add(bel[SA.SA[i]]);
		for (int tq : qG[i]) {
			int o = tq < 0 ? -1 : 1;
			int q = o * tq;
			int sum = Qur(qR[q]) - Qur(qL[q] - 1);
			Ans[q] += o * sum;
		}
	}
	for (int q = 1; q <= Q; ++q)
		printf("%d\n", Ans[q]);
	return 0;
}