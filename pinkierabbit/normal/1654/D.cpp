#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <array>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int qpow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((ll)b * b % mod))
		if (e & 1) a = (int)((ll)a * b % mod);
	return a;
}

void Init(int);
void Solve();

int main() {
	Init(200000);
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int inv[MN];
int mpf[MN];
void Init(int n) {
	for (int i = 2; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			if (!mpf[j]) mpf[j] = i;
	inv[1] = 1;
	for (int i = 2; i <= n; ++i)
		inv[i] = (int)((ll)(mod - mod / i) * inv[mod % i] % mod);
}

int n;
vector<std::array<int, 3>> G[MN];

int ans;
int dfc;
vector<pii> V[MN];
void DFS(int u, int p, int x) {
	++dfc;
	ans = (ans + x) % mod;
	for (auto e : G[u]) {
		int v = e[0];
		if (v == p) continue;
		int y = (int)((ll)x * inv[e[1]] % mod * e[2] % mod);
		int ldf = dfc + 1;
		DFS(v, u, y);
		int rdf = dfc + 1;
		int a = e[1], b = e[2];
		while (a >= 2) {
			int pr = mpf[a];
			V[pr].push_back({ldf, 1});
			V[pr].push_back({rdf, -1});
			a /= pr;
		}
		while (b >= 2) {
			int pr = mpf[b];
			V[pr].push_back({ldf, -1});
			V[pr].push_back({rdf, 1});
			b /= pr;
		}
	}
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) G[i].clear(), V[i].clear();
	F(i, 1, n - 1) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		G[x].push_back({y, a, b});
		G[y].push_back({x, b, a});
	}
	ans = 0;
	dfc = 0;
	DFS(1, 0, 1);
	F(i, 1, n) if (!V[i].empty()) {
		V[i].push_back({0, 0});
		sort(V[i].begin(), V[i].end());
		int s = V[i].size(), sum = 0, mx = 0;
		for (int j = 1; j < s; ++j) {
			if (V[i][j].fi != V[i][j - 1].fi)
				mx = max(mx, sum);
			sum += V[i][j].se;
		}
		if (mx > 0)
			ans = (ll)ans * qpow(i, mx) % mod;
	}
	printf("%d\n", ans);
}