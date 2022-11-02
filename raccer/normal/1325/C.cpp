#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> lea;
vector <pii> from[100010];
int ans[100010];

void dfs(int x, int last) {
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, id = from[x][i].se;
		if (v == last) continue;
		dfs(v, x);
		if (from[v].size() == 1) lea.push_back(id);
	}
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(mp(y, i));
		from[y].push_back(mp(x, i));
	}
	dfs(1, 1);
	if (from[1].size() == 1) lea.push_back(from[1][0].se);
	if (lea.size() == 2) {
		for (int i = 1; i < n; i++) {
			printf("%d\n", i - 1);
		}
		return 0;
	}
	memset(ans, -1, sizeof(ans));
	ans[lea[0]] = 0, ans[lea[1]] = 1, ans[lea[2]] = 2;
	int NOW = 3;
	for (int i = 1; i < n; i++) {
		if (ans[i] == -1) ans[i] = NOW++;
	}
	for (int i = 1; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}