#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
typedef long long ll;

vector<int> adj[200000];
int vis[200000];
int bcnt[200000];
int chk[200000];

int cnt = 0;

void dfs(int i) {
	vis[i] = 1;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		dfs(x);
		if (chk[x]) bcnt[i]++;
	}
	if (bcnt[i] == 0) {
		chk[i] = 1;
	}
	else if (bcnt[i] == 1) {
		cnt++;
		chk[i] = 1;
	}
	else {
		cnt += 2;
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x, y;
	scanf("%d %d %d ", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (x >= y) {
		ll ans = (ll)y*(n - 2);
		int bad = 0;
		for (int i = 0; i < n; i++) {
			if (adj[i].size() == n - 1) {
				ans = ans + x;
				bad = 1;
				break;
			}
		}
		if (!bad) {
			ans = ans + y;
		}
		printf("%I64d", ans);
	}
	else {
		dfs(0);
		cnt = n - 1 - cnt;
		printf("%I64d", (ll)(n - 1 - cnt)*x + (ll)cnt*y);
	}
	return 0;
}