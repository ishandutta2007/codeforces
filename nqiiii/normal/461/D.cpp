#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, mod = 1000000007;

int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int n, k;
int x[maxn + 10], y[maxn + 10], d[maxn + 10];
int v[maxn + 10];
vector<pair<int, int> > g[maxn + 10];
int val[maxn + 10];

bool dfs(int p) {
	for (int i = 0; i < (int)g[p].size(); ++i) {
		pair<int, int> e = g[p][i];
		int d = e.second ^ val[p];
		if (val[e.first] == -1) {
			val[e.first] = d;
			if (!dfs(e.first)) return 0;
		} else if (d != val[e.first]) return 0;
	}
	return 1;
}

int solve(int v) {
	for (int i = 0; i <= n; ++i) {
		g[i].clear(); val[i] = -1;
	}
	for (int i = 1; i <= k; ++i)
		if ((x[i] + y[i]) % 2 == v) {
			int l = 1, r = n;
			l = max(l, abs(x[i] - y[i]));
			r = min(r, x[i] + y[i] - 1);
			r = min(r, 2 * (n - 1) - x[i] - y[i] + 3);
			if (l % 2 == v) ++l;
			if (r % 2 == v) --r;
			if (l <= r) {
				g[max(l - 2, 0)].push_back(make_pair(r, d[i]));
				g[r].push_back(make_pair(max(l - 2, 0), d[i]));
			}
		}
	int cnt = 0;
	for (int i = 0; i <= n; ++i)
		if (!i || i % 2 != v) {
			if (val[i] == -1) {
				val[i] = 0;
				if (!dfs(i)) return 0;
				++cnt;
			}
		}
	int ans = 1;
	for (int i = 1; i < cnt; ++i) ans = add(ans, ans);
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		char s[5]; scanf("%s", s);
		d[i] = s[0] == 'o';
	}
	printf("%d", mul(solve(0), solve(1)));
}