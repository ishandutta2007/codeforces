#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007, Inv2 = (Mod + 1) / 2;
const int MN = 300005, MQ = 300005, MS = 1 << 21 | 7;

int N, Q, A[MN], qpos[MQ], qval[MQ], D[MS], qP[MS], iqP[MS], C;

int _pw[MS], *pw = _pw + (MS / 2);

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
int ans[MS], s1[MS], s2[MS], tg1[MS], tg2[MS], cc[MS];
inline void P(int i, int x, int y, int c) {
	s1[i] = (LL)s1[i] * x % Mod;
	s2[i] = (LL)s2[i] * y % Mod;
	tg1[i] = (LL)tg1[i] * x % Mod;
	tg2[i] = (LL)tg2[i] * y % Mod;
	cc[i] += c;
}
inline void Pushdown(int i) {
	if (cc[i]) {
		P(li, tg1[i], tg2[i], cc[i]);
		P(ri, tg1[i], tg2[i], cc[i]);
		tg2[i] = tg1[i] = 1, cc[i] = 0;
	}
}
inline void Upd(int i) {
	s1[i] = (s1[li] + s1[ri]) % Mod;
	s2[i] = (s2[li] + s2[ri]) % Mod;
	ans[i] = (ans[li] + ans[ri] + (LL)s1[li] * s2[ri]) % Mod;
}
void Build(int i, int l, int r) {
	if (l == r) {
		ans[i] = s2[i] = s1[i] = 0;
		tg2[i] = tg1[i] = 1, cc[i] = 0;
		return ;
	}
	Build(ls), Build(rs);
	tg2[i] = tg1[i] = 1, cc[i] = 0;
}
void Mdf(int i, int l, int r, int p, int t) {
	if (l == r) {
		if (t) {
			++cc[i];
			s1[i] = (LL)pw[cc[i]] * D[p] % Mod;
			s2[i] = (LL)pw[-cc[i]] * D[p] % Mod;
			ans[i] = 0;
		} else {
			ans[i] = s2[i] = s1[i] = 0;
			--cc[i];
		}
		return ;
	}
	Pushdown(i);
	if (p <= mid) {
		if (t) P(ri, 2, Inv2, 1);
		else P(ri, Inv2, 2, -1);
		Mdf(ls, p, t);
	} else {
		Mdf(rs, p, t);
	}
	Upd(i);
//	printf("Mdf[%d : %d - %d] : (ans, s1, s2) = (%d, %d, %d)\n", i, l, r, ans[i], s1[i], s2[i]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), D[++C] = A[i];
	scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i) scanf("%d%d", &qpos[i], &qval[i]), D[++C] = qval[i];
	for (int i = 1; i <= C; ++i) qP[i] = i;
	std::sort(qP + 1, qP + C + 1, [](int i, int j) { return D[i] < D[j]; });
	std::sort(D + 1, D + C + 1);
	for (int i = 1; i <= C; ++i) iqP[qP[i]] = i;
	for (int i = 1; i <= N; ++i) A[i] = iqP[i];
	for (int i = 1; i <= Q; ++i) qval[i] = iqP[N + i];
//	for (int i = 1; i <= N; ++i) printf("%d, ", A[i]); puts("");
//	for (int i = 1; i <= Q; ++i) printf("%d %d\n", qpos[i], qval[i]);
	pw[0] = 1;
	for (int i = 1; i <= C; ++i)
		pw[i] = 2ll * pw[i - 1] % Mod,
		pw[-i] = (LL)Inv2 * pw[-i + 1] % Mod;
	Build(1, 1, C);
	for (int i = 1; i <= N; ++i) Mdf(1, 1, C, A[i], 1);
	printf("%lld\n", (LL)ans[1] * Inv2 % Mod);
	for (int i = 1; i <= Q; ++i) {
		int pz = qpos[i], vx = qval[i];
		Mdf(1, 1, C, A[pz], 0);
		Mdf(1, 1, C, A[pz] = vx, 1);
		printf("%lld\n", (LL)ans[1] * Inv2 % Mod);
	}
	return 0;
}