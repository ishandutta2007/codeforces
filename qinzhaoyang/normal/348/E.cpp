#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int first[N], cur;
struct Edge {
	int nxt, to, w;
}	e[N << 1];
void con(int x, int y, int z) {
	e[++cur] = (Edge){first[x], y, z};
	first[x] = cur;
}

int n, m, f[N], Fa[N][22], dep[N], L[N], R[N], cnt;
int mx1[N], wh1[N];

int c[N];

int is_fa(int x, int y) {
	return L[x] <= L[y] && R[y] <= R[x];
}

void dfs1(int x, int fa) {
	L[x] = ++cnt;
	Fa[x][0] = fa, dep[x] = dep[fa] + 1;
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to, w = e[i].w;
		if (v == fa) continue; dfs1(v, x);
		if (wh1[v]) {
			if (mx1[v] + w > mx1[x]) {
				mx1[x] = mx1[v] + w;
				wh1[x] = wh1[v];
			}
			else if (mx1[v] + w == mx1[x])
				wh1[x] = x;
		}
	}
	if (!mx1[x] && f[x]) wh1[x] = x;
	R[x] = cnt;
}

int Lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[Fa[x][i]] >= dep[y])
			x = Fa[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--)
		if (Fa[x][i] != Fa[y][i])
			x = Fa[x][i], y = Fa[y][i];
	return Fa[x][0];
}

void get(int x, int y) {
	//cout << "Add " << x << " " << y << endl;
	if (!x || !y) return;
	int lca = Lca(x, y);
	c[x]++, c[y]++;
	c[lca]--, c[Fa[lca][0]]--;
}

void dfs2(int x, int mx, int wh) {
	//cout << "In " << x << " " << mx << " " << wh << endl;
	if (f[x]) {
		//cout << x << ": ";
		//cout << mx << " " << wh << " ";
		//cout << mx1[x] << " " << wh1[x] << endl;
		if (mx > mx1[x]) get(x, wh);
		else if (mx < mx1[x]) get(x, wh1[x]);
	}
	int max1 = 0, max2 = 0, max3 = 0;
	int w1 = 0, w2 = 0, w3 = 0;
	max1 = mx, w1 = wh;
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to, w = e[i].w; if (v == Fa[x][0]) continue;
		int tmp = mx1[v] + w;
		if (wh1[v]) {
			if (tmp > max1) {
				max3 = max2, max2 = max1;
				w3 = w2, w2 = w1;
				max1 = tmp, w1 = wh1[v];
			}
			else if (tmp > max2) {
				max3 = max2, w3 = w2;
				max2 = tmp, w2 = wh1[v];
			}
			else if (tmp > max3) {
				max3 = tmp, w3 = wh1[v];
			}
		}
	}
	int flag = 0;
	if (w1 == 0 && f[x]) flag = 1;
	else if (max1 == max2) flag = 2;
	else if (max1 == max2 && max2 == max3) flag = 3;
	/*
	cout << "Run" << " " << x << endl;
	cout << max1 << " " << max2 << " " << max3 << endl;
	cout << w1 << " " << w2 << " " << w3 << endl;
	cout << flag << endl;
	*/
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to, w = e[i].w; if (v == Fa[x][0]) continue;
		if (flag == 1) dfs2(v, w, x);
		else if (flag == 2) {
			if (is_fa(v, w1) || is_fa(v, w2)) {
				if (is_fa(v, w1)) dfs2(v, max1 + w, w2);
				else dfs2(v, max1 + w, w1);
			}
			else dfs2(v, max1 + w, x);
		}
		else if (flag == 3) dfs2(v, max1 + w, x);
		else {
			if (is_fa(v, w1)) {
				if (max2 == 0) {
					if (f[x]) dfs2(v, w, x);
					else dfs2(v, 0, 0);
				}
				else if (max2 == max3) dfs2(v, max2 + w, x);
				else dfs2(v, max2 + w, w2);
			}
			else dfs2(v, max1 + w, w1);
		}
	}
}

void dfs3(int x, int fa) {
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to; if (v == fa) continue;
		dfs3(v, x), c[x] += c[v];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x; scanf("%d", &x);
		f[x] = 1;
	}
	for (int i = 1; i < n; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		con(x, y, z), con(y, x, z);
	}
	dfs1(1, 0);
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n; i++)
			Fa[i][j] = Fa[Fa[i][j - 1]][j - 1];
	dfs2(1, 0, 0), dfs3(1, 0);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++)
		if (!f[i]) {
			if (c[i] > ans1) ans1 = c[i], ans2 = 0;
			if (ans1 == c[i]) ans2++;
		}
	printf("%d %d\n", ans1, ans2);
	return 0;
}