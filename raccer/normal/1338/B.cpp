#include <bits/stdc++.h>
using namespace std;

vector <int> from[100010];

int dfs(int x, int last) {
	int res = 0;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		int tmp = dfs(v, x);
		tmp = ((tmp & 1) << 1) | (tmp >> 1 & 1);
		res |= tmp;
	}
	if (from[x].size() == 1) res |= 1;
	return res;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	int rt = -1;
	for (int i = 1; i <= n; i++) {
		if (from[i].size() > 1) {
			rt = i;
			break;
		}
	}
	int tmp = dfs(rt, rt);
	if (tmp == 3) printf("3 ");
	else printf("1 ");
	int ans = n - 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j];
			if (from[v].size() == 1) cnt++;
		}
		if (cnt) ans -= cnt - 1;
	}
	printf("%d\n", ans);
	return 0;
}