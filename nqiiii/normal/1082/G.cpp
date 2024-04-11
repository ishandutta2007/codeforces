#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000;
const ll inf = 1e18;
int n, m, mpn[maxn + 10], mpe[maxn + 10], ndcnt = 2;
ll ans;

namespace flow {
	typedef ll type;
	struct edge {
		int to;
		type cap, flow;
		int nxt;
	}eg[2 * maxn * maxn + 10];
	int h[maxn * 10 + 10], d[maxn * 10 + 10], cur[maxn * 10 + 10];
	int n, egcnt, s, t;

	void init(int nn, int ss, int tt) {
		n = nn; s = ss; t = tt; egcnt = 1;
		for (int i = 1; i <= n; ++i) h[i] = 0;
	}

	void aadd(int &h, int to, type cap) {
		eg[++egcnt] = (edge){to, cap, 0, h};
		h = egcnt;
	}

	void addeg(int l, int r, type cap) {
		aadd(h[l], r, cap);
		aadd(h[r], l, 0);
	}

	bool bfs() {
		static queue<int> q;
		for (int i = 1; i <= n; ++i) d[i] = i == s ? 0 : -1;
		q.push(s);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			for (int i = h[p]; i; i = eg[i].nxt)
				if (eg[i].cap > eg[i].flow && d[eg[i].to] == -1) {
					d[eg[i].to] = d[p] + 1;
					q.push(eg[i].to);
				}
		}
		return d[t] != -1;
	}

	type dfs(int p, type a) {
		if (p == t) return a;
		type ans = 0, now;
		for (int &i = cur[p]; i; i = eg[i].nxt)
			if (eg[i].cap > eg[i].flow && d[p] + 1 == d[eg[i].to]) {
				now = dfs(eg[i].to, min(a, eg[i].cap - eg[i].flow));
				eg[i].flow += now; eg[i ^ 1].flow -= now;
				ans += now; a -= now;
				if (!a) break;
			}
		return ans;
	}

	type main() {
		type ans = 0;
		while (bfs()) {
			for (int i = 1; i <= n; ++i) cur[i] = h[i];
			ans += dfs(s, inf);
		}
		return ans;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) mpn[i] = ++ndcnt;
	for (int i = 1; i <= m; ++i) mpe[i] = ++ndcnt;
	flow::init(ndcnt, 1, 2);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		flow::addeg(1, mpn[i], x);
	}
	for (int i = 1; i <= m; ++i) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);
		flow::addeg(mpn[l], mpe[i], inf);
		flow::addeg(mpn[r], mpe[i], inf);
		flow::addeg(mpe[i], 2, w); ans += w;
	}
	printf("%lld", ans - flow::main());
}