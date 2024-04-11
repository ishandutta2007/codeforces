#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

typedef long long LL;
const int Mod = 998244353;
const int MS = 1000005;

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

std::vector<std::pair<int, int>> prime_factorization(int n) {
	std::vector<std::pair<int, int>> ret;
	for (int d = 2; d * d <= n; ++d)
		if (n % d == 0) {
			int p = d, v = 0;
			while (n % p == 0)
				n /= p, ++v;
			ret.push_back({p, v});
		}
	if (n != 1)
		ret.push_back({n, 1});
	return ret;
}

int n;
int a[MN], b[MN];

void Solve();

int main() {
	Init(1000000);
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

vector<int> v;
vector<pair<int, int>> pf;
int ans1, ans2;

void DFS(int st, int x, int phi) {
	if (st == (int)pf.size()) {
		debug("(x, phi) = (%d, %d)\n", x, phi);
		ll coef = (ll)(n / x) * ((n / x) - 1);
		int bin = Fac[n / x];
		for (int c : v)
			coef -= (ll)(b[c] / x) * (b[c] / x - 1),
			bin = (ll)bin * iFac[b[c] / x] % mod;
		int res = coef % mod * Inv[n / x] % mod * Inv[n / x - 1] % mod * bin % mod;
		debug("(res, bin) = (%d, %d)\n", res, bin);
		ans1 = (ans1 + (ll)phi % mod * res) % mod;
		ans2 = (ans2 + (ll)phi % mod * bin) % mod;
		return ;
	}
	DFS(st + 1, x, phi);
	x *= pf[st].fi;
	phi *= pf[st].fi - 1;
	DFS(st + 1, x, phi);
	F(j, 2, pf[st].se)
		x *= pf[st].fi,
		phi *= pf[st].fi,
		DFS(st + 1, x, phi);
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	if (a[1] == a[n])
		return puts("1"), void();
	F(i, 1, n) b[i] = 0;
	F(i, 1, n) ++b[a[i]];
	int g = 0;
	v.clear();
	F(i, 1, n)
		if (b[i])
			g = gcd(g, b[i]),
			v.push_back(i);
	debug("g = %d\n", g);
	pf = prime_factorization(g);
	ans1 = ans2 = 0;
	DFS(0, 1, 1);
	debug("%d, %d\n", ans1, ans2);
	ans2 = (ll)ans2 * gInv(n) % mod;
	int ans = (ll)ans1 * gInv(ans2) % mod;
	printf("%d\n", ans);
}