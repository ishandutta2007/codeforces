#include <cstdio>

typedef long long LL;
const int MN = 100005;
const int MM = 400005;
const int MB = 100025;
const int BB = 100020;
const int MS = 20000005;
const int HB = 3;
const int HM = 1004535809;
const int MZ = 262144;
const int Mod = 1000000007;

int khs[MB], mhs[MB], pw2[MB];
inline void Init(int N) {
	khs[0] = pw2[0] = 1;
	for (int i = 1; i <= N; ++i) khs[i] = (LL)khs[i - 1] * HB % HM;
	for (int i = 1; i <= N; ++i) mhs[i] = (mhs[i - 1] + khs[i - 1]) % HM;
	for (int i = 1; i <= N; ++i) pw2[i] = pw2[i - 1] * 2ll % Mod;
}

int N, M, S, T;
int h[MN], nxt[MM], to[MM], w[MM], tot;
inline void ins(int x, int y, int z) {
	nxt[++tot] = h[x], to[tot] = y, w[tot] = z, h[x] = tot;
}

int hs[MS], ls[MS], rs[MS], cnt;
inline void upd(int i, int s) { hs[i] = ((LL)khs[s] * hs[rs[i]] + hs[ls[i]]) % HM; }
int Calc(int i, int l = 0, int r = BB) {
	if (!~i) return -1; if (!i) return 0;
	if (l == r) return 1;
	int mid = (l + r) >> 1;
	int L = Calc(ls[i], l, mid), R = Calc(rs[i], mid + 1, r);
	if (!~L || !~R) return -1;
	return (L + (LL)pw2[mid - l + 1] * R) % Mod;
}
bool less(int i, int j, int l = 0, int r = BB) {
	if (!~i) return 0; if (!~j) return 1;
	if (!j) return 0; if (!i) return 1;
	if (l == r) return 0;
	int mid = (l + r) >> 1;
	if (hs[rs[i]] == hs[rs[j]]) {
		int d = less(ls[i], ls[j], l, mid);
		return d;
	}
	int d = less(rs[i], rs[j], mid + 1, r);
	return d;
}
bool Add(int &i, int p, int l = 0, int r = BB) {
	if (p == l && hs[i] == mhs[r - l + 1]) return i = 0, 1;
	if (l == r) return hs[i = ++cnt] = mhs[1], 0;
	int mid = (l + r) >> 1, lc = ls[i], rc = rs[i];
	if (p > mid) {
		int d = Add(rc, p, mid + 1, r);
		if (!lc && !rc) return i = 0, 1;
		return ls[i = ++cnt] = lc, rs[i] = rc, upd(i, mid - l + 1), d;
	}
	int d = Add(lc, p, l, mid);
	if (!d) return ls[i = ++cnt] = lc, rs[i] = rc, upd(i, mid - l + 1), 0;
	d = Add(rc, mid + 1, mid + 1, r);
	if (!lc && !rc) return i = 0, 1;
	return ls[i = ++cnt] = lc, rs[i] = rc, upd(i, mid - l + 1), d;
}

int rt[MN], fr[MN], id[MZ], Sz;
void Upd(int p, int z) {
	id[p += Sz] = z;
	for (p >>= 1; p; p >>= 1) {
		if (less(rt[id[p << 1]], rt[id[p << 1 | 1]])) id[p] = id[p << 1];
		else id[p] = id[p << 1 | 1];
	}
}
void Dijk() {
	for (Sz = 1; Sz < N + 2; Sz <<= 1) ;
	for (int i = 0; i <= N; ++i) rt[i] = -1;
	rt[S] = 0, Upd(S, S);
	for (int t = 1; t <= N; ++t) {
		int u = id[1];
		for (int i = h[u]; i; i = nxt[i]) {
			int tmp = rt[u];
			Add(tmp, w[i]);
			if (less(tmp, rt[to[i]]))
				rt[to[i]] = tmp, Upd(to[i], to[i]), fr[to[i]] = u;
		}
		Upd(u, 0);
	}
}

int Ans, stk[MN], tp;

int main() {
	Init(BB + 1);
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y, z; i <= M; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		ins(x, y, z), ins(y, x, z);
	}
	scanf("%d%d", &S, &T);
	Dijk();
	printf("%d\n", Ans = Calc(rt[T]));
	if (!~Ans) return 0;
	int now = T;
	while (now) stk[++tp] = now, now = fr[now];
	printf("%d\n", tp);
	while (tp) printf("%d ", stk[tp--]);
	return 0;
}