#include <cstdio>
#include <algorithm>

const int ML = 600005;

char S[ML];

namespace SuffixArray {
	int str[ML];
	int Len, Sig, rk[ML], SA[ML], SA2[ML], buk[ML], tmp[ML];
	int Height[ML];
	inline void getHeight() {
		for (int i = 1, k = 0; i <= Len; ++i) {
			if (rk[i] == 1) { Height[rk[i]] = k = 0; continue; }
			if (k) --k;
			int j = SA[rk[i] - 1];
			while (i + k <= Len && j + k <= Len && str[i + k] == str[j + k]) ++k;
			Height[rk[i]] = k;
		}
	}
	inline void RSort() {
		for (int i = 1; i <= Sig; ++i) buk[i] = 0;
		for (int i = 1; i <= Len; ++i) ++buk[rk[i]];
		for (int i = 1; i <= Sig; ++i) buk[i] += buk[i - 1];
		for (int i = Len; i >= 1; --i) SA[buk[rk[SA2[i]]]--] = SA2[i];
	}
	inline void getSA() {
		rk[Len + 1] = 0;
		for (int i = 1; i <= Len; ++i) rk[i] = str[i], SA2[i] = i;
		RSort();
		for (int j = 1; j <= Len; j <<= 1) {
			int p = 0;
			for (int i = Len - j + 1; i <= Len; ++i) SA2[++p] = i;
			for (int i = 1; i <= Len; ++i) if (SA[i] > j) SA2[++p] = SA[i] - j;
			RSort();
			tmp[SA[1]] = p = 1;
			for (int i = 2; i <= Len; ++i) {
				int lst = SA[i - 1], now = SA[i];
				if (rk[lst] != rk[now] || rk[lst + j] != rk[now + j]) ++p;
				tmp[SA[i]] = p;
			}
			for (int i = 1; i <= Len; ++i) rk[i] = tmp[i];
			if ((Sig = p) == Len) break;
		}
		getHeight();
	}
	inline void Init() { Len = Sig = 0; }
	inline void AddChar(int ch) { Sig = std::max(Sig, str[++Len] = ch); }
}
using SuffixArray::AddChar;
using SuffixArray::Len;
using SuffixArray::SA;
using SuffixArray::rk;
using SuffixArray::Height;

const int MM = 50005, MS = 20400005;

#define mid ((l + r) >> 1)
int Ans1, Ans2;
int rt[ML * 2], ls[MS], rs[MS], mxv[MS], mxi[MS], cnt;
void Build(int &i, int l, int r, int p) {
	mxv[++cnt] = 1, mxi[cnt] = p, i = cnt;
	if (l == r) return ;
	if (p <= mid) Build(ls[i], l, mid, p);
	else Build(rs[i], mid + 1, r, p);
}
int Merge(int i1, int i2, int l, int r) {
	if (!i1 || !i2) return i1 + i2;
	int i = ++cnt;
	if (l == r) {
		mxv[i] = mxv[i1] + mxv[i2];
		mxi[i] = l;
		return i;
	}
	ls[i] = Merge(ls[i1], ls[i2], l, mid);
	rs[i] = Merge(rs[i1], rs[i2], mid + 1, r);
	int *lr = mxv[ls[i]] >= mxv[rs[i]] ? ls : rs;
	mxv[i] = mxv[lr[i]], mxi[i] = mxi[lr[i]];
	return i;
}
void Qur(int i, int l, int r, int a, int b) {
	if (!i || r < a || b < l) return ;
	if (a <= l && r <= b) {
		if (mxv[i] > Ans2) Ans1 = mxi[i], Ans2 = mxv[i];
		return ;
	}
	Qur(ls[i], l, mid, a, b);
	Qur(rs[i], mid + 1, r, a, b);
}

int M, bel[ML], perm[ML];
int fa[ML * 2], fcnt;
int ff(int x) { return fa[x] ? fa[x] = ff(fa[x]) : x; }
int lc[ML * 2], rc[ML * 2], wgh[ML * 2];
int dep[ML * 2], faz[ML * 2][21];
void DFS(int u, int fz) {
	dep[u] = dep[faz[u][0] = fz] + 1;
	for (int j = 0; 2 << j < dep[u]; ++j)
		faz[u][j + 1] = faz[faz[u][j]][j];
	if (u > Len) {
		DFS(lc[u], u), DFS(rc[u], u);
		rt[u] = Merge(rt[lc[u]], rt[rc[u]], 1, M);
	} else if (bel[u]) Build(rt[u], 1, M, bel[u]);
}

int main() {
	int idx;
	scanf("%s", S);
	for (idx = 0; S[idx]; ++idx) AddChar(S[idx] - 'a' + 1);
	scanf("%d", &M);
	for (int m = 1; m <= M; ++m) {
		AddChar(m + 26);
		scanf("%s", S);
		for (idx = 0; S[idx]; ++idx) AddChar(S[idx] - 'a' + 1), bel[Len] = m;
	}
	SuffixArray::getSA();
	for (int i = 2; i <= Len; ++i) perm[i] = i;
	std::sort(perm + 2, perm + Len + 1, [](int i, int j) { return Height[i] > Height[j]; });
	fcnt = Len;
	for (int i = 2; i <= Len; ++i) {
		int u = ff(SA[perm[i]]), v = ff(SA[perm[i] - 1]);
		fa[u] = fa[v] = ++fcnt;
		lc[fcnt] = u, rc[fcnt] = v;
		wgh[fcnt] = Height[perm[i]];
	}
	DFS(fcnt, 0);
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int li, ri, pos, len;
		scanf("%d%d%d%d", &li, &ri, &pos, &len), len -= pos - 1;
		int j = 0;
		while (faz[pos][j] && wgh[faz[pos][j]] >= len) ++j;
		for (--j; j >= 0; --j) if (faz[pos][j] && wgh[faz[pos][j]] >= len) pos = faz[pos][j];
		Ans1 = li, Ans2 = 0, Qur(rt[pos], 1, M, li, ri);
		printf("%d %d\n", Ans1, Ans2);
	}
	return 0;
}