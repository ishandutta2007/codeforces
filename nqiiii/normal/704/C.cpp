#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, mod = 1e9 + 7;
int n, m;
int f[maxn + 10][2][2][2];

struct data {
	bool tr[2][2];
};
data rev(const data &a) {
	data b;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			b.tr[i][j] = a.tr[j][i];
	return b;
}
data upd(const data &a) {
	data b;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			b.tr[i][j] = 0;
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					b.tr[i][j] ^= ((i ^ k) | (j ^ l)) & a.tr[k][l];
		}
	return b;
}

map<int, data> mp[maxn + 10];
bool a[maxn + 10][2];

bool sig(int x) {
	return x < 0;
}

struct edge {
	int to; data w;
};
vector<edge> g[maxn + 10];
int c[maxn + 10], ccnt;
data to[maxn + 10];
bool vis[maxn + 10];
int s[2], ans[2];

void dfs(int p, int lst) {
	c[++ccnt] = p; vis[p] = 1;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != lst) {
			to[ccnt] = e.w;
			if (!vis[e.to]) dfs(e.to, p);
		}
	}
}

void merge() {
	/*
	for (int i = 0; i < 2; ++i) printf("(%d) ", s[i]);
	for (int i = 0; i < 2; ++i) printf("(%d) ", ans[i]);
	printf("\n");
	*/
	static int tmp[2];
	memset(tmp, 0, sizeof tmp);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			(tmp[i ^ j] += 1ll * s[i] * ans[j] % mod) %= mod;
	for (int i = 0; i < 2; ++i) ans[i] = tmp[i];
}

void solve() {
	/*
	for (int i = 1; i <= ccnt; ++i) {
		printf("(%d:", c[i]);
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				printf(" %d", to[i].tr[j][k]);
		printf(") ");
	}
	printf("\n");
	*/
	for (int i = 1; i <= ccnt; ++i)
		memset(f[i], 0, sizeof f[i]);
	for (int i = 0; i < 2; ++i)
		f[1][i][i][a[c[1]][i]] = 1;
	for (int i = 1; i < ccnt; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					for (int p = 0; p < 2; ++p)
						(f[i + 1][j][p][l ^ a[c[i + 1]][p] ^ to[i].tr[k][p]] += f[i][j][k][l]) %= mod;
	s[0] = s[1] = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				(s[k ^ to[ccnt].tr[j][i]] += f[ccnt][i][j][k]) %= mod;
	merge();
}


int main() {
	scanf("%d%d", &m, &n);
	ans[0] = 1;
	for (int i = 1; i <= m; ++i) {
		int k, x, y; scanf("%d", &k);
		if (k == 1) {
			scanf("%d", &x);
			a[abs(x)][sig(x)] ^= 1;
		} else {
			scanf("%d%d", &x, &y);
			if (abs(x) > abs(y)) swap(x, y);
			if (abs(x) == abs(y)) {
				if (x == y) a[abs(x)][sig(x)] ^= 1;
				else swap(ans[0], ans[1]);
			} else mp[abs(x)][abs(y)].tr[sig(x)][sig(y)] ^= 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool d[2];
		d[0] = d[1] = 0;
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k) {
				d[j] ^= (j ^ k) & a[i][k];
			}
		a[i][0] = d[0]; a[i][1] = d[1];
	}
	for (int i = 1; i <= n; ++i)
		for (auto j: mp[i]) {
			g[i].push_back((edge){j.first, upd(j.second)});
			g[j.first].push_back((edge){i, upd(rev(j.second))});
		}
		/*
	for (int i = 1; i <= n; ++i) 
		for (auto j: g[i])
			if (i < j.to) {
				printf("|%d %d|\n", i, j.to);
				for (int k = 0; k < 2; ++k)
					for (int l = 0; l < 2; ++l)
						if (j.w.tr[k][l]) printf("{%d %d} ", k, l);
				printf("\n");
			}
	for (int i = 1; i <= n; ++i)
		printf("|%d %d %d|\n", i, a[i][0], a[i][1]);
	printf("\n");
			*/
	for (int i = 1; i <= n; ++i)
		if (g[i].empty()) {
			vis[i] = 1;
			memset(s, 0, sizeof s);
			++s[a[i][0]]; ++s[a[i][1]];
			merge();
		}
	for (int i = 1; i <= n; ++i)
		if (!vis[i] && g[i].size() == 1) {
			ccnt = 0;
			dfs(i, 0);
			memset(to[ccnt].tr, 0, sizeof to[ccnt].tr);
		//	puts("chain");
			solve();
		}
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			assert(g[i].size() == 2);
			ccnt = 0;
			dfs(i, g[i][0].to);
		//	puts("cycle");
			solve();
		}
	printf("%d", ans[1]);
}