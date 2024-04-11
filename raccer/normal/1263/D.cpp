#include <bits/stdc++.h>
using namespace std;

char buf[1000010];
vector <int> from[300010];
int vis[300010];

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		int len = strlen(buf);
		for (int j = 0; j < len; j++) {
			from[buf[j] - 'a'].push_back(i + 26), from[i + 26].push_back(buf[j] - 'a');
		}
	}
	int ans = 0;
	for (int i = 26; i < n + 26; i++) {
		if (vis[i]) continue;
		dfs(i);
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}