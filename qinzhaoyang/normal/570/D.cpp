#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define pii pair <int,int>
#define mp make_pair

using namespace std;

const int N = 500010;

int n, m, Ans[N], Ch[N], dep[N], fa[N];
char s[N];
vector <int> G[N];
vector <pii > Q[N];
int siz[N], son[N], L[N], R[N], dfn[N], cur = 0;

void Add(int x) {
	Ch[dep[x]] ^= (1 << (s[x] - 'a'));
}

void Mdf(int x) {
	for (int i = L[x]; i <= R[x]; i++) Add(dfn[i]);
}

void dfs(int x) {
	int M = 0; siz[x] = 1; dep[x] = dep[fa[x]] + 1;
	dfn[++cur] = x, L[x] = cur;
	for (int i : G[x]) {
		dfs(i), siz[x] += siz[i];
		if (M < siz[i]) M = siz[i], son[x] = i;
	}
	R[x] = cur;
}

void Solve(int x) {
	for (int i : G[x]) if (i != son[x])
		Solve(i), Mdf(i);
	if (son[x]) Solve(son[x]);
	for (int i : G[x]) if (i != son[x])
		Mdf(i);
	Add(x);
	for (pii i : Q[x]) {
		int d = i.first, k = Ch[d]; 
		Ans[i.second] = (k == (k & (-k)));
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2, x; i <= n; i++)
		scanf("%d", &fa[i]), G[fa[i]].push_back(i);
	dfs(1), scanf("%s", s + 1);
	for (int i = 1, x, d; i <= m; i++)
		scanf("%d%d", &x, &d), Q[x].pb(mp(d, i));
	Solve(1);
	for (int i = 1; i <= m; i++) {
		if (Ans[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}