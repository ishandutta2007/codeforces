#include <cstdio>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
const int Mod = 998244353;
const int MN = 200005;
const int MS = 4 * MN;
const int MB = 2 * MN;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MB], Fac[MB], iFac[MB];
inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N] = gInv(Fac[N]);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
	for (int i = 1; i <= N; ++i) Inv[i] = (LL)Fac[i - 1] * iFac[i] % Mod;
}
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
}

int N, M, x[MN], y[MN];

unsigned int pri[MS];
int lc[MS], rc[MS], num[MS], siz[MS], typ[MS], cnt;
inline int Newnode(int c, int v) {
	int i = ++cnt;
	pri[i] = rng(), lc[i] = rc[i] = 0, siz[i] = num[i] = c, typ[i] = v;
	return i;
}
inline void PushUp(int i) { siz[i] = siz[lc[i]] + num[i] + siz[rc[i]]; }
int Merge(int i1, int i2) {
	if (!i1 || !i2) return i1 | i2;
	if (pri[i1] < pri[i2]) {
		rc[i1] = Merge(rc[i1], i2);
		PushUp(i1);
		return i1;
	} else {
		lc[i2] = Merge(i1, lc[i2]);
		PushUp(i2);
		return i2;
	}
}
void Split(int i, int k, int &i1, int &i2, int &i3) {
//	printf("Split(%d, %d)\n", i, k);
	if (k <= siz[lc[i]]) {
		Split(lc[i], k, i1, i2, i3);
		lc[i] = i3;
		PushUp(i);
		i3 = i;
	} else if (siz[lc[i]] + num[i] < k) {
		Split(rc[i], k - siz[lc[i]] - num[i], i1, i2, i3);
		rc[i] = i1;
		PushUp(i);
		i1 = i;
	} else {
		i1 = lc[i];
		i3 = rc[i];
		lc[i] = rc[i] = 0;
		PushUp(i);
		i2 = i;
	}
}
/*
void Print(int i) {
	if (!i) return ;
	Print(lc[i]);
	printf("[%d (%d, %d) : %c %d]  ", i, lc[i], rc[i], "<="[typ[i]], num[i]);
	Print(rc[i]);
}
*/

inline void Solve() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i)
		scanf("%d%d", &x[i], &y[i]);
	// y[i] = x[i] for others (N - M)
	if (x[M] != N) {
		x[++M] = N;
		y[M] = N;
	}
	int Ans = 0;
	cnt = 0;
	int root = Newnode(1, 0);
	int lst = 0;
	for (int i = 1; i <= M; ++i) {
		int i1, i2, i3;
		if (x[i] - lst >= 2) {
			int len = x[i] - lst - 1;
			Split(root, lst + 1, i1, i2, i3);
			int nw = Newnode(len, 1);
			root = Merge(Merge(i1, nw), i2);
			Ans += len;
//			Print(root), puts("");
		}
		Split(root, y[i], i1, i2, i3);
//		printf("i1 : "), Print(i1), puts("");
//		printf("i2 : "), Print(i2), puts("");
//		printf("i3 : "), Print(i3), puts("");
		int k = y[i] - siz[i1];
//		printf("k = %d, num[i2] = %d\n", k, num[i2]);
		int nw1 = k > 1 ? Newnode(k - 1, typ[i2]) : 0;
		int nw2 = k < num[i2] ? Newnode(num[i2] - k, typ[i2]) : 0;
		int ins1 = Newnode(1, 1);
		int ins2 = Newnode(1, 0);
		root = Merge(Merge(Merge(Merge(Merge(i1, nw1), ins1), ins2), nw2), i3);
		Ans += 1 - typ[i2];
//		Print(root), puts("");
		lst = x[i];
	}
	printf("%d\n", Binom(N + Ans - 1, N));
}

int main() {
	Init(400000);
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) Solve();
	return 0;
}