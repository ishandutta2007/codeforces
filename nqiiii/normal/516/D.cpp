#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int n, rt, acnt, q;
ll d[maxn + 10], a[maxn + 10], L;
int s[maxn + 10], b[maxn + 10];

struct edge {
	int to, len;
};

vector<edge> g[maxn + 10];

void getdis(int p, int fa, ll w, ll *d) { 
	d[p] = max(d[p], w);
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != fa)
			getdis(e.to, p, w + e.len, d);
	}
}

void dfs(int p, int fa) {
	a[++acnt] = d[p]; b[acnt] = p;
	int x = lower_bound(a + 1, a + acnt + 1, d[p] - L) - a - 1;
	++s[p]; --s[b[x]]; 
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != fa) {
			dfs(e.to, p);
			s[p] += s[e.to];
		}
	}
	--acnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);
		g[l].push_back((edge){r, w});
		g[r].push_back((edge){l, w});
	}
	getdis(1, 0, 0, d);
	int x = max_element(d + 1, d + n + 1) - d;
	memset(d, 0, sizeof d);
	getdis(x, 0, 0, d);
	int y = max_element(d + 1, d + n + 1) - d;
	getdis(y, 0, 0, d);
	rt = min_element(d + 1, d + n + 1) - d;
	scanf("%d", &q);
	while (q--) {
		scanf("%lld", &L);
		memset(s, 0, sizeof s);
		dfs(rt, 0);
		printf("%d\n", *max_element(s + 1, s + n + 1));
	}
}