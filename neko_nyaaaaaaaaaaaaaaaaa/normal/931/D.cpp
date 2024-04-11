#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj(100007);
map<int, int> ct;
int lvmax = 0;
int ans = 0;

void dfs(int now, int lv) {
	ct[lv]++;
	lvmax = max(lv, lvmax);
	for (int i = 0; i < adj[now].size(); i++) {
		dfs(adj[now][i], lv+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	int n, x;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> x;
		adj[x].push_back(i);
	}
	dfs(1, 1);
	for (int i = 1; i <= lvmax; i++) {
		ans += (ct[i] % 2);
	}
	cout << ans;
	
	return 0;
}