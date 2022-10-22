#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, dep[200005], clen, cnt;
bool vis[200005];
vector< pair<int, int> > v[200005];

void dfs(int x, int p, int d) {
	cnt++;
	vis[x] = 1;
	dep[x] = d;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i].second == p) continue;
		int node = v[x][i].first;
		if (vis[node]) {
			if (d >= dep[node]) clen = d - dep[node] + 1;
			continue;
		}
		dfs(node, v[x][i].second, d + 1);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].push_back(make_pair(y, i));
		v[y].push_back(make_pair(x, i));
	}
	long long ans = 1;
	for (int i = 0; i < 2 * N; i++) {
		if (vis[i]) continue;
		clen = -1;
		cnt = 0;
		dfs(i, -1, 0);
		//printf("%d %d %d\n", i, clen, cnt);
		if (clen == -1) {
			ans *= cnt;
			ans %= MOD;
		} else {
			if (clen >= 2) ans *= 2;
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);
}