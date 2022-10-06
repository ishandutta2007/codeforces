#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 1005
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
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, m;
int a[MN], deg[MN];
vector<int> G[MN];
ll f[MN][MN];
ll s[MN];

void Solve() {
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%d", a + i), deg[i] = 0, G[i].clear();
	F(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[y].push_back(x);
		++deg[x];
	}
	int p = min_element(deg + 1, deg + n + 1) - deg;
	debug("node = %d\n", p);
	F(i, 1, n) F(j, 0, n) f[i][j] = 0;
	f[p][0] = 1;
	queue<int> q;
	q.push(p);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : G[u]) {
			F(j, 1, n) {
				f[v][j] = f[v][j] + f[u][j - 1];
				while (f[v][j] >= 2 * mod)
					f[v][j] -= mod;
			}
			if (!--deg[v])
				q.push(v);
		}
	}
	F(i, 0, n) s[i] = 0;
	F(i, 1, n) {
		F(j, 0, n) {
			ll k = f[i][j] * a[i];
			if (k >= 2 * mod)
				k = k % mod + mod;
			s[j] = s[j] + k;
			while (s[j] >= 2 * mod)
				s[j] -= mod;
		}
	}
	int d = n;
	while (d >= 0 && !s[d]) --d;
	if (d == -1)
		return puts("0"), void();
	ll sum = 0;
	F(i, 0, d) {
		sum += s[i];
		while (sum >= 2 * mod)
			sum -= mod;
		if (sum)
			--sum;
	}
	printf("%lld\n", (d + 1 + sum) % mod);
}