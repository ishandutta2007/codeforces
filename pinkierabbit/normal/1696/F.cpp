#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <bitset>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 105
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

int n;
bitset<101> f[MN][MN];
vector<int> G[MN];
int dist[MN][MN];

void DFS(int u, int p, int o, int d) {
	dist[o][u] = d;
	for (int v : G[u]) if (v != p)
		DFS(v, u, o, d + 1);
}

void Solve() {
	vector<pii> ans;
	scanf("%d", &n);
	F(i, 1, n) G[i].clear();
	F(i, 1, n - 1)
		F(j, i + 1, n)
			F(k, 1, n) {
				int x;
				scanf("%1d", &x),
				f[j][i][k] = f[i][j][k] = x;
				// ? d(i, k) == d(j, k)
			}
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	bitset<101> A;
	A.reset();
	F(i, 1, n) A[i] = 1;
	F(num, 1, n - 2) {
		int l = 0;
		bitset<101> chain;
		for (int k : a) {
			bitset<101> B = A;
			for (int i : a)
				for (int j : a) if (i < j)
					if (f[i][j][k])
						B &= f[i][j];
			if (B.count() >= 2) {
				l = k;
				chain = B;
				break;
			}
		}
		if (!l)
			return puts("No"), void();
		vector<int> b;
		for (int i : a)
			if (chain[i])
				b.push_back(i);
		static int dis[MN], pto[MN];
		for (int i : b)
			dis[i] = -1;
		function<void(int)> calc = [&](int i) {
			if (dis[i] != -1)
				return ;
			auto &B = f[i][l];
			int p = 0;
			for (int j : b)
				if (B[j]) {
					p = j;
					break;
				}
			pto[i] = p;
			if (!p)
				dis[i] = 0;
			else
				dis[i] = 999,
				calc(p),
				dis[i] = dis[p] + 1;
		};
		for (int i : b) if (i != l) calc(i);
		int mx = -1, mxi = 0;
		for (int i : b) if (i != l)
			if (dis[i] > mx)
				mx = dis[i],
				mxi = i;
		if (mx >= n)
			return puts("No"), void();
		int c = mxi;
		for (int t = mx; t != 0; --t)
			c = pto[c];
		// c -- l
		ans.push_back({c, l});
		G[c].push_back(l);
		G[l].push_back(c);
		a.erase(find(a.begin(), a.end(), l));
		A[l] = 0;
	}
	ans.push_back({a[0], a[1]});
	G[a[0]].push_back(a[1]);
	G[a[1]].push_back(a[0]);
	F(i, 1, n) DFS(i, 0, i, 0);
	bool ok = true;
	F(i, 1, n - 1) F(j, i + 1, n) F(k, 1, n)
		if ((dist[k][i] == dist[k][j]) != f[i][j][k])
			ok = false;
	if (!ok)
		return puts("No"), void();
	puts("Yes");
	for (auto &[x, y] : ans)
		printf("%d %d\n", x, y);
}