#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, dis[151], ans = inf;

struct edge {
	int l, r, w;
	bool operator < (const edge &t) const {
		return w < t.w;
	}
}a[151];

struct mat {
	bitset<151> a[151];

	void init() {
		for (int i = 1; i <= n; ++i) a[i][i] = 1;
	}
}s, pw;

mat operator * (const mat &a, const mat &b) {
	mat ans;
	for (int i = 1; i <= n; ++i) {
		ans.a[i].reset();
		for (int j = 1; j <= n; ++j)
			if (a.a[i][j])
				ans.a[i] |= b.a[j];
	}
	return ans;
}

mat fpow(mat x, int y) {
	mat ans; ans.init();
	while (y) {
		if (y & 1) ans = ans * x;
		y >>= 1; x = x * x;
	}
	return ans;
}

int bfs() {
	static queue<int> q;
	memset(dis, -1, sizeof dis);
	dis[n] = 0; q.push(n);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		for (int i = 1; i <= n; ++i)
			if (pw.a[i][p] && dis[i] == -1) {
				dis[i] = dis[p] + 1; q.push(i);
			}
	}
	int ans = inf;
	for (int i = 1; i <= n; ++i)
		if (s.a[1][i] && dis[i] != -1)
			ans = min(ans, dis[i]);
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
	sort(a + 1, a + m + 1);
	s.init();
	for (int i = 1; i <= m; ++i) {
		s = s * fpow(pw, a[i].w - a[i - 1].w);
		pw.a[a[i].l][a[i].r] = 1;
		ans = min(ans, a[i].w + bfs());
	}
	if (ans < inf) printf("%d", ans);
	else printf("Impossible");
}