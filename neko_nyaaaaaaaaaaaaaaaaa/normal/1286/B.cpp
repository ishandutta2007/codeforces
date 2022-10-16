#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p(2001), c(2001);
vector<int> adj[2001];

vector<int> dfs(int now) {
	vector<int> ans;
	for (int u: adj[now]) {
		vector<int> f = dfs(u);
		for (int i: f) ans.push_back(i); 
	}
	
	if (c[now] > ans.size()) {
		cout << "NO\n"; exit(0);
	}

	ans.insert(ans.begin() + c[now], now);
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n; int rt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		if (p[i] == 0) rt = i;
		else adj[p[i]].push_back(i);
	}
	vector<int> ans = dfs(rt);
	vector<int> pos(n+1);
	for (int i = 0; i < n; i++) {
		pos[ans[i]] = i+1;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << pos[i] << ' ';
	}

	return 0;
}