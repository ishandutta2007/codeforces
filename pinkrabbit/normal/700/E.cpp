#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 200005;

struct SuffixArray {
	int N, Sig, Str[MN], SA[MN], rk[MN];
	int SA2[MN], Tmp[MN];
	int Height[MN];
	
	inline void RSort() {
		static int Buk[MN];
		for (int i = 1; i <= Sig; ++i) Buk[i] = 0;
		for (int i = 1; i <= N; ++i) ++Buk[rk[i]];
		for (int i = 1; i <= Sig; ++i) Buk[i] += Buk[i - 1];
		for (int i = N; i >= 1; --i) SA[Buk[rk[SA2[i]]]--] = SA2[i];
	}
	inline void BuildSA() {
		for (int i = 1; i <= N; ++i) rk[i] = Str[i], SA2[i] = i;
		rk[N + 1] = 0;
		Sig = 26, RSort();
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
	
	int Lg[MN], BLCP[MN][18], Bt;
	inline void InitST() {
		Lg[0] = -1;
		for (int i = 1; i <= N; ++i) Lg[i] = Lg[i >> 1] + 1, BLCP[i][0] = Height[i];
		while (2 << Bt <= N) ++Bt;
		for (int j = 1; j <= Bt; ++j)
			for (int i = 1 << j; i <= N; ++i)
				BLCP[i][j] = std::min(BLCP[i][j - 1], BLCP[i - (1 << (j - 1))][j - 1]);
	}
	inline int LCP(int x, int y) {
		if (x == y) return N + 1;
		x = rk[x], y = rk[y];
		if (x > y) std::swap(x, y);
		int j = Lg[y - x];
		return std::min(BLCP[y][j], BLCP[x + (1 << j)][j]);
	}
	inline void GetRange(int pos, int k, int &lb, int &rb) {
		int lj = 0;
		while (pos > 1 << lj && BLCP[pos][lj] >= k) ++lj;
		for (--lj, lb = pos; lj >= 0; --lj)
			if (lb > 1 << lj && BLCP[lb][lj] >= k)
				lb -= 1 << lj;
		int rj = 0;
		while (N - pos >= 1 << rj && BLCP[pos + (1 << rj)][rj] >= k) ++rj;
		for (--rj, rb = pos; rj >= 0; --rj)
			if (N - rb >= 1 << rj && BLCP[rb + (1 << rj)][rj] >= k)
				rb += 1 << rj;
	}
} SA;

struct dat {
	int k, x;
	dat() {}
	dat(int _k, int _x) : k(_k), x(_x) {}
	void z() { k = x = 0; }
	void z(int _k, int _x) { k = _k, x = _x; }
	bool t() { return k || x; }
	friend bool operator < (dat p, dat q) {
		return p.k == q.k ? p.x > q.x : p.k < q.k;
	}
};

const int MS = 1 << 19 | 7;

int N, Ans; char Str[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
dat val[MS]; int mnv[MS];
inline void P(int i, dat v) { val[i] = std::max(val[i], v); }
inline void Pushdown(int i) { if (val[i].t()) P(li, val[i]), P(ri, val[i]), val[i].z(); }
void Build(int i, int l, int r) {
	mnv[i] = N + 1;
	if (l == r) return val[i].z(1, 0);
	Build(ls), Build(rs);
	val[i].z();
}
void Mdf1(int i, int l, int r, int a, int b, dat v) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, v);
	Pushdown(i);
	Mdf1(ls, a, b, v), Mdf1(rs, a, b, v);
}
dat Qur1(int i, int l, int r, int p) {
	if (l == r) return val[i];
	Pushdown(i);
	return p <= mid ? Qur1(ls, p) : Qur1(rs, p);
}
void Mdf2(int i, int l, int r, int p, int v) {
	if (l == r) return mnv[i] = v, void();
	p <= mid ? Mdf2(ls, p, v) : Mdf2(rs, p, v);
	mnv[i] = std::min(mnv[li], mnv[ri]);
}
int Qur2(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return N + 1;
	if (a <= l && r <= b) return mnv[i];
	return std::min(Qur2(ls, a, b), Qur2(rs, a, b));
}

int main() {
	scanf("%d%s", &N, Str + 1), SA.N = N;
	for (int i = 1; i <= N; ++i) SA.Str[i] = Str[i] - 'a' + 1;
	SA.BuildSA(), SA.GetHeight(), SA.InitST();
	Build(1, 1, N);
	for (int i = N; i >= 1; --i) {
		int lb, rb, len;
		dat now = Qur1(1, 1, N, SA.rk[i]);
		Ans = std::max(Ans, now.k);
		if (now.k > 1) {
			SA.GetRange(SA.rk[i], now.x, lb, rb);
			len = Qur2(1, 1, N, lb, rb) - i + now.x;
		} else len = 1;
		SA.GetRange(SA.rk[i], len, lb, rb);
		Mdf1(1, 1, N, lb, rb, dat(now.k + 1, len));
		Mdf2(1, 1, N, SA.rk[i], i);
	}
	printf("%d\n", Ans);
	return 0;
}