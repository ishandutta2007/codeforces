#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	int tests = 1;
	while (tests--) {
		Solve();
	}
	return 0;
}

typedef long long ll;
const int MN = 200005;

int n, h[MN];
std::vector<int> G[MN];

int mx[MN];
ll DFS(int u, int p) {
	mx[u] = 0;
	ll ret = 0;
	for (int v : G[u]) if (v != p) {
		ret += DFS(v, u);
		mx[u] = std::max(mx[u], mx[v]);
	}
	ret += std::max(h[u] - mx[u], 0);
	mx[u] = std::max(mx[u], h[u]);
	return ret;
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", h + i);
	F(i, 2, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int rt = (int)(std::max_element(h + 1, h + n + 1) - h);
	ll ans = 0;
	int mx1 = 0, mx2 = 0;
	for (int v : G[rt]) {
		ans += DFS(v, rt);
		if (mx[v] > mx2)
			mx2 = mx[v];
		if (mx2 > mx1)
			std::swap(mx1, mx2);
	}
	ans += 2 * h[rt] - mx1 - mx2;
	printf("%lld\n", ans);
}