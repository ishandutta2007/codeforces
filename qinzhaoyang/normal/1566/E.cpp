#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int T, n, f[N], d[N], ans = 0;
vector <int> G[N];

int dfs1(int x, int fa) {
	int c = 0, c1 = 0;
	for (int i = 0; i < G[x].size(); i++) {
		int v = G[x][i];		
		if (v == fa) continue;
		if (dfs1(v, x)) c++;
		else c1++;
		f[x] += f[v];
	}
	if (c > 0) f[x]++;
	if (c == 0 && c1 > 0) f[x]--;
	return c == 0;
}

void dfs2(int x, int fa, int tmp) {
	ans = min(ans, tmp);
	for (int i = 0; i < G[x].size(); i++) {
		int v = G[x][i];
		if (v == fa) continue;
		tmp -= f[v];
	}
	for (int i = 0; i < G[x].size(); i++) {
		int v = G[x][i];
		if (v == fa) continue;
		dfs2(v, x, tmp + f[v]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i <= n; i++) f[i] = d[i] = 0;
		for (int i = 1; i < n; i++) {
			int x, y; cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
			d[x]++, d[y]++;
		}
		ans = n + 1;
		int cnt = 0;
		for (int i = 2; i <= n; i++)
			if (d[i] == 1) cnt++;
		dfs1(1, 0);
		dfs2(1, 0, cnt);
		cout << ans << endl;		
	}
	return 0;
}