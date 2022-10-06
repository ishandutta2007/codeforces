#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 200005
#define MM 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Solve();

int main() {
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}


typedef long long LL;
const int Mod = 998244353;
const int G = 3, iG = 332748118;
const int MS = 1 << 21;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((LL)b * b % Mod))
		if (e & 1) a = (int)((LL)a * b % Mod);
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MS], Fac[MS], iFac[MS];
inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (int)((LL)Fac[i - 1] * i % Mod);
	iFac[N] = gInv(Fac[N]);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (int)((LL)iFac[i] * i % Mod);
	for (int i = 1; i <= N; ++i) Inv[i] = (int)((LL)Fac[i - 1] * iFac[i] % Mod);
}
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (int)((LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod);
}


const int v = 200000;
int n, m;
int a[MN], b[MN];
int c[MM], bit[MM];
void Add(int i, int x) {
	for (; i <= v; i += i & -i)
		bit[i] += x;
}
int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[i];
	return s;
}

void Solve() {
	Init(v);
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%d", a + i), ++c[a[i]];
	F(i, 1, m) scanf("%d", b + i);
	F(i, 1, v) Add(i, c[i]);
	int ans = 0, coef = Fac[n];
	F(i, 1, v) coef = (int)((ll)coef * iFac[c[i]] % mod);
	bool gg = false;
	F(i, 1, min(n, m)) {
		coef = (int)((ll)coef * Inv[n - i + 1] % mod);
		int s = Qur(b[i] - 1);
//		printf("i = %d, coef = %d, s = %d\n", i, coef, s);
		ans = (int)((ans + (ll)coef * s) % mod);
		if (!c[b[i]]) {
			gg = true;
			break;
		}
		coef = (int)((ll)coef * c[b[i]] % mod);
		--c[b[i]], Add(b[i], -1);
	}
	if (n < m && !gg)
		ans = (ans + 1) % mod;
	printf("%d\n", ans);
}