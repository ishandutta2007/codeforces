#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

const int MN = 500005, MM = 500005, MQ = 500005, MS = 1 << 20 | 7, MK = 51;

int N, M, K, Q;
int ea[MM], eb[MM], ncol[MM];
int qe[MQ], qc[MQ];
std::map<int, int> mpe;
int mpq[MK][MM], fa[MQ * 2], rk[MQ * 2], tg[MQ * 2], cnt;
int st[MM], tp;
inline void gvtx(int i, int &a, int &b) {
	a = mpq[qc[i]][ea[qe[i]]], b = mpq[qc[i]][eb[qe[i]]];
}
inline int gcol(int x, int &c) {
	c = tg[x];
	while (fa[x]) x = fa[x], c ^= tg[x];
	return x;
}
inline void merge(int x, int y) {
	int cx, cy, o;
	x = gcol(x, cx), y = gcol(y, cy), o = cx ^ cy ^ 1;
	if (x == y) return ;
	if (rk[x] < rk[y]) std::swap(x, y);
	rk[x] += rk[y], fa[y] = x, tg[y] ^= o, st[++tp] = (o ? -1 : 1) * y;
}
inline void undo1() {
	int o = st[tp] < 0 ? 1 : 0, y = (o ? -1 : 1) * st[tp];
	rk[fa[y]] -= rk[y], tg[y] ^= o, fa[y] = 0, --tp;
}
inline void undok(int k) { while (k--) undo1(); }

std::vector<int> vq[MS];
void Ins(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return vq[i].push_back(x);
	Ins(i << 1, l, (l + r) >> 1, a, b, x);
	Ins(i << 1 | 1, ((l + r) >> 1) + 1, r, a, b, x);
}
void Solve(int i, int l, int r) {
	int ntp = tp, a, b;
	for (auto j : vq[i]) if (qc[j]) {
		gvtx(j, a, b);
		merge(a, b);
	}
	if (l == r) {
		int j = l, e = qe[j], c = qc[j];
		if (ncol[e] != c) {
			gvtx(j, a, b);
			int ca, aa = gcol(a, ca);
			int cb, bb = gcol(b, cb);
			if (aa == bb && ca == cb) qc[j] = ncol[e], puts("NO");
			else ncol[e] = c, puts("YES");
		} else puts("YES");
	} else {
		Solve(i << 1, l, (l + r) >> 1);
		Solve(i << 1 | 1, ((l + r) >> 1) + 1, r);
	}
	undok(tp - ntp);
}

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= M; ++i) scanf("%d%d", &ea[i], &eb[i]);
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d", &qe[i], &qc[i]);
		int a = ea[qe[i]], b = eb[qe[i]];
		if (!mpq[qc[i]][a]) mpq[qc[i]][a] = ++cnt;
		if (!mpq[qc[i]][b]) mpq[qc[i]][b] = ++cnt;
		int &lpos = mpe[qe[i]];
		if (lpos) Ins(1, 1, Q, lpos + 1, i, lpos);
		lpos = i;
	}
	for (auto p : mpe) if (p.second < Q) Ins(1, 1, Q, p.second + 1, Q, p.second);
	for (int i = 1; i <= cnt; ++i) rk[i] = 1;
	Solve(1, 1, Q);
	return 0;
}