#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

struct Node {int id; char c[2];};

vector <int> G[N];
vector <Node> o[N];
vector <string> S;
vector <vector<int> > P;

int n, q, fat[N], dep[N], fa[N << 1], loc[N << 1];
char s[N], ans[N];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void con(int x, int y) {if (find(x) != find(y)) fa[fa[x]] = fa[y];}

void dfs(int x, int Fa) {
	fat[x] = Fa, dep[x] = dep[Fa] + 1;
	for (int v : G[x]) if (Fa != v) dfs(v, x);
}

vector<int> Path(int u, int v) {
	vector<int> pre, suf;
	while (u != v) {
		if (dep[u] >= dep[v]) pre.push_back(u), u = fat[u];
		else suf.push_back(v), v = fat[v];
	}
	pre.push_back(u);
	while (suf.size()) pre.push_back(suf.back()), suf.pop_back();
	return pre;
}

void make(Node a, Node b) {
	if (b.c[0] != a.c[0] && b.c[1] != a.c[0] && b.c[0] != a.c[1] && b.c[1] != a.c[1])
		puts("NO"), exit(0);
	if (a.c[0] == a.c[1] && b.c[0] == b.c[1]) return;
	if (a.c[0] == a.c[1]) {
		if (b.c[0] == a.c[0]) loc[b.id * 2 - 1] = 1;
		else if (b.c[1] == a.c[0]) loc[b.id * 2] = 1;
		return;
	}
	if (b.c[0] == b.c[1]) {
		if (a.c[0] == b.c[0]) loc[a.id * 2 - 1] = 1;
		else if (a.c[1] == b.c[0]) loc[a.id * 2] = 1;
		return;
	}
	if (a.c[0] == b.c[0] && a.c[1] == b.c[1])
		return con(a.id * 2 - 1, b.id * 2 - 1), con(a.id * 2, b.id * 2);
	if (a.c[0] == b.c[1] && a.c[1] == b.c[0])
		return con(a.id * 2 - 1, b.id * 2), con(a.id * 2, b.id * 2 - 1);
	if (a.c[0] == b.c[0]) return loc[a.id * 2 - 1] = loc[b.id * 2 - 1] = 1, void();
	if (a.c[0] == b.c[1]) return loc[a.id * 2 - 1] = loc[b.id * 2] = 1, void();
	if (a.c[1] == b.c[0]) return loc[a.id * 2] = loc[b.id * 2 - 1] = 1, void();
	if (a.c[1] == b.c[1]) return loc[a.id * 2] = loc[b.id * 2] = 1, void();
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1, u, v; i <= q; i++) {
		scanf("%d%d%s", &u, &v, s); string tmp = "";
		vector<int> p = Path(u, v);
		for (int j = 0; j < p.size(); j++) {
			o[p[j]].push_back((Node){i, s[j], s[p.size() - j - 1]});
			tmp += s[j];
		}
		S.push_back(tmp), P.push_back(p);
	}
	for (int i = 1; i <= 2 * q; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < o[i].size(); j++)
			make(o[i][0], o[i][j]);
	for (int i = 1; i <= 2 * q; i++)
		if (loc[i]) loc[find(i)] = 1;
	for (int i = 1; i <= 2 * q; i++)
		if (loc[find(i)]) loc[i] = 1;
	for (int i = 1; i <= 2 * q; i += 2) {
		if (loc[i] && loc[i + 1]) puts("NO"), exit(0);
		if (find(i) == find(i + 1)) puts("NO"), exit(0);
	}
	for (int i = 1; i <= 2 * q; i += 2)
		if (!loc[find(i)] && !loc[find(i + 1)])
			loc[find(i)] = 1;
	for (int i = 1; i <= n; i++) ans[i] = 'a';
	for (int i = 0; i < q; i++) {
		if (loc[find(2 * i + 2)]) reverse(S[i].begin(), S[i].end());
		for (int j = 0; j < S[i].size(); j++)
			ans[P[i][j]] = S[i][j];
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%c", ans[i]);
	return 0 * puts("");
}